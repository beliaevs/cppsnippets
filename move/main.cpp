#include<cfloat>
#include<iostream>
#include<vector>
#include<string>
#include "cont.h"

class Spy
{
public:
	Spy()
	{
		std::cout << "Spy default\n";
	}

	explicit Spy(std::string i_name): d_name(std::move(i_name)) 
	{
		std::cout << "Spy from string(" << d_name << ")\n";
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
		std::cout << "Spy move-assign(" << d_name << ")\n";
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

class SpyHolder
{
	// Don't take by value and move if you:
	// 1. set an existing value (move assignment vs move constructor + move assignment)
	// 2. might not adopt
	// 3. move is expensive
	//
	// holder.setSpy(spy);
	// could have difficulty of 
	// 1. "spy copy" + "spy move assignment" or
	// 2. "spy assignment"
	// 
    // holder.setSpy(std::move(spy))
	// could have difficulty of
	// 1. "spy move" + "spy move assignment"
	// 2. "spy move assignment" 
public:
	SpyHolder() = default;
	// 1. Simple strategy, pass by value only
	 /*
	void setSpy(Spy spy)
	{
		d_spy = std::move(spy);
	}
*/
    // 2. More involved overloading 
	
	void setSpy(const Spy& spy)
	{
		d_spy = spy;
	}

	void setSpy(Spy&& spy)
	{
		d_spy = std::move(spy);
	}
    
private:
	Spy d_spy;
};

static Spy getSpy()
{
	std::string name = "Mata Hari jsjsjjjskjahjskdghjshgajhsdhjksjhaksjdgjhghjasjkhdjkjasjhdghjhasdgh";
	Spy spy(name);
	return spy;
}

static std::string getStr()
{
	std::string ret("string 1 string 1 string 1 string 1 string 1");
	std::cout << "getStr:\n";
	std::cout << mem(ret) << '\n';
	return ret;
}

int main()
{
	{
		SpyHolder holder;
		holder.setSpy(getSpy());
		Spy myspy("My personal spy");
		holder.setSpy(std::move(myspy));
	}
	{
	// floating point test
		std::cout << "FLT_EVAL_METHOD: " << FLT_EVAL_METHOD << "\n";
	}
	{ //spy test
		const auto& s = getSpy().name();
		std::cout << s << "\n"; // UB !!! const ref does not prolong life of the temporary 
	}
	{
		Cont cont;
		const std::string str = "hellohellohellohellohello";
		std::cout << mem(str) << "\n";
		cont.insert(std::move(str));
		cont.insert(getStr());
		cont.print();
	}
	{
		ContT<std::string> txt;
		txt.insert(getStr());
		txt.print();

		ContT<bool> bs;
		bs.insert(true);
		bs.insert(false);
		bs.print();

		ContT<Spy> cia;
		Spy myspy("zorge");
		cia.insert(std::move(myspy));
		Spy otherspy("avva");
		// expensive: copy even if the spy is not inserted
		cia.insertIf(otherspy, [](const Spy& a){ return a.name().length() > 5; });
		// ok, copy + move in case of insertion
		cia.insertIf(otherspy, [](const Spy& a){ return !a.name().empty() && a.name()[0] == 'a'; });
	}
	{
		ContT<Spy> cia;
		Spy myspy("Zorge");
		// nothing happens!
		// non-const lvalue
		// U->Spy&
		cia.insertIf1(myspy, [](const Spy& a){ return !a.name().empty() && a.name()[0] == 'a';});
		// Ok, only copy
		const Spy otherspy("Z");
		// const lvalue
		// U->const Spy&
		cia.insertIf1(otherspy, [](const Spy& a){ return !a.name().empty() && a.name()[0] == 'Z';});
		// rvalue
        // U->Spy
		cia.insertIf1(Spy("Hi"), [](const Spy&) {return true; });
	}
}