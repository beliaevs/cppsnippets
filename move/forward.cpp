#include<iostream>
#include<ranges>
#include<vector>

void f(int&)
{
    std::cout << "f(&)\n";
}

void f(int&&)
{
    std::cout << "f(&&)\n";
}

void f(const int&)
{
    std::cout << "f(const&)\n";
}

template<typename T>
void call_f(T&& a)
{
    f(std::forward<T>(a));
}

int main()
{
    {
        const int a = 1;
        int b = 2;
        call_f(a); // f(const&)
        call_f(b); // f(&)
        call_f(42); // f(&&)
        call_f(std::move(b)); // f(&&)
    }
    {
        auto print = [](auto&& cont) { // const auto does not compile with filter
            std::cout << "[";
            for(auto&& e: cont) {
                std::cout << e << " ";
            }
            std::cout << "]\n";
        };
        std::vector v{1, 5, 2, 8, 3, 9, 4, 0};
        std::cout << "v:\n";
        print(v);
        std::cout << "drop(3):\n";
        print(v | std::views::drop(3));
        std::cout << "filter > 2:\n";
        print(v | std::views::filter([](auto&& e){ return e > 2;}));
    }
    return 0;
}