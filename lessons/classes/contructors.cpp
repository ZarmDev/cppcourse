// Instead of:
class Character {
public:
  Character() {
    mHealth = 100;
    mLevel = 5;
  }

private:
  int mHealth;
  int mLevel;
};
// You can also use:
class Character {
public:
  Character() : mHealth{ 150 }, mLevel{ 5 } {
    // Body here
  }

private:
  int mHealth;
};
// Or with parameters:
class Character {
public:
  Character(int Health, int Level) :
    mHealth{Health},
    mLevel{Level}
  {
    // Body here
  }

private:
  int mHealth;
  int mLevel;
};
