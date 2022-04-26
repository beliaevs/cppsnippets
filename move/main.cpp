#include<iostream>
#include<vector>
#include<string>

class Spy
{
public:
	Spy() = default;
	explicit Spy(std::string i_name): d_name(std::move(i_name)) 
	{
		std::cout << "Spy from string(" << i_name << ")\n";
	}

	Spy(const Spy& other) : d_name(other.d_name)
	{
		std::cout << "Spy copy(" << d_name << ")\n";
	}

	Spy(Spy&& other) : d_name(std::move(other.d_name))
	{
		std::cout << "Spy move(" << d_name << ")\n";
	}

	Spy& operator = (const Spy& rhs)
	{
		d_name = rhs.d_name;
		std::cout << "Spy assign(" << d_name << ")\n";
		return *this;
	}

	Spy& operator = (Spy&& rhs)
	{
		d_name = std::move(rhs.d_name);
		std::cout << "Spy move(" << d_name << ")\n";
		return *this;
	}

	~Spy()
	{
		std::cout << "~Spy(" << d_name << ")\n";
	}

	const std::string& name() const
	{
		return d_name;
	}

private:
	std::string d_name;
};

Spy getSpy()
{
	std::string name = "Mata Hari";
	return Spy(name);
}

int main()
{
	{ //spy test
		std::cout << getSpy().name() << "\n"; // UB???
	}
}