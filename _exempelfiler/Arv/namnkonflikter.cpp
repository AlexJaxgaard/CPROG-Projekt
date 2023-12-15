/*
#include <string>
#include <iostream>
using namespace std;

class Person
{
    string x;

public:
    Person(string n) : x(n) {}
    string get() { return x; }
    void put(string n) { x = n; }
};

class Varg
{

    int x;

public:
    Varg(int n) : x(n) {}
    int get() { return x; }
    void put(int n) { x = n; }
    void zero() { x = 0; }
};

class Varulv : public Person, public Varg
{
public:
Varulv(std::string n1, int n2) : Person(n1), Varg(n2){}
void show(){
    std::cout << Person::get() << " " << Varg::get();
}

void put(string s){Person::put(s);}
void put(int i){Varg::put(i);}

};

int main()
{
    Varulv vu("Stefan", 137);
    vu.zero();
    vu.Person::put("Ulla");
    vu.Varg::put(37);
    vu.show();
}

/*

Observera alltså att här är det fråga om namn, inte signatur (skulle vara alltför
osäkert annars).Konflikten uppstår även om namnet är privat i en av
basklasserna.

*/
