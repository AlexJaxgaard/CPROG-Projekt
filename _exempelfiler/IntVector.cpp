// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

#include "IntVector.h"
#include <initializer_list>
#include <ostream>

int sizeOfArray;
int arrayCapacity;
int *arrayElements;

IntVector::IntVector()
    : sizeOfArray{0}, arrayCapacity{5}, arrayElements{nullptr}
{
    arrayElements = new int[arrayCapacity];
}

IntVector::IntVector(std::initializer_list<int> list)
{
    sizeOfArray = list.size();
    arrayCapacity = list.size();
    arrayElements = new int[list.size()];

    int i = 0;

    for (int j : list)
    {
        arrayElements[i] = j;
        i++;
    }
}

void IntVector::push_back(int value)
{
    if (sizeOfArray == arrayCapacity)
    {
        arrayCapacity *= 2;

        int *tempArray = new int[arrayCapacity];
        for (int i = 0; i < sizeOfArray; i++)
        {
            tempArray[i] = arrayElements[i];
        }
        delete[] arrayElements;
        arrayElements = tempArray;
    }
    arrayElements[sizeOfArray] = value;
    ++sizeOfArray;
}

int IntVector::size() const
{
    return sizeOfArray;
}

std::ostream &operator<<(std::ostream &os, const IntVector &vec)
{
    for (int i = 0; i < vec.sizeOfArray; i++)
    {
        os << vec.arrayElements[i] << " ";
    }
    return os;
}

int &IntVector::operator[](int index)
{
    return arrayElements[index];
}

int IntVector::operator[](int index) const
{
    return arrayElements[index];
}

IntVector &IntVector::operator=(IntVector &other)
{

    if (this == &other)
    {
        return *this;
    }

    if (this->size() != other.size())
    {
        int *temp = new int[other.size()];
        delete[] arrayElements;
        arrayElements = temp;
        sizeOfArray = other.size();
        arrayCapacity = other.size();
    }
    for (int i = 0; i < other.size(); i++)
    {
        arrayElements[i] = other[i];
    }

    return *this;
}



