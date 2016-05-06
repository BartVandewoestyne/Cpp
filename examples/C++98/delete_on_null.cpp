/*
 * This sample tries to answer the question whether it is necessary to check
 * for NULL before deleting a pointer.
 *
 * Current answer:
 *
 *   The check is not necessary, because per 5.3.5/2 in ISO/IEC 14882,
 *   deleting a NULL pointer is a no-op.
 *
 * References:
 *
 *   [1] ISO/IEC 14882
 *   [2] http://stackoverflow.com/questions/615355/is-there-any-reason-to-check-for-a-null-pointer-before-deleting
 *   [3] http://stackoverflow.com/questions/13818803/check-for-null-before-delete-in-c-good-practice
 *   [4] http://stackoverflow.com/questions/8004495/deleting-a-null-pointer
 *   [5] http://stackoverflow.com/questions/4804258/c-checking-for-null-on-delete
 *
 */

#include <cstddef>

class Widget {};

int main()
{
    Widget* pw1 = new Widget;
    delete pw1;                 // typical case, works
    //delete pw1;               // error, cannot delete again!

    Widget* pw2 = NULL;
    delete pw2;                 // no-op (see 5.3.5/2 in [1])

    Widget* pw3 = new Widget;
    if (pw3 != NULL)            // a lot of legacy code often checks
    {                           // for NULL before deleting...
        delete pw3;             // QUESTION: is this check necessary???
    } 
}
