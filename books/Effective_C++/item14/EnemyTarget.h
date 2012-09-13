#ifndef ENEMY_TARGET_H
#define ENEMY_TARGET_H

#include <cstddef>
#include <iostream>
using namespace std;

class EnemyTarget {
public:

  EnemyTarget() {
    cout << "EnemyTarget()" << endl;
    ++numTargets;
  }

  EnemyTarget(const EnemyTarget&) {
    cout << "EnemyTarget(const EnemyTarget&)" << endl;
    ++numTargets;
  }

  // When you try to delete a derived class object through a base class pointer
  // and the base class has a nonvirtual destructor, the results are undefined.
  //
  // To avoid this problem, you have only to make the EnemyTarget destructor
  // virtual. Declaring the destructor virtual ensures well-defined behavior
  // that does precisely what you want: both EnemyTank's and EnemyTarget's
  // destructors will be called before the memory holding the object is
  // deallocated.
  virtual
  ~EnemyTarget() {
    cout << "~EnemyTarget()" << endl;
    --numTargets;
  }
 
  static size_t numberOfTargets() {
    return numTargets;
  }
 
  //virtual bool destroy();                 // returns success of
                                          // attempt to destroy
                                          // EnemyTarget object
 
private:
  static size_t numTargets;               // object counter
};
 
#endif /* ENEMY_TARGET_H */
