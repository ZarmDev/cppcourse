// CharacterTypes.h
#pragma once

struct Image {
  int Width;
  int Height;
  // ...
};

#include <iostream>

class Character {
public:
  virtual void Render() {}
  // WE need this in order for the delete to work. Otherwise the Monster's deconstructor will not be called
  // This is because Monster is deleted as a pointer and it looks for the "non-virtual" constructor. Here we specify the deconstructor for the virtual part
  //virtual ~Character() = default; 
};

class Monster : public Character {
public:
  Monster()
  : Art{new Image{256, 256}} {
    std::cout << "Creating Monster\n"; 
  }

  ~Monster() {
    std::cout << "Deleting Monster\n"; 
    delete Art;                        
  }

  Image* Art{nullptr};
};