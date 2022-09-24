#include <cassert>
#include <cstdio>
#include <iostream>

int main()
{
    char lineBuf[200] = "5 1.0|2.0|3.0|4.0 5.0|6.0|7.0|8.0|9.0|10.0";
    int chanRead = 0;
    double vr[10] = {0.0};

    std::fill_n(vr, 10, 1.0/3);

    // Old method.
    const int nbArgumentsAssignedOld = sscanf(
        lineBuf,
        "%d%lf|%lf|%lf|%lf %lf|%lf|%lf|%lf|%lf|%lf",
        &chanRead, vr, vr+1, vr+2, vr+3, vr+4, vr+5, vr+6, vr+7, vr+8, vr+9);
    assert(nbArgumentsAssignedOld == 11);

    // Secure method
    const int nbArgumentsAssignedNew = sscanf_s(
        lineBuf,
        "%d%lf|%lf|%lf|%lf %lf|%lf|%lf|%lf|%lf|%lf",
        &chanRead, vr, vr+1, vr+2, vr+3, vr+4, vr+5, vr+6, vr+7, vr+8, vr+9);
    assert(nbArgumentsAssignedNew == 11);

    std::cout << "chanRead = " << chanRead << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "vr[" << i << "] = " << vr[i] << std::endl;
    }
}
