/*
 * Illustrates how weak ptrs can help in breaking cyclic dependencies (which have
 * as a problem that memory is not released.
 *
 * References:
 *     [1] http://www.acodersjourney.com/2016/05/top-10-dumb-mistakes-avoid-c-11-smart-pointers/ (Mistake #8)
 */

#include <iostream>
#include <memory>
#include <string>

class Aircraft {
public:
    Aircraft(const std::string& name)
        : m_model(name)
    {
        std::cout << "Aircraft type " << m_model << " is created." << std::endl;
    }

    ~Aircraft()
    {
        std::cout << "Aircraft type " << m_model << " is destroyed." << std::endl;
    }

public:
    //std::shared_ptr<Aircraft> myWingMan;  // pMaverick and pIceman will *not* be destroyed.
    std::weak_ptr<Aircraft> myWingMan;  // pMaverick and pIceman *will* be destroyed.

private:
    std::string m_model;
};

int main()
{
    auto pMaverick = std::make_shared<Aircraft>("Maverick: F-14");
    auto pIceman = std::make_shared<Aircraft>("Iceman: F-14");

    pMaverick->myWingMan = pIceman; // So far so good - no cycles yet
    pIceman->myWingMan = pMaverick; // now we got a cycle - neither maverick
                                    // nor goose will ever be destroyed

    return 0;
}
