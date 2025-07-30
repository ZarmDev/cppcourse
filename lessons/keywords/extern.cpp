// Say you have this:
// Geometry.cpp
float Pi { 3.1415 };

// IN main.cpp, you can declare Pi again without having an error when including Geometry.cpp by using extern
#include <iostream>
using namespace std;

extern float Pi;

int main() {
  cout << "Pi as defined in some other file: "
    << Pi;
}