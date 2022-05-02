#include<iostream>
#include<string>
#include<vector>
#include<boost/type_index.hpp>
#include<array>
#include "util.h"

void f(NoCopyMove)
{
}

NoCopyMove bar()
{
    return NoCopyMove();
}

/*
NoCopyMove baz()
{
    NoCopyMove res;
    return res; // error: non temporary requires copy/move available
}
*/
int main()
{
    { // int
        int i1; // undefined
        int i2 = 42;
        int i3(42);
        int i4 = int(); // inits with 0
        int i5{42};
        int i6 = {42};
        int i7{};
        int i8 = {};
        auto i9 = 42;
        auto i10{42}; // defect in c++11: std::initializer_list<int>
                      // c++14: int
                     
        std::cout << boost::typeindex::type_id<decltype(i10)>().pretty_name() << "\n";  // fixed even in c++11 mode
        auto i11 = {42}; // initializer_list<int>
        std::cout << boost::typeindex::type_id<decltype(i11)>().pretty_name() << "\n";
        auto i12 = int{42};
        // int i13(); // function
        //std::cout << boost::typeindex::type_id<decltype(i13)>().pretty_name() << "\n";
    }
    {
        auto i = 42;
        auto v = 42l;
        std::cout << boost::typeindex::type_id<decltype(v)>().pretty_name() << "\n";
        auto a = 42ll;
        std::cout << boost::typeindex::type_id<decltype(a)>().pretty_name() << "\n";
        using namespace std::literals;
        auto s = "sasha"s;
        std::cout << boost::typeindex::type_id<decltype(s)>().pretty_name() << "\n";
        auto r = std::array{1, 4, 2, 3}; // c++17 is ok: mandatory RVO and copy elision
    }
    {
        NoCopyMove a;
        //f(a); // error, use of deleted function ‘NoCopyMove::NoCopyMove(const NoCopyMove&)
        //f(NoCopyMove()); // c++17 - ok, c++14 - error, no move
        auto b = bar(); //  c++17 - ok, c++14 - error
        // auto c = baz(); // error - named value return
        extfoo(NoCopyMove());
        auto d = extbar();
    }
    {
        auto show = [](const auto& cont) { 
            for(const auto& e: cont) {
                std::cout << e << " ";
            }; 
            std::cout << "\n"; 
        };
        std::vector<std::string> a1 = {"hello", "world"};
        show(a1);
        std::vector<std::string> a2 = {{"hello", "world"}};
        show(a2);
        std::vector<std::string> a3 = {{{"hello", "world"}}};
        show(a3);
    }
}