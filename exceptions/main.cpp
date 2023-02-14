#include<iostream>
#include<fstream>
#include<stdexcept>
#include<string>
#include<exception>

void print_exception(const std::exception& e, int level =  0)
{
    std::cout << std::string(level, ' ') << "exception: " << e.what() << '\n';
    try 
    {
        std::rethrow_if_nested(e);
    } 
    catch(const std::exception& nestedException) 
    {
        print_exception(nestedException, level+1);
    } 
    catch(...) {}
}

// sample function that catches an exception and wraps it in a nested exception
void open_file(const std::string& s)
{
    std::ifstream file(s.c_str());
    file.exceptions(std::ios_base::failbit);
    std::string content;
    file >> content;
    std::cout << content << "\n";
}

void work_with_file(const std::string& i_name)
{
    try
    {
        open_file(i_name);
    }
    catch(...)
    {
        std::throw_with_nested(std::runtime_error("cannot work with file " + i_name));
    }
}

void run(const std::string& i_name)
{
    try
    {
        work_with_file(i_name);
    }
    catch(const std::exception& e)
    {
        std::throw_with_nested(std::runtime_error("cannot run on file " + i_name));
    }
}

int main()
{
    try
    {
        run("nonexistent.txt");
    }
    catch(const std::exception& e)
    {
        print_exception(e);
    }
    return 0;
}