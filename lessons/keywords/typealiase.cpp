using integer = int;

int main() {
  integer MyNumber{42};
}

/*Alternative of above*/
typedef int integer;

int main() {
  integer MyNumber;
}

/* USE CASES */
#pragma once
#include <cstdint>

#ifdef PLATFORM_64BIT
  using integer = std::int64_t;
#else
  using integer = std::int32_t;
#endif

/*using keyword to make things more readable*/
using Items = std::unordered_map<
  Enums::ItemType, std::vector<Item&>>;

class Character {
public:
  void SetInventory(Items Inventory) {
    mInventory = Inventory;
  }
  Items GetInventory() { return mInventory; }
private:
  Items mInventory;
};