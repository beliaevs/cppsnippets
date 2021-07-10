#include<iostream>
#include<string>
#include<string_view>
#include<vector>

using Strings = std::vector<std::string>;

Strings generate(std::string_view s)
{
	Strings res;
	if (s.size() <= 1)
	{
		res.push_back(std::string(s));
		return res;
	}
	for (unsigned int i = 1; i + 1 <= s.size(); ++i)
	{
		auto res1 = generate(std::string_view(&s[0], i));
		auto res2 = generate(std::string_view(&s[i], s.size() - i));
		for (auto r1 : res1)
		{
			for (auto r2 : res2)
			{
				res.push_back("(" + r1 + r2 + ")");
			}
		}
	}
	return res;
}

int main()
{
	for (auto s : generate("abcdef"))
	{
		std::cout << s << "\n";
	}
	return 0;
}