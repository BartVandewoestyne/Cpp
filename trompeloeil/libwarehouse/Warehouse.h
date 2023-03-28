#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class Warehouse
{
public:
  virtual bool hasInventory(const std::string& name, size_t amount) const = 0;
  virtual void remove(const std::string& name, size_t amount) = 0;
};

#endif  // WAREHOUSE_H
