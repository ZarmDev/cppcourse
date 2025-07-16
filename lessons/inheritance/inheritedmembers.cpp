#include <iostream>
using namespace std;

class Monster {
public:
  Monster(int Health) : mHealth{Health}{
    cout << "Constructing Monster with an int";
  }

  int GetHealth(){ return mHealth; }

private:
  int mHealth{100};
};

class Goblin : public Monster {
public:
  Goblin() : Monster{150}{
    cout << "\nDefault Constructing Goblin";
  }
};

int main(){
  Goblin Bonker;
  cout << "\nHealth: " << Bonker.GetHealth();
}
