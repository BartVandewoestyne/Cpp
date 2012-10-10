class FileSystem { };            // this class is in your
                                 // library

FileSystem theFileSystem;            // this is the object
                                     // with which library
                                     // clients interact

class Directory {                    // created by library client
public:
  Directory();
};

Directory::Directory()
{
  // create a Directory object by invoking member
  // functions on theFileSystem;
}

Directory tempDir;                  // directory for temporary
                                    // files
