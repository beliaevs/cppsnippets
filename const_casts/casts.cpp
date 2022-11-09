#include<iostream>

const int N = 42;

void mutate(const int& c_n)
{
    int& n = const_cast<int&>(c_n);
    std::cout << "inside function initial: " << n << "\n";
    ++n;
    std::cout << "inside function final: " << n << "\n";
}

int main()
{
    {
        int n = 42;
        std::cout << "Before: " << n << "\n";
        mutate(n);
        std::cout << "After: " << n << "\n";
     }
     {
        std::cout << "Before: " << N << "\n";
        mutate(N);
        std::cout << "After: " << N << "\n";
     }
    return 0;
}