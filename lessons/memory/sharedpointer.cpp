/* The standard library provides another smart pointer for this scenario: std::shared_ptr.
Whilst a std::unique_ptr automatically releases the resource it's managing once its 
unique owner is destroyed, a std::shared_ptr will release its object only 
when all of its shared owners are deleted.*/

#include <iostream>
#include <memory>

struct Quest {};

struct Player {
  Player()
  : CurrentQuest{std::make_shared<Quest>()} {}

  std::shared_ptr<Quest> CurrentQuest;
};

int main() {
  Player One;
  std::cout << "Quest Owner Count: "
    << One.CurrentQuest.use_count();

  // Create a copy
  Player Two{One};
  
  if (One.CurrentQuest == Two.CurrentQuest) {
    std::cout << "\nPlayers have same quest";
  }
  std::cout << "\nQuest Owner Count: "
    << One.CurrentQuest.use_count();
}

/*Output:
	
*/