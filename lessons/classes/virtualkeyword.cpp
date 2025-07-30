/*using virtual is the only way to be able to use override in children classes*/
class Character {
public:
  virtual void Act(Character* Target){
    cout << "Character Acting\n";
  }

  bool GetIsAlive(){ return isAlive; }

protected:
  bool isAlive{true};
};

/*So now you can use overide...*/
class Goblin : public Character {
public:
  void Act(Character* Target) override {
    cout << "Goblin Acting!\n";
  }
};
/*
YOU DO NOT need to use virtual or override if you already put it in the header file

Using these specifiers outside of a class definition will result in a compilation error.
*/

// Character.h
#pragma once

class Character : public Actor {
public:
  virtual void FunctionA();

private:
  void FunctionB() override;
};
// Character.cpp
#include "Character.h"

// No specifiers are used in the definition
void Character::FunctionA() {}

void Character::FunctionB() {}