class FileSystem { };                // same as before
 

FileSystem& theFileSystem()          // this function replaces
{                                    // the theFileSystem object
 
  static FileSystem tfs;             // define and initialize
                                     // a local static object
                                     // (tfs = "the file system")
 
  return tfs;                        // return a reference to it
}

 
class Directory {
public:
  Directory();
};


Directory::Directory()
{
  // same as before, except references to theFileSystem are
  // replaced by references to theFileSystem();
}
 
Directory& tempDir()                 // this function replaces
{                                    // the tempDir object
 
  static Directory td;               // define/initialize local
                                     // static object
 
  return td;                         // return reference to it
}
