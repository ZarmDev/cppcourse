// There are many times of operators:
/*
int Number{5};

-Number; // Return -5
Number - Number; // Return 0
LeftOperand + RightOperand;
SomeNumber++;
SomeNumber--;
*/

// We can put the prototypes/functions in the Struct
struct Vector3 {
  float x;
  float y;
  float z;
  Vector3 operator+ (const Vector3& Other);
};

// We can also do the EXACT same thing but outside of the struct
// Although, if we that, we need to also add a constructor in the original struct:
Vector3 Vector3::operator+ (const Vector3& Other) {
  return Vector3 {
    x + Other.x,
    y + Other.y,
    z + Other.z
  };
}
