/************************************************
 * scan_dir -- Scan directories for magic files *
 *      and report the results.                 *
 *                                              *
 * Test on the directories "first" and "second".*
 ************************************************/
#include <iostream>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
const long int MAGIC = 0x464c457f; // Linux executable magic #
/************************************************
 * next_file -- find a list of files with magic *
 *      numbers that match the given number.    *
 *                                              *
 * Returns the name of the file or              *
 *      NULL if no more files.                  *
 ************************************************/
char *next_file(
    DIR  *dir           // Directory to scan
) {
    // Current entry in the dir
    struct dirent *cur_ent;

    while (1) {

        cur_ent = readdir(dir);
        if (cur_ent == NULL)
            return (NULL);

        int fd = open(cur_ent->d_name, O_RDONLY);
        if (fd < 0) {
            // Can't get the file so try again
            continue;
        }

        int magic;      // The file's magic number

        // Size of the header read
        int read_size =
            read(fd, &magic, sizeof(magic));

        if (read_size != sizeof(magic)) {
            close(fd);
            continue;
        }

        if (magic == MAGIC) {
            close(fd);
            return (cur_ent->d_name);
        }
        close(fd);
    }
}
/************************************************
 * scan_dir -- Scan a directory for the files   *
 *      we want.                                *
 ************************************************/
char *scan_dir(
    const char dir_name[] // Directory name to use
) {
    // Directory to scan
    DIR *dir_info = opendir(dir_name);
    if (dir_info == NULL)
        return (NULL);

    chdir(dir_name);

    // Name of the file we just found
    char *name = next_file(dir_info);
    closedir(dir_info);

    chdir("..");        // Undo the original chdir

    return (name);
}

int main() {
    // Find a file in the directory "first"
    char *first_ptr = scan_dir("first");

    // Find a file in the directory "second"
    char *second_ptr = scan_dir("second");

    // Print the information about the dir first
    if (first_ptr == NULL) {
        std::cout << "First: NULL ";
    } else {
        std::cout << "First: " << first_ptr << " ";
    }
    std::cout << '\n';

    // Print the information about the dir second
    if (second_ptr == NULL) {
        std::cout << "Second: NULL ";
    } else {
        std::cout << "Second: " << second_ptr << "  ";
    }
    std::cout << '\n';
    return (0);
}
