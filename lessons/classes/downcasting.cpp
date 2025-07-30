#include <iostream>
using namespace std;

class Character {
public:
  Character(string Name) : mName{Name}{}
  string GetName(){ return mName; }

private:
  string mName;
};

class Goblin : public Character {
public:
  Goblin(string Name) : Character{Name}{}

  void Enrage(){
    cout << "Getting Angry!";
    Damage += 5;
  }

private:
  int Damage{10};
};

void Act(Character* Enemy){
  cout << Enemy->GetName() << " Acting\n";
  static_cast<Goblin*>(Enemy)->Enrage();
}

int main(){
  Goblin Bonker{"Bonker"};
  Act(&Bonker);
}