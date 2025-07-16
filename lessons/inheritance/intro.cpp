class Player {
  public: void Move(){}; void Talk(){};
};
class Dude : Player {
  public:  
  void Move(){};
  void Attack(){};
  void DropLoot(){};
  void Enrage(){};
};
// Example of preventing inheritance
class Demon final {};
// What if you want to pass a variable to classes through inheritance?
// Use the "protected" keyword
class Character {
public:
  int GetHealth(){ return mHealth; }

protected:
  int mHealth{100};
};

class Healer : public Character {
public:
  void Heal(int Amount){ mHealth += Amount; }
};

