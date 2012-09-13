#ifndef ENEMY_TARGET_H
#define ENEMY_TARGET_H

#include <cstddef>

class EnemyTarget {
public:
  EnemyTarget() { ++numTargets; }
  EnemyTarget(const EnemyTarget&) { ++numTargets; }

  virtual
  ~EnemyTarget() { --numTargets; }
 
  static size_t numberOfTargets()
  { return numTargets; }
 
  virtual bool destroy();                 // returns success of
                                          // attempt to destroy
                                          // EnemyTarget object
 
private:
  static size_t numTargets;               // object counter
};
 
// class statics must be defined outside the class;
// initialization is to 0 by default
size_t EnemyTarget::numTargets;

#endif /* ENEMY_TARGET_H */
