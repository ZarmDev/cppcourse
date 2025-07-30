#include <iostream>

struct Player {
  Player() = default;
  Player(const Player& Original) {
    std::cout << "Copying Player by Constructor\n";
  }

  Player& operator=(const Player& Original) {
    std::cout << "Copying Player by Assignment\n";
    return *this;
  }
};

struct Party {
  Player PlayerOne;
  // Other Players
  // ...
};

int main() {
  Party PartyOne;
  Party PartyTwo{PartyOne};
  PartyOne = PartyTwo;
}

/* Prevent copying a constructor/class/struct */
struct Player {
  Player() = default;
  Player(const Player&) = delete;
  Player& operator=(const Player&) = delete;
};