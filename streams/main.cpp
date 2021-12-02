#include<iostream>
#include<exception>

int getInt(std::istream& istr)
{
    int res = 0;
    if(istr >> res)
        return res;
    throw std::runtime_error("input error");
}

int main()
{
    int a = 0;
    int b = 0;
   
    try
    {
        std::cout << "Number 1: ";
        a = getInt(std::cin);
        std::cout << "Number 2: ";
        b = getInt(std::cin);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    
    std::cout << a << " + " << b << " = " << a + b << "\n";
    return 0;
}