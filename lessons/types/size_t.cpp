/* size_t is the maximum array size. This is good practice */

#include <iostream>
#include <vector>

int main() {
  std::vector MyVector{1, 2, 3};

  for (size_t i{0}; i < MyVector.size(); ++i) {
    std::cout << MyVector[i] << ", ";
  }
}