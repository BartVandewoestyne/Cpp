/***********************************************
 * Code fragment to demonstrate how to use the *
 * debugger to turn on debugging.  All you     *
 * have to do is put a breakpoint on the "if"  *
 * line and change the debugging variable.     *
 ***********************************************/
extern void dump_variables(void);

void do_work()
{
    static int debugging = 0;

    if (debugging)
    {
        dump_variables();
    }
    // Do real work
}
