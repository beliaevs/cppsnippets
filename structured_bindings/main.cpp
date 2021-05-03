#include<iostream>
#include<tuple>
#include<string>


class Structured
{
    public:
        Structured(double volume, double weight): d_volume(volume), d_weight(weight) 
        {}

    template <std::size_t N>
    decltype(auto) get() const 
    {
       if      constexpr (N == 0) return d_volume;
       else if constexpr (N == 1) return d_weight;
    }

private:
    double d_volume;
    double d_weight;
};

namespace std 
{
    template<>
    struct tuple_size<Structured>
        : std::integral_constant<std::size_t, 2> {};

    template<std::size_t N>
    struct tuple_element<N, Structured> 
    {
        using type = decltype(std::declval<Structured>().get<N>());
    };
}


Structured getObj()
{
    return {23, 32};
}

std::tuple<std::string, int, double> getPerson()
{
    return {"sasha", 42, 83.5};
} 

int main()
{
    {
        auto [name, age, weight] = getPerson();
        std::cout << "name: " << name << ", age: " << age << ", weight: " << weight << "\n";
    }
    {
        auto [volume, weight] = getObj();
        std::cout << "volume: " << volume << ", weight: " << weight << ", density: " << weight/volume << "\n";
    }
    return 0;
}