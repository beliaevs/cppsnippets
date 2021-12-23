#include<iostream>
#include<cmath>
#include<numbers>

constexpr double operator"" _deg (long double angle)
{
    return angle/180. * std::numbers::pi; 
}

constexpr double operator"" _deg (unsigned long long angle)
{
    return angle/180. * std::numbers::pi; 
}

constexpr double operator"" _minutes (unsigned long long angle)
{
    return angle/10800. * std::numbers::pi ;
}

constexpr double operator"" _minutes (long double angle)
{
    return angle/10800. * std::numbers::pi ;
}

constexpr double operator"" _seconds (long double angle)
{
    return angle/648000. *std::numbers::pi;
}

constexpr double operator"" _seconds (unsigned long long angle)
{
    return angle/648000. *std::numbers::pi;
}

int main()
{
    const auto a = 45_deg;
    const auto b = -45_deg;
    std::cout << std::sin(a) << ", " << std::cos(a) << "\n";
    std::cout << std::sin(b) << ", " << std::cos(b) << "\n";
    std::cout << std::sqrt(2)/2 << "\n";  

    const auto gamma = 30_deg + 15_minutes + 10_seconds;
    std::cout << gamma << "\n";
    return 0; 
}
