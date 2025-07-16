#include <iostream>
using namespace std;

class Monster {
 public:
 //  implicitly define this as the default constructor, but not neccessary for functionality
  Monster() = default;
  Monster(int x, int y) {
    std::cout << "Two integers\n";
  }
  Monster(int x, int y, int z) {
    std::cout << "Three integers\n";
  }
};

class Goblin : public Monster {
public:
  // You must use the using keyword to inherit constructors
  using Monster::Monster;
  
  // overloading constructors leads to this being used instead of the parent constructor
  Goblin(int x, int y, int z) {
    std::cout << "I'll handle this one\n";
  }
};

int main() {
  // Use Monster constructor
  Goblin Bonker{1, 2};

  // Use Goblin constructor
  Goblin Basher{1, 2, 3};
}

//----------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Monster {
public:
	// this is asking for a int value, health and then setting that to the mHealth variable.
  Monster(int Health) : mHealth{Health}{
    cout << "Constructing Monster with an int";
  }

  int GetHealth(){ return mHealth; }

private:
  int mHealth{100};
};

class Goblin : public Monster {
public:
// This is like super(150) in Java, just setting a value to the super constructor
  Goblin() : Monster{150}{
    cout << "\nDefault Constructing Goblin";
  }
};

int main(){
  Goblin Bonker;
  cout << "\nHealth: " << Bonker.GetHealth();
}