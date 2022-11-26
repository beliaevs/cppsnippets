#include<algorithm>
#include<iostream>
#include<fstream>
#include<functional>
#include<memory>
#include<string>
#include<variant>
#include<vector>

template<typename T>
constexpr auto c_cast = [](auto x) { return (T)x; };

template<typename... Ts>
struct Overload: Ts...
{
    using Ts::operator()...;
};

// template deduction guide is not needed in c++20
template<class... Ts> Overload(Ts...) -> Overload<Ts...>;

class Spy
{
public:
    explicit Spy(int n): d_n(n)
    {
        std::cout << "Spy(" << d_n << ")\n";
    }

    ~Spy()
    { 
        std::cout << "~Spy(" << d_n << ")\n";
    }

    Spy(const Spy&) = delete;
    Spy& operator = (const Spy&) = delete;
    void show() const
    {
        std::cout << "Spy(" << d_n << ").show()\n";
    }
private:
    int d_n;
};

int main()
{
    {
        std::cout << "Lambda to function pointer conversion\n";
        auto f = [](int n){ std::cout << "f(" << n << ")\n"; };
        f(101);
        // strange conversion from lambda to function pointer
        auto *g = +[](int n){ std::cout << "g(" << n << ")\n"; };
        g(42);
    }
    
    {
        std::cout << "immediate lambda invocation\n";
        //immediate lambda invocation
        const std::string name = [](){ std::string in; std::ifstream("data.txt") >> in; return in; }();
        std::cout << name << "\n";
        std::invoke([](){ std::cout << "std::invoke!\n"; });
    }
    {
        std::cout << "modification of captured variables\n";
        // modification of captured variables
        int n = 21;
        auto f = [&n](){ ++n; };
        f();
        auto g = [n]() mutable { ++n; std::cout << n << "\n"; };
        for(int i = 0; i < 5; ++i)
            g();
        std::cout << n << "\n";
    }
    {
        std::cout << "captures\n";
        // what do we need to capture?
        // static - no
        static int n = 42;
        auto f = [](){ std::cout << n << "\n"; };
        f();
        // constexpr - no
        constexpr int m = 56;
        auto g = [](){ std::cout << m << "\n"; };
        g();
        // simply const - yes
        int p = 500;
        const int k = p;
        //auto h = [](){ std::cout << k << "\n";}; // error: "k" is not captured
        auto h = [k](){ std::cout << k << "\n";}; // error: "k" is not captured
        h();
        const double u = 2.345;
        //auto i = [](){ std:: cout << u << "\n"; }; // floating-point constants should be captured 
        auto i = [u](){ std:: cout << u << "\n"; };
        i();
    }
    {
        std::cout << "run once lambda\n";
        class X
        {
            public:
            X() {
                [[maybe_unused]] static auto tmp = [](){ std::cout << "ONCE!\n"; return 0; }();
            }
        };
        X a;
        X b;
        X c;
    }
    {
        std::cout << "Generic lambda\n";
        auto f = [](auto a) { return a.first + a.second; };
        std::pair p1 = {1.2, 2.3};
        std::pair p2 = {4, 5};
        std::pair p3 = {std::string("hi"), std::string("boy")};
        std::cout << f(p1) << ", " << f(p2) << ", " << f(p3) << "\n";
        // does not work for generic lambdas
        //auto* g = +[](auto n){ return n*n; };
        int(*g)(std::pair<int, int>) = f;
        std::cout << g({102, 304}) << "\n"; 
        // variadic lambda
        auto h = [](auto&&... args){
            (std::cout << ... << args);
            std::cout << "\n";
        };
        h(1, 3, "hello");
    }
    {
        std::cout << "variable template lambda\n";
        std::cout << c_cast<int>(3.45132) << "\n";
    }
    {
        std::cout << "init capture\n";
        auto p = std::make_unique<Spy>(42);
        auto f = [p = std::move(p)](){ p->show(); };
        f();
    }
    {
        std::cout << "init capture optimization\n";
        const std::vector<std::string> v = {"apple", "orange", "foobar"};
        const std::string prefix = "foo";
        auto res = std::find_if(v.cbegin(), v.cend(), [target = prefix + "bar"](const auto& a){ return a == target; });
        if(res != v.end())
            std::cout << "something is found\n";
    }
    {
        std::cout << "lambda overload set\n";
        std::vector<std::variant<bool, int, std::string>> v = {true, 42, "sasha", false, 1984};
        Overload f{
            [](bool a){ std::cout << (a ? "True" : "False") << "\n"; }, 
            [](int a){ std::cout << "number " << a << "\n"; }, 
            [](std::string s){ std::cout << s << "\n"; } 
            };

        for(auto a: v)
            std::visit(f, a);
    }
    {
        std::cout << "C++20 stuff\n";
        struct Widget
        {
            decltype([](){ std::cout << "Hello from Widget\n"; }) f; //C++20
        };

        Widget w;
        w.f();
    }
    {
        //std::cout << "C++23 stuff! Rdcursive lambda\n";
        //auto f = [](this auto&& self, int n) { return n <= 0 ? 1 : n * self(n-1); };
        //std::cout << f(5) << "\n";
    }
}