/*#include <string>
#include <iostream>

using namespace std;

class Person
{
    string namn;

public:
    Person(string s) : namn(s){}
    
        string get_namn() const { return namn; }
        void talar() const { cout << "Bla bla..." << endl; }
    
};

class Varg
{
    bool grym;

public:
    Varg(bool g) : grym(g) {}
    bool is_grym() const { return grym; }
    void ylar() const { cout << "Uuuuuuu.." << endl; }
};

class Varulv : public Person, public Varg
{
    bool dodlig;

public:
    Varulv(string namn, bool dodl) : Person(namn), Varg(true), dodlig(dodl) {}
    bool is_dodlig() const { return dodlig; }
};

void samtal(Person *p1, Person *p2){
    p1->talar();
    p2->talar();
}

void fullmåne(Varg *v){
    v->ylar();
}

int main(){

Varulv *vu = new Varulv("Jozef", true);
vu->talar();
vu->ylar();
Person *p = vu;
p->talar();
Varg *v = vu;
v->ylar();
Person *pers = new Person("Stefan");
samtal(pers, vu);
fullmåne(vu);

}
*/