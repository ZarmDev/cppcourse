// Prefix
int MyNumber { 5 };
MyNumber++; //at this line MyNumber is 5

// Postfix
int MyNumber { 5 };
++MyNumber; //at this line MyNumber is 6

/* Overloading them */
struct Vector3 {
  float x;
  float y;
  float z;

  // Prefix operator
  Vector3& operator++(){
    ++x;
    ++y;
    ++z;
    return *this;
  }

  // Postfix operator
  Vector3 operator++(int){
    Vector3 temp{*this};
    ++(*this);
    return temp;
  }
};