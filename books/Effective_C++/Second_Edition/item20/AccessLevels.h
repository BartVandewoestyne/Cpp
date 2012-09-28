#ifndef ACCESSLEVELS_H
#define ACCESSLEVELS_H

class AccessLevels {

public:
  int getReadOnly() const { return readOnly; }
 
  void setReadWrite(int value) { readWrite = value; }

  int getReadWrite() const { return readWrite; }
 
  void setWriteOnly(int value) { writeOnly = value; }

private:
  int noAccess;                    // no access to this int
 
  int readOnly;                    // read-only access to this int
 
  int readWrite;                   // read-write access to this int
 
  int writeOnly;                   // write-only access to this int
};

#endif /* ACCESSLEVELS_H */
