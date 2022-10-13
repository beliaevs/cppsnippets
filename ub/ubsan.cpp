#include<iostream>
#include<cstdlib>
#include<limits>

int main()
{
    int k = (std::rand() >= 0) ? std::numeric_limits<int>::max() - 10 : 0;
    bool large = (k + 15 < 0);
    std::cout << "k is large? " << large << "\n";
    return 0;
}