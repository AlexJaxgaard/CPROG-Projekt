/*
class Stack
{

public:   //"Interface": endast rent virtuella medlemsfunktioner, ingen konstruktor, virtuell destruktor.
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual bool is_empty() = 0;
    ~virtual Stack() {}
};

#include <vector>

class Vector_stack : public Stack, private std::vector<int>
{
public:
    void push(int value)
    {
        push_back(value);
    }

    int pop()
    {
        int val = back();
        pop_back();
        return val;
    }

    bool is_empty() const { return empty(); }
};
*/