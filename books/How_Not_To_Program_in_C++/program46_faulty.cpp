/************************************************
 * list -- Test out the command list decoder.   *
 *                                              *
 * Read a command from the input and check to   *
 * see if the command decoder can find it.      *
 ************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>

static inline void do_open() {
   std::cout << "do_open called\n";
}
static inline void do_close() {
   std::cout << "do_close called\n";
}
static inline void do_save() {
   std::cout << "do_save called\n";
}
static inline void do_quit() {
    exit(0);
}
/*
 * The command as a string and
 * as a function to execute
 */
struct cmd_info {
    char *const cmd;
    void (*funct)();
};

/*
 * List of all possible commands
 */
static cmd_info cmd_list[] = {
    {"open", do_open},
    {"close", do_close},
    {"save", do_save},
    {"quit", do_quit},
    {NULL, NULL}
};

/************************************************
 * do_cmd -- Decode a command an execute it.    *
 *    If the command is not found, output an    *
 *    error.                                    *
 ************************************************/
static void do_cmd(
    const char *const cmd
) {
    struct cmd_info *cur_cmd;

    cur_cmd = cmd_list;

    while (
        (std::strcmp(cur_cmd->cmd, cmd) != 0) &&
        cur_cmd->cmd != NULL)
    {
        cur_cmd++;
    }
    if (cur_cmd == NULL) {
        std::cout << "Command not found\n";
    } else {
        cur_cmd->funct();
    }
}

/************************************************
 * main -- Simple test program.                 *
 ************************************************/
int main()
{
    char cmd[100];
    while (1) {
        std::cout << "Cmd: ";
        std::cin.getline(cmd, sizeof(cmd));

        do_cmd(cmd);
    }
}
