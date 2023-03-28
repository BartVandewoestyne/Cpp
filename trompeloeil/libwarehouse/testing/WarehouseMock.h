#ifndef WAREHOUSE_MOCK
#define WAREHOUSE_MOCK

#include "Warehouse.h"

class WarehouseMock : public Warehouse
{
public:
  MAKE_CONST_MOCK2(hasInventory, bool(const std::string&, size_t));
  MAKE_MOCK2(remove, void(const std::string&, size_t));
};

#endif  // WAREHOUSE_MOCK
