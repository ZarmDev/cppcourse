#include <iostream>
#include <vector>

int main() {
  std::vector MyVector{1, 2, 3};

  for (int Number : MyVector) {
    std::cout << Number << ", ";
  }
}

#include <iostream>
#include <vector>

int main() {
  std::vector MyVector{1, 2, 3};

  for (int& Number : MyVector) {
    std::cout << Number << ", ";
  }
}

#include <iostream>
#include <vector>

int main() {
  std::vector MyVector{1, 2, 3};

  for (const int& Number : MyVector) {
    std::cout << Number << ", ";
  }
}