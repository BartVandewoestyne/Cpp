/************************************************
 * full_test -- Test the full_name function     *
 ************************************************/
#define PATH "/usr/tmp"

/************************************************
 * full_name -- Given the name of a file,       *
 *      return a full path name.                *
 *                                              *
 * Returns: Absolute path to the file name.     *
 ************************************************/
char *full_name(
    const char name[]   /* Base file name */
)
{
    /* Full file name */
    static char file_name[100];

    strcpy(file_name, PATH);
    strcat(file_name, '/');
    strcat(file_name, name);
    return (file_name);
}

int main()
{
    /* Test the full_name funtion */
    printf("Full name is %s\n",
            full_name("data"));
    return (0);
}
