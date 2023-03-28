#include <catch2/catch_all.hpp>
#include <catch2/trompeloeil.hpp>

#include "Order.h"
#include "WarehouseMock.h"

TEST_CASE("filling_removes_inventory_if_in_stock")
{
  Order order("Talisker", 50);

  WarehouseMock warehouse;
  {
    REQUIRE_CALL(warehouse, hasInventory("Talisker", 50))
      .RETURN(true);

    REQUIRE_CALL(warehouse, remove("Talisker", 50));

    order.fill(warehouse);
  }

  REQUIRE(order.is_filled() == true);
}
