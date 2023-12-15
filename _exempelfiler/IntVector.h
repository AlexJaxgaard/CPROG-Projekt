// Labb2, IntVector.h – klassdefinition
#include <initializer_list>
#include <ostream>
class IntVector
{

public:
    IntVector();

    IntVector(std::initializer_list<int> list);
    int size() const;
    void push_back(int value);

    friend std::ostream &operator<<(std::ostream &os, const IntVector &vec);

    int operator[](int index) const;
    int &operator[](int index);

    IntVector &operator=(IntVector &other);

private:
    int sizeOfArray;
    int arrayCapacity;
    int *arrayElements;
    void sortArray();
};