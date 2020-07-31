#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<list>


template<template<typename> typename F, typename H, typename... T>
void print_map()
{
	std::cout << F<H>{}.str() << "\n";
	if constexpr (sizeof...(T) > 0)
		print_map<F, T...>();
}

template<typename H>
struct IsObject
{
	std::string str()
	{
		std::stringstream os;
		os << typeid(H).name() << "\t" << std::is_object_v<H>;
		return os.str();
	}
};

template<typename H>
struct Sizes
{
	std::string str()
	{
		std::stringstream os;
		os << typeid(H).name() << "\t" << sizeof(H) << "\t" << alignof(H);
		return os.str();
	}
};

template<typename H, typename ...T>
void print_type()
{
	print_map<Sizes, T...>();
}

int main()
{
	print_type<char, bool, short, int, long, char*>();
	print_type<std::vector<int>, std::list<int>, std::string>();
	print_map<IsObject, char, int, char*, void()>();

	return 0;
}