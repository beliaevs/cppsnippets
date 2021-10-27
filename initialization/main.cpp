#include<iostream>
#include<vector>

//initialization test
class A 
{
    public:
    explicit A(int a, double b): d_n(a), d_d(b) { std::cout << "A::A(int, double)\n"; }
    private:
    int d_n;
    double d_d;
};

class B 
{
    public:
    B(int a, double b): d_n(a), d_d(b) { std::cout << "B::B(int, double)\n"; }
    private:
    int d_n;
    double d_d;
};

int main()
{
    A a1(2, 4.3);
    // A a2 = {3, 4.5}; does not compile

    B b1(4, 2.12);
    B b2 = {5, 7.3};

    std::vector<int> vec1(3); // size - 3
    std::vector<int> vec2{3}; // one-element
    std::cout << "vec1: \n";
    for(auto n: vec1)
        std::cout << n << " ";
    std::cout << "\nvec2: \n";
    for(auto n: vec2)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}