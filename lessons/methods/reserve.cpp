#include <iostream>
#include <vector>

int main() {
  std::vector MyVector{1, 2, 3, 4, 5};
  MyVector.reserve(100);

  std::cout << "Capacity: " << MyVector.size()
    << "/" << MyVector.capacity();
}