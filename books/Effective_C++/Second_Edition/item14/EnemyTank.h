#ifndef ENEMY_TANK_H
#define ENEMY_TANK_H

#include <cstddef>
#include <iostream>
#include "EnemyTarget.h"
using namespace std;

class EnemyTank: public EnemyTarget {
public:
  EnemyTank() {
    cout << "EnemyTank()" << endl;
    ++numTanks;
  }
 
  EnemyTank(const EnemyTank& rhs)
  : EnemyTarget(rhs)
  {
    cout << "EnemyTank(const EnemyTank& rhs)" << endl;
    ++numTanks;
  }
 
  ~EnemyTank() {
    cout << "~EnemyTank()" << endl;
    --numTanks;
  }
 
  static size_t numberOfTanks() {
    return numTanks;
  }
 
  //virtual bool destroy();
 
private:
  static size_t numTanks;         // object counter for tanks
};

#endif /* ENEMY_TANK_H */
