#include<iostream>
#include<boost/type_index.hpp>
#include<string>
class Spy
{
    public:
    explicit Spy(std::string name): d_name(std::move(name))
    {
        std::cout << "Spy(" << d_name << ")\n";
    }

    ~Spy()
    {
        std::cout << "~Spy(" << d_name << ")\n";
    }

    void show() const
    {
        std::cout << "Spy> " << d_name << "\n";
    }
    private:
    std::string d_name;
};

Spy getSpy()
{
    return Spy("temp spy");
}

int getInt()
{
    return 45;
}

template<typename T>
void uniref(T&&)
{
    std::cout << boost::typeindex::type_id_with_cvr<T>().pretty_name() << "\n";
}

template<typename T>
T&& id(T&& x)
{
    std::cout << "id> " << &x << "\n";
    return std::forward<T>(x);
}

int main()
{
    {
        int a = 23;
        const int ca = 32;
        int& ra = a; //ok
        const int& cra = ca; //ok
        //int& ra2 = ca;//error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
        //int&& rra = a; //error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
        //int& ra2 = getInt(); //error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
        //int& ra3 = 3; // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
        int&& rref = getInt();
        std::cout << rref << "\n";
        Spy&& rrspy = getSpy();
        rrspy.show();
        //Spy& rspy = getSpy();  //error: cannot bind non-const lvalue reference of type ‘Spy&’ to an rvalue of type ‘Spy’
        const Spy& crspy = getSpy(); //ok
        uniref(getSpy()); // T -> Spy
        uniref(rrspy); // T -> Spy&
        uniref(crspy); // T -> const Spy&
        uniref(ra); // T -> int&
        uniref(std::move(ra)); // T -> int
        std::cout << boost::typeindex::type_id_with_cvr<decltype(std::move(3))>().pretty_name() << "\n"; //int&&
    }
    {
        int n = 8;
        auto&& tn = id(n);
        std::cout << "tn: " << boost::typeindex::type_id_with_cvr<decltype(tn)>().pretty_name() << "\n";
        std::cout << &n << "->" << &tn << "\n";
        const int cn = 9;
        auto&& ctn = id(cn);
        std::cout << "ctn: " << boost::typeindex::type_id_with_cvr<decltype(ctn)>().pretty_name() << "\n";
        std::cout << &cn << "->" << &ctn << "\n";
        auto&& lit = id(10);
        std::cout << "lit: " << boost::typeindex::type_id_with_cvr<decltype(lit)>().pretty_name() << "\n";
        std::cout << &lit << "\n";
    }
    return 0;
}
