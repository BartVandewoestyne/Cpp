/**
 * References:
 *
 *   [jossutis1999] The C++ Standard Library, A Tutorial and Reference, Jossutis, 1999, page 180-183.
 */

#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string,float> coll;

    // ...

    if (coll.insert(std::make_pair("otto", 22.3)).second)
    {
        std::cout << "OK, could insert otto/22.3" << std::endl;
    }
    else
    {
        std::cout << "Oops, could not insert otto/22.3 "
                  << "(key otto already exists)" << std::endl;
    }

    // remove all elements with the passed key
    std::string key("otto");
    coll.erase(key);

    // Note that if the index does not exist yet, new element will be created.
    coll["otto"] = 7.7;
}
