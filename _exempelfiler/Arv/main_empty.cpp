/*
#include <string>
#include <iostream>
using namespace std;
class Animal
{

public:
    std::string get_name() const { return name; }
    virtual void moves() const { cout << "Springer"; }
    virtual void talks() const = 0;
    virtual ~Animal() {} // Måste ha en implementering
protected:
    Animal(std::string n) : name(n) {}

private:
    std::string name;
    // Förbjud kopiering och tilldelning
    // Detta behövs endast i rotklassen eftersom att även fast t.ex bird inte ärver konstruktorer så kommer
    // kopiering inte att tillåtas på grund av att nedanstående ändå följer med i initiering.
    Animal(const Animal &) = delete;
    const Animal &operator=(const Animal &other) = delete;
};

class Bird : public Animal
{

public:
    // statiska metoder måste deklareras utan definition. Detta görs utanför medlemsklassen.
    static Bird *getInstance(string n, double ws);
    // Motsvarar superanropet i Java
    double get_wingspan() const { return wingspan; }
    void moves() const { cout << "Flyger"; }
    void talks() const { cout << "Kvitter kvitter"; }

private:
    // class bird extends animal^^
    double wingspan;
    Bird(std::string name, double ws) : Animal(name), wingspan(ws) {}
};

class Mask : public Animal
{
public:
    using Animal::Animal;
    // Vill ärva samma konstruktorer som i animal^^
    void moves() const { cout << "kryper"; }
};

class Cat : public Animal
{

public:
    static Cat *getInstance(string n);
    void talks() const { cout << "Mjau, mjau"; }

private:
    double wingspan;
    Cat(std::string n) : Animal(n) {}
};

int main()
{
}

// Ser till att objekten skapas på heapen, tack vare att konstruktorn är privat.
Bird *Bird::getInstance(string n, double ws)
{
    return new Bird(n, ws);
}

Cat *Cat::getInstance(string name)
{
    return new Cat(name);
}
*/