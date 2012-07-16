/************************************************
 * print_privs -- Print some of the privilege   *
 * flags.                                       *
 ************************************************/
#include <iostream>

#define CI const int
CI P_USER   = (1 << 0);  // Normal user privileges
CI P_REBOOT = (1 << 1);  // Can reboot systems
CI P_KILL   = (1 << 2);  // Can kill any process
CI P_TAPE   = (1 << 3);  // Can use tape devices
CI P_RAW    = (1 << 4);  // Can do raw io
CI P_DRIVER = (1 << 5);  // Can load drivers
CI P_ADMIN  = (1 << 6);  // Can do administration
CI P_BACKUP = (1 << 7);  // Can do backups

int main()
{
    // The privileges
    unsigned char privs = 0;

    // Set some privs
    privs |= P_ADMIN;
    privs |= P_BACKUP;

    std::cout << "Privileges: ";

    if ((privs & P_ADMIN) != 0)
        std::cout << "Administration ";

    if ((privs & P_BACKUP) != 0)
        std::cout << "Backup ";

    std::cout << std::endl;
    return (0);
}
