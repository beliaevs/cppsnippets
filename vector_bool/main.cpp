#include<vector>
#include<iostream>

template<typename Cont>
auto& getFirst(Cont& cont)
{
    return cont.front();
}

int main()
{
    std::vector<bool> v = {1,0,0,1,1};
    auto& a = getFirst(v);
    std::cout << a << "\n";
    return 0;
}