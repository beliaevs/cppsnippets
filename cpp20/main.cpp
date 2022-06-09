#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<ranges>

template<std::ranges::range Coll, typename T>
void add(Coll& coll, const T& val)
requires std::convertible_to<T, std::ranges::range_value_t<Coll>>
{
    if constexpr (requires {coll.push_back(val);})
    {
        coll.push_back(val);
    }
    else
    {
        coll.insert(val);
    }
}

void print(const std::ranges::input_range auto& coll)
{
    for(const auto& elem: coll)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> coll1;
    std::set<std::string> coll2;

    add(coll1, 42);
    add(coll2, "hi");

    print(coll1);
    print(coll2);

    std::vector<int> coll3{0, 8, 15, 47, 11, 42};
    print(coll3 | std::views::take(3) | std::views::transform([](auto v){return std::to_string(v) + 's';}));
    return 0;
}