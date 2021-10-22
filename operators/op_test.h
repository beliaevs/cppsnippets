#pragma once

class MyInt
{
    public:
    MyInt() {}
    explicit MyInt(int n): d_n(n) {}
    
    friend MyInt operator+(MyInt a, MyInt b);
    friend MyInt operator-(MyInt a, MyInt b);
    
    MyInt operator-() const
    {
        return MyInt(-d_n);
    }

    MyInt operator+() const
    {
        return *this;
    }

    MyInt& operator++()
    {
        ++d_n;
        return *this;
    }

    MyInt operator++(int)
    {
        MyInt res = *this;
        ++*this;
        return res;
    }

    int data() const 
    {
        return d_n;
    }

    private:
    int d_n = 0;
};

inline MyInt operator+(MyInt a, MyInt b)
{
    return MyInt(a.d_n + b.d_n);
}

inline MyInt operator-(MyInt a, MyInt b)
{
    return MyInt(a.d_n - b.d_n);
}