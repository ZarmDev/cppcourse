#include <iostream>
using namespace std;

struct Vector3 {
  float x;
  float y;
  float z;
};

int main(){
  Vector3 SomeVector{1.0, 2.0, 3.0};
  auto [a, b, c]{SomeVector}; 

  cout << "a = " << a
    << ", b = " << b
    << ", c = " << c;
}
