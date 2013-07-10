#include <vector>
#include <iostream>

class CNumber
{

private:

    int m_Number;

public:

    CNumber() : m_Number(0) {}

    int GetNumber() const
    {
        return m_Number;
    }

    void SetNumber(int Number)
    {
        m_Number = Number;
    }

    void Copy(CNumber& Number)
    {
        m_Number = Number.m_Number;
        Number.m_Number = -1;
    }

};


int main()
{
    CNumber Num1, Num2;
    Num1.SetNumber(5);
    std::cout << "Num1 (before copy): " << Num1.GetNumber() << std::endl;
    std::cout << "Num2 (before copy): " << Num2.GetNumber() << std::endl;
    Num2.Copy(Num1);
    std::cout << "Num1 (after copy): " << Num1.GetNumber() << std::endl;
    std::cout << "Num2 (after copy): " << Num2.GetNumber() << std::endl;
    return 0;
}
