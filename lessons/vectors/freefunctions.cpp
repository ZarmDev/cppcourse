struct Vector3
{
    float x;
    float y;
    float z;
    Vector3 operator+(Vector3 Other);
};

void operator+(Vector3 a, Vector3 b);

// Similar to prototype in Javascript (overriding default addition operator)
// It's Vector3& because we want to pass the reference instead of copying the value
// It's like handing the memory address directly to this function
Vector3 operator+(Vector3 &a, Vector3 &b)
{
    return Vector3{
        a.x + b.x,
        a.y + b.y,
        a.z + b.z};
}

// int * Vector3 - override the default * operator
Vector3 operator*(int num, Vector3 vec)
{
    return Vector3{
        vec.x * num, vec.y * num, vec.z * num};
}

// Vector3 * int
Vector3 operator*(Vector3 vec, int num)
{
    // We can just use the other "prototype" (object?) instead of writing everything again
    return num * vec;
}