#include<iostream>

#include "spy.h"

class NoSpecialFunctions
{
    Spy d_spy{"NoSpecialFunctions"};   
};

class DefaultCopy
{
    public:
    DefaultCopy() = default; // defaulted copy suppresses default constructor, need to add
    DefaultCopy(const DefaultCopy&) = default; // it also suppresses move constructor and move assignment
    private:
    Spy d_spy{"DefaultCopy"};   
};

class DefaultMove
{
    public:
    DefaultMove() = default;
    DefaultMove(const DefaultMove&) = default;
    DefaultMove(DefaultMove&&) = default; // it suppresses all others: default, copy, move assignment
    DefaultMove& operator=(const DefaultMove&) = default;
    private:
    Spy d_spy{"DefaultMove"};
};

class DefaultDestructor
{
    public:
    ~DefaultDestructor() = default; // it spoils all move operations
    private:
    Spy d_spy{"DefaultDestructor"};
};

template<typename T>
void checkSpecialFunctions()
{
    T a;
    T b = a;
    T c = std::move(a);
    a = b; 
    c = std::move(a);
}

int main()
{
    {
        // move and copy do all expected things
       checkSpecialFunctions<NoSpecialFunctions>();
    }
    {
        checkSpecialFunctions<DefaultCopy>();
    }
    {
        checkSpecialFunctions<DefaultMove>();
    }
    {
        checkSpecialFunctions<DefaultDestructor>();
    }
    return 0;
}