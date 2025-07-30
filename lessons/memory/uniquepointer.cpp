/* Creating unique pointers */
#include <memory>

int main() {
  std::unique_ptr<int> Pointer {
    std::make_unique<int>(42)
  };
  // Or
  /*
  auto Pointer{std::make_unique<int>(42)};
  */
}

/* Passing unique pointers */
#include <memory>

void SomeFunction(int* Num) {
  // ...
}

int main() {
  auto Ptr{std::make_unique<int>(42)};
  SomeFunction(Ptr.get());
}

/* Transferring ownership (rust 💀) */

#include <memory>
#include <utility>
#include <iostream>

void TakeOwnership(std::unique_ptr<int> Num) {
  std::cout << "TakeOwnership function now "
    "owns the pointer.\n";
  std::cout << "Value: " << *Num << '\n';
}

int main() {
  auto Number{std::make_unique<int>(42)};
  std::cout << "main function owns the pointer.\n";

  TakeOwnership(std::move(Number)); 

  // Number is now in a "moved-from" state
  if (Number == nullptr) {
    std::cout << "Number no longer owns any object.";
  }
}

/* Accepting unique pointers */
class Monster {
 public:
  Monster() : Art{GetArt()} {}
  
  // ...

  std::unique_ptr<Image> Art;
};


/* Giving a unique pointer a new address */ 
Image* GetArt() {
  return new Image{256, 256};
}

class Monster {
 public:
  // ...
  void UpdateArt(Image* NewArt) {
    Art.reset(NewArt);
  } 
  // ...
  std::unique_ptr<Image> Art;
};

int main() {
  Monster A;
  A.UpdateArt(GetArt());
}

/* Giving up ownership */
void HandleArt(Image* Art) {
  // ...
  delete Art;
}

class Monster {
 public:
  // ...
  ~Monster() {
    HandleArt(Art.release());
  }

  std::unique_ptr<Image> Art;
};

/* DO NOT DO THIS */
int main() {
  // Stack allocated memory
  Image Art;

  // A stack allocated memory address managed
  // by a smart pointer is undefined behavior
  std::unique_ptr<Image> Ptr{&Art}; 
}
