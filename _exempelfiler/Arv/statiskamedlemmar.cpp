#include <string>
#include <iostream>

using namespace std;

class Counted
{

public:
    Counted(string s) : data(s) { count++; }
    Counted(const Counted &other) : data(other.data)
    {
        count++;
    }
    ~Counted() { count--; }
    string get_data() const { return data; }
    static int get_count();

private:
    static int count; // endast deklaration
    string data;      //"instansvariabel"
};

int Counted::count = 0; // definition med initiering
int Counted::get_count()
{                 // Definition av medlemsfunktionen,
    return count; // ordet static upprepas inte
}

void funk(){
    Counted c1("Jozef"), c2("Stefan");

    cout << Counted::get_count() << endl;
}
