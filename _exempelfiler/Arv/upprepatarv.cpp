/*
#include <string>

using namespace std;

class Named
{ 
};

class Teacher : virtual public named
{
    string kurs;

public:
    Teacher(string n, string k) : Named(n), kurs(k) {}
};

class Student : virtual public Named
{
    bool godkänd;

public:
    Student(string n, bool g) : Named(n), godkänd(g) {}
};

class Handledare : public Teacher, public Student
{

public:
    Handledare(string n, string k, bool g) : Named(n), Teacher(n, k), Student(n, g) {}
};
*/