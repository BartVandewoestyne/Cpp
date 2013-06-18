/**
 * TODO:
 *   Complete and check this exercise.
 */

#include <string>

using std::string;

int main()
{
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;

    // (a)
    pv = (void*)ps;
    // TODO

    // (b)
    i = int(*pc);
    //i = static_cast<int>(*pc);

    // (c)
    pv = &d;
    // TODO

    // (d)
    //pc = (char*) pv;
    pc = static_cast<char*>(pv);
}
