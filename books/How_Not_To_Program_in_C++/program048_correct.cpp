/************************************************
 * scan -- Scan a directory tree for files that *
 *      begin with a magic number.              *
 ************************************************/
#include <iostream>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

// Linux executable magic #
const long int MAGIC = 0x464c457f;

/************************************************
 * next_file -- find a list of files with       *
 *      magic numbers that match the given      *
 *      number.                                 *
 *                                              *
 * Returns the name of the file or              *
 *      NULL if no more files.                  *
 ************************************************/
char *next_file(
    DIR  *dir   // Directory we are scanning
)
{
    // The current directory entry
    struct dirent *cur_ent;

    while (1) {
        cur_ent = readdir(dir);
        if (cur_ent == NULL)
            return (NULL);

        // Open the fd for the input file
        int fd = open(cur_ent->d_name, O_RDONLY);
        if (fd < 0)
            continue;   // Can't get the file
                        // so try again

        int magic;      // The file's magic number

        // Size of the latest read
        int read_size =
            read(fd, &magic, sizeof(magic));

        if (read_size != sizeof(magic))
            close(fd);
            continue;

        if (magic == MAGIC)
        {
            close(fd);
            return (cur_ent->d_name);
        }
        close(fd);
    }
}

/************************************************
 * scan_dir -- Scan a directory for the         *
 *      files we want.                          *
 ************************************************/
void scan_dir(
    const char dir_name[] // Directory name to use
)
{
    // The directory we are reading
    DIR *dir_info = opendir(dir_name);
    if (dir_info == NULL)
        return;

    chdir(dir_name);

    while (1) {
        char *name = next_file(dir_info);
        if (name == NULL)
            break;
        std::cout << "Found: " << name << '\n';
    }
    closedir(dir_info);
}

int main()
{
    scan_dir(".");
    return (0);
}
