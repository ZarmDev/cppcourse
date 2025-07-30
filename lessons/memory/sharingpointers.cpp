#include <iostream>

struct Sword{};
struct Player {
  Player(Sword* Weapon) : Weapon{Weapon} {};
  Sword* Weapon{nullptr};
};

int main() {
  Sword IronSword;
  Player PlayerOne{&IronSword};
  Player PlayerTwo{PlayerOne};

  if (PlayerOne.Weapon == PlayerTwo.Weapon) {
    std::cout << "Players sharing same weapon";
  }
}