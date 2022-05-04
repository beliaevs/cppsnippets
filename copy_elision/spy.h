#pragma once

#include<iostream>
#include<string>

class Spy
{
public:
Spy() {
    std::cout << "Default Spy\n";
}

Spy(std::string name): d_name(std::move(name)){
    std::cout << "Spy(string(" << d_name << "))\n";
}

Spy(const Spy& other): d_name(other.d_name) {
    std::cout << "copy Spy(" << d_name << ")\n";
}

Spy(Spy&& other): d_name(std::move(other.d_name)){
    std::cout << "move Spy(" << d_name << ")\n";
}

Spy& operator=(const Spy& rhs) {
    std::cout << "copy assign Spy(" << d_name << ") = Spy(" << rhs.d_name << ")\n";
    d_name = rhs.d_name;
    return *this;
}

Spy& operator=(Spy&& rhs) {
    std::cout <<  "move assign Spy(" << d_name << ") = Spy(" << rhs.d_name << ")\n";
    d_name = std::move(rhs.d_name);
    return *this;
}

~Spy(){
    std::cout << "~Spy(" << d_name << ")\n";
}

const std::string& name() const& {
    return d_name;
}

std::string name() && {
    return std::move(d_name);
}
private:
std::string d_name;
};
