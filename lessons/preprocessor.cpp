/*Usually use the preprocessor for version or build system or operating system*/

#define VERSION         \
void Greet(){                \
  cout << "Hello There\n";   \
};

#include <iostream>
using namespace std;

int main(){
  cout << VERSION;
	
  Greet();

  MyType MyObject;
  MyObject.Greet();
}