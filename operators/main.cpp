#include<iostream>
#include "op_test.h"

MyInt f(MyInt n)
{
    return n + MyInt(1);
}

int main()
{
    MyInt a(3), b(5);

    MyInt c = a + b;
    MyInt d = a - b;
    MyInt e = -a;
    MyInt g = +e;

    std::cout << "g = " << g.data() << "\n";
    std::cout << "c = " << c.data() << ", d = " << d.data() << ", e = " << e.data() << "\n"; 
    std::cout << "f(" << c.data() << ") = " << f(c).data() << "\n"; 

    {
        MyInt a(1), b(1);
        MyInt c = ++a;
        MyInt d = b++;

        std::cout << "a = " << a.data() << ", ++a = " << c.data() << ", b++ = " << d.data() << ", b = " << b.data() << "\n";
    }
}
