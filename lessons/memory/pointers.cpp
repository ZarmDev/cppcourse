#include <iostream>

using namespace std;

// Why use pointers? Because you can just set a variable to the address rather than the variable and only dereference if you actually need the value. (performance)

// Creating pointers
int x { 1 };
int* MyPointer { &x };

// Dereferencing
int main(){
  int original{42};
  int* x{&original};
  cout << *x;
}

// Reference
void Increment(int& Number){
  Number++;
}

int main(){
  int x{1};
  Increment(x);
}
// And here it is using a pointer: (💀)

void Increment(int* Number){
  (*Number)++;
}

int main(){
  int x{1};
  Increment(&x);
}