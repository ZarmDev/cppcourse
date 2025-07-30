struct SomeType {
  SomeType Pointer(){ return this; }
  SomeType& Reference(){ return this; }
  SomeType  Copy(){ return this; }
};

/*Use Case 1: Identifying the Caller*/
#include <iostream>
using namespace std;

class Character {
public:
  Character(string Name) : mName{Name}{}

  void Attack(Character& Target){
    Target.TakeDamage(*this); 
  }

  void TakeDamage(Character& Attacker){
    cout << Attacker.mName
      << " has attacked me!";
  }

  string mName;
};

int main(){
  Character Player{"Player One"};
  Character Monster{"Goblin"};

  Player.Attack(Monster);
}

/*Use Case 2: Chaining Function Calls*/
#include <iostream>
using namespace std;

class Character {
public:
  Character& SetName(string Name){
    mName = Name;
    return *this;
  }

  Character& SetLevel(int Level){
    mLevel = Level;
    return *this;
  }

  Character& Log(){
    cout << "I am a " << mName
      << " and I am level " << mLevel;
    return *this;
  }

private:
  string mName;
  int mLevel;
};

int main(){
  Character Enemy;

  Enemy
    .SetName("Goblin Warrior")
    .SetLevel(10)
    .Log();
}

