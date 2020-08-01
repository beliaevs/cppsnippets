#include<iostream>
#include<vector>

namespace A
{
	struct S {};
	void f(S) 
	{
		std::cout << "A::f(S)\n";
	}
}

namespace B
{
	struct S {};
	void f(S)
	{
		std::cout << "B::f(S)\n";
	}
	void g(std::vector<S>)
	{
		std::cout << "B::g(vector<S>)\n";
	}
}

void f(int)
{
	std::cout << "spoiler\n";
}

namespace C
{
	struct S {};
	void f(std::vector<S>)
	{
		std::cout << "C::f(vector<S>)\n";
	}
}

namespace D
{
	struct S {};
	void f(std::vector<S>)
	{
		std::cout << "D::f(vector<S>)\n";
	}
}

namespace E
{
	template<typename T>
	struct Tag{};

	void f(Tag<int>)
	{
		std::cout << "E::f(Tag<int>)\n";
	}
}

namespace Parse
{
	template<typename T>
	struct To {};
}

namespace Formats
{
	struct F1
	{
		template<typename T>
		T As()
		{
			return parse(*this, Parse::To<T>{});
		}
	};

	struct F2
	{
		template<typename T>
		T As()
		{
			return parse(*this, Parse::To<T>{});
		}
	};
}

namespace DataA
{
	struct DataA1 {};
	struct DataA2 {};

	DataA1 parse(const Formats::F1&, Parse::To<DataA1>)
	{
		std::cout << "DataA1 parse(F1)\n";
		return {};
	}

	DataA2 parse(const Formats::F1&, Parse::To<DataA2>)
	{
		std::cout << "DataA2 parse(F1)\n";
		return {};
	}

	DataA1 parse(const Formats::F2&, Parse::To<DataA1>)
	{
		std::cout << "DataA1 parse(F2)\n";
		return {};
	}

	DataA2 parse(const Formats::F2&, Parse::To<DataA2>)
	{
		std::cout << "DataA2 parse(F2)\n";
		return {};
	}
}

int main()
{
	// ADL 
	f(A::S{});
	f(B::S{});
	f(std::vector<C::S>());
	f(std::vector<D::S>());
	f(E::Tag<int>{});
	// Double dispatch
	Formats::F1 format1;
	Formats::F2 format2;

	format1.As<DataA::DataA1>();
	format1.As<DataA::DataA2>();
	format2.As<DataA::DataA1>();
	format2.As<DataA::DataA2>();
}
