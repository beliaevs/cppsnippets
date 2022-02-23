#include<iostream>
#include<vector>

int main()
{
    {
        //using MyType = int; // typedef ‘using MyType = int’ locally defined but not used
        std::cout << "Hello!\n";
    }
    {
        //int n;
        //std::cout << n << "\n"; // ‘n’ is used uninitialized in this function
    }
    {
        std::vector<int> v;
    }
    return 0;
}