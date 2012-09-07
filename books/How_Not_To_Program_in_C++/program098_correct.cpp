/**
 * Answer:
 *
 * Try compiling with both these commands:
 *
 *   Command 1: g++ -g program98_correct.cpp 
 *
 *   Command 2: g++ -g -O1 program98_correct.cpp
 *
 * With command 1, the debugging trick works.  With command 2, it doesn't
 * because the compiler optimizes the whole program to an empty program and the
 * debugging variable is optimized out and does no longer exist in the optimized
 * version.
 *
 * Using the volatile keyword, we can prevent that the debugging variable gets
 * optimized out.
 */

/***********************************************
 * Code fragment to demonstrate how to use the *
 * debugger to turn on debugging.  All you     *
 * have to do is put a breakpoint on the "if"  *
 * line and change the debugging variable.     *
 ***********************************************/
void dump_variables(void) {
}

void do_work()
{
    //static int debugging = 0;
    static volatile int debugging = 0;

    if (debugging)
    {
        dump_variables();
    }
    // Do real work
}

int main()
{
  do_work();
}
