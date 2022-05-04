#pragma once

#include<iostream>
#include<string>

class Spy
{
public:
    Spy()
    {
        std::cout << "Spy default\n";
    }

    explicit Spy(std::string i_name): d_name(std::move(i_name)) 
    {
        std::cout << "Spy from string(" << d_name << ")\n";
    }

    Spy(const Spy& other) : d_name(other.d_name)
    {
        std::cout << "Spy copy(" << d_name << ")\n";
    }

    Spy(Spy&& other) : d_name(std::move(other.d_name))
    {
        std::cout << "Spy move(" << d_name << ")\n";
    }

    Spy& operator = (const Spy& rhs)
    {
        std::cout << "Spy assign: " << d_name << " = " <<  rhs.d_name << "\n";
        d_name = rhs.d_name;
        return *this;
    }

    Spy& operator = (Spy&& rhs)
    {
        std::cout << "Spy move-assign: " << d_name << " = " <<  rhs.d_name << "\n";
        d_name = std::move(rhs.d_name);
        return *this;
    }

    ~Spy()
    {
        std::cout << "~Spy(" << d_name << ")\n";
    }

    // dangerous const ref return
    // crash when called on temporary objects
    const std::string& name() const
    {
        return d_name;
    }

    void show() const
    {
        std::cout << "> Spy(" << d_name << ")\n";
    }
private:
    std::string d_name;
};
