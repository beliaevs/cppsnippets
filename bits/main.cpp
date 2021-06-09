#include<iostream>
#include<limits>

void output_bytes(unsigned n)
{
    for(int i = 0; i < 4; ++i)
    {
        std::cout << ((n >> 8*i) & 0xff) << ":";
    }
    std::cout << "\n";
}

void output_bytes2(unsigned n)
{
    auto pn = reinterpret_cast<unsigned char*>(&n);
    for(int i = 0; i < 4; ++i)
        std::cout << (int)(pn[i]) << ":";

    std::cout << "\n";
} 

int average1(int a, int b)
{
    return (a+b)/2;
}

int average2(int a, int b)
{
    return (a > b) ? b + (a-b)/2 : a + (b - a)/2;
}

int main()
{
    { //endianness
        std::cout << "unsigned: " << sizeof(unsigned) << "\n";

        for(auto a: {123u, 345u, 1203u, 1000000u})
        {
            output_bytes(a);
            output_bytes2(a);
        }
    }
    { //shift and division for signed
        int a = -3;
        int b = a >> 1;
        int c = a/2;

        std::cout << a << "/2 = ?\n" << "shift: " << b << ", division: " << c << "\n";
    }
    { //which integers are their own negation?
        std::cout << "what integers are their own negation?\n";
        for(int i = std::numeric_limits<int>::min(); i != std::numeric_limits<int>::max(); ++i)
        {
            if( i == -i)
                std::cout << i << " == -" << i << "\n";
        } 
    }
    { //big shift
        unsigned long a = 19287367815523; 
        for(unsigned i = 0; i <= 8*sizeof(long); ++i)
        {
            std::cout << (a >> i) << "\n";
        }
    }
    { //average overflow
        const int a = std::numeric_limits<int>::max() - 2;
        const int b = std::numeric_limits<int>::max() - 4;
        std::cout << "average of " << a << " and " << b << " is:\n";
        std::cout << average1(a, b) << " or " << average2(a, b) << "\n";
    }
}