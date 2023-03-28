#ifndef ORDER_H
#define ORDER_H

#include "Warehouse.h"

#include <string>

class Order
{
public:
  Order(const std::string& name, size_t amount) {}
  
  void fill(Warehouse& w)
  {
    if (w.hasInventory("Talisker", 50))
    {
      w.remove("Talisker", 50);
    }
  }

  bool is_filled() const
  {
    return true;
  }
};

#endif  // ORDER_H
