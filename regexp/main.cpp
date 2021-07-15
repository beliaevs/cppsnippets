#include<iostream>
#include<string>
#include<regex>
#include<string_view>

void show_matches(const std::string& in, const std::string& re)
{
    std::smatch m;
    std::regex_search(in, m, std::regex(re));
    if(m.empty()) {
        std::cout << "input=[" << in << "], regex=[" << re << "]: NO MATCH\n";
    } else {
        std::cout << "input=[" << in << "], regex=[" << re << "]: ";
        std::cout << "prefix=[" << m.prefix() << "] ";
        for(std::size_t n = 0; n < m.size(); ++n)
            std::cout << " m[" << n << "]=[" << m[n] << "] ";
        std::cout << "suffix=[" << m.suffix() << "]\n";
    }
}

int main()
{
    using namespace std::literals;
    std::string rxstring = "aa";
    std::regex rx(rxstring);
    std::string s;
    std::cout << rxstring << "\n";
    while(std::cin >> s)
    {
        std::cout << "match: " << std::regex_match(s, rx) << "\n";
        std::cout << "search: " << std::regex_search(s, rx) << "\n";
        show_matches(s, rxstring);
    }
    {
        const std::string s = "Quick brown fox.";
 
        std::regex words_regex(R"([^\s]+)");
        auto words_begin = 
            std::sregex_iterator(s.begin(), s.end(), words_regex);
        auto words_end = std::sregex_iterator();
 
        std::cout << "Found " 
                 << std::distance(words_begin, words_end) 
                 << " words:\n";
 
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;                                                 
            std::string match_str = match.str(); 
            std::cout << match_str << '\n';
        }   
    }
}