/*EXAMPLE*/
namespace Geometry {
  float Add(float x, float y) {
    return x + y;
  }

  float Pi { 3.14 };
}

int main() {
  Geometry::Add(10, Geometry::Pi);
}

/*NESTED NAMESPACES*/

namespace Geometry {
  float Add(float x, float y) {
    return x + y;
  }
  namespace Constants {
    float Pi { 3.14f };
  }
}

Geometry::Add(10, Geometry::Constants::Pi)

/*ANOYMOUS NAMESPACE*/

// main.cpp
#include <iostream>
using namespace std;

namespace {
  float Pi{3.14};
}

// Geometry.cpp
float GetPi();

int main() {
  cout << "Pi in main.cpp: " << Pi
    << "\nPi in Geometry.cpp: " << GetPi();
}

/*USING NAMESPACE. It will search that namespace if identifier is not found*/
#include <iostream>

void Hello() {
  // This using statement's effects are
  // limited to just this function block
  using namespace std;
  cout << "Hello ";
}

void World() {
  // Error - there are no using
  // statements in effect in this scope
  cout << "World";  
}

int main() {
  Hello();
  World();
}