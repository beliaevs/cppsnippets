#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<charconv>

int main()
{
    {
        const char* double_repr = "1.3*****  ";
        char* out = nullptr;
        const double val = std::strtod(double_repr, &out);
        std::cout << val << ", " << (const void*)double_repr << "\n";
        printf("%1.9f\n", val);
        std::cout << "repr len: " << (out - double_repr) << "\n";
        const double other = 1.3;
        std::cout << "val == other?: " << (val == other) << "\n";
        double a = sqrt(-1.1);
        std::cout << "root of -1 is " << a << "\n";
        double sqrt2 = std::sqrt(2.);
        printf("%.30f\n", sqrt2);
        printf("%.20f\n", sqrt2);
        printf("%.15f\n", sqrt2);
        printf("%.10f\n", sqrt2);
        printf("%.5f\n", sqrt2);
    }
    {
        const double sqrt2 = std::sqrt(2.);
        auto res = std::to_string(sqrt2);
        std::cout << "to_string: sqrt(2) = " << res << "\n";
    }
    return 0;
}