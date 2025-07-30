#include <iostream>

struct Image {
  int Width;
  int Height;
};

class Monster {
public:
  Monster() : Art{new Image(256, 256)} {}
  
  /*
  One solution: (It will create a monster using another monsters' art width and length)
  Monster(const Monster& Other)
  : Art{new Image{
      Other.Art->Width, Other.Art->Height
    }} {}
    
  Another solution: (copy in place - modify the pointer and update it)
  Monster& operator=(const Monster& Other) {
   if (&Other == this) return *this;
   *Art = *Other.Art;
   return *this;
  }
  
  Final solution: (replace)
  Monster& operator=(const Monster& Other) {
	  if (&Other == this) return *this;
	  delete Art;
	  Art = new Image(*Other.Art);
	  return *this;
  }


  */

  ~Monster() {
    delete Art;
  }

  Image* Art;
};

void Render(Monster EnemyCopy) {
  // ...
}

int main() {
  // This is fine. Points to a new Monster class
  Monster* Enemy{new Monster()};
  
  // The issue is that Render accepts a COPY and not a reference so it "shallow copies" Enemy
  // Because of this, the pointer is copied but the actual two pointers point to the same memory address
  // When Render() finishes running the memory management sees that it can delete the *Enemy
  Render(*Enemy);
  
  // But since both Enemy objects point to the same pointer, when the first object deletes Art both pointers are null

  std::cout << "Art Width: "
    << Enemy->Art->Width;
}

/*
The Rule of Three
The problem we encountered in the previous section is so ubiquituous that a convention exists to deal with it: the rule of three. It relates to the following three functions of a class:

The destructor
The copy constructor
The copy assignment operator
The rule states that if we need to provide an implementation for any of these functions, we'd typically need to implement all of them.
*/

/* The better solution to the class above is this: (using smart pointers) */
// Remember that we use make_unique because the unique pointer holds only one value and is auto destroyed whne out of scope
class Monster {
 public:
  Monster()
  : Art{std::make_unique<Image>(256, 256)} {}

  Monster(const Monster& Other)
  : Art{std::make_unique<Image>(*Other.Art)} {}

  Monster& operator=(const Monster& Other) {
    if (&Other == this) return *this;
    *Art = *Other.Art;
    return *this;
  }

  std::unique_ptr<Image> Art;
};