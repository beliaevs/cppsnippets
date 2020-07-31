#include<iostream>
#include<string>
#include<vector>
#include<list>

template<typename H, typename ...T>
void print_type()
{
	std::cout << typeid(H).name() << "\t" << sizeof(H) << "\t" << alignof(H) << "\n";
	if constexpr (sizeof...(T) > 0)
		print_type<T...>();
}

int main()
{
	print_type<char, bool, short, int, long, char*>();
	print_type<std::vector<int>, std::list<int>, std::string>();
	return 0;
}