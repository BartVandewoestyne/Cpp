#ifndef ENEMY_TANK_H
#define ENEMY_TANK_H

#include <cstddef>
#include "EnemyTarget.h"

class EnemyTank: public EnemyTarget {
public:
  EnemyTank() { ++numTanks; }
 
  EnemyTank(const EnemyTank& rhs)
  : EnemyTarget(rhs)
  { ++numTanks; }
 
  ~EnemyTank() { --numTanks; }
 
  static size_t numberOfTanks()
  { return numTanks; }
 
  virtual bool destroy();
 
private:
  static size_t numTanks;         // object counter for tanks
};

#endif /* ENEMY_TANK_H */
