// To use dynamic casting, our type must be polymorphic. A polymorphic type is a type with at least one virtual function.
/*Bare minimum for using dynamic casting*/ 
class Character {
public:
  virtual ~Character() = default;
};


// Dynamic casting (actually checks if type can be casted)
void Handle(Character* Object){
  Goblin* GoblinPointer{
    dynamic_cast<Goblin*>(Object)
  };
  
  if (GoblinPointer) {
    cout << "That was a Goblin\n";
  } else {
    cout << "That was not a Goblin\n";
  }
};