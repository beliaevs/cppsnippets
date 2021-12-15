#include<iostream>
#include<limits>

bool foo(int x)
{
    std::cout << x << ", " << x + 1 << ": ";
    return x+1 > x;
}

bool exists_in_table(int v)
{
    static int table[4] = {1,3,2,4};
    constexpr int N = 10;
    for(int i = 0; i <= N; i++)
    {
        std::cout << table[i] << "\n";
        if(table[i] == v)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::cout << "foo:\n";
    std::cout << foo(1) << "\n" << foo(std::numeric_limits<int>::max()) << "\n";
    std::cout << "table:\n";
    for(auto i: {3, 5})
    {
        std::cout << exists_in_table(i) << "\n";
    }
    
    return 0;
}
