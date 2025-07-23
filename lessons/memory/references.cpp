/*
How references are created in memory
*/
#include <iostream>
using namespace std;

class Character {
public:
  string Name;
};

Character& GetPlayer(){
	// Since the reference of the Character, Anna is passed, the variable is not copied and the garbage collector automatically deletes it
  Character Player{"Anna"};
  return Player;
}

int main(){
	// That's why this will put gibberish or crash (15:10: warning: reference to stack memory associated with local variable 'Player' returned [-Wreturn-stack-address] )
  cout << "Name: " << GetPlayer().Name;
}