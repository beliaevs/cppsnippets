#include<boost/signals2.hpp>
#include<iostream>

int main()
{
    boost::signals2::signal<void()> sig;

    auto hello = []() { std::cout << "hello ";};
    auto world = []() { std::cout << "world\n";};

    sig.connect(hello);
    sig.connect(world);

    sig();
}