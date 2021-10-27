#include<iostream>
#include<unordered_map>

class A
{
    public:
    A() = delete;
    explicit A(int n): d_n(n) {}
    A(const A&) 
    { 
        if(g_debug)
            std::cout << "copy A(" << d_n << ")\n"; 
    }

    A& operator = (const A&) 
    { 
        if(g_debug)
            std::cout << "assign A(" << d_n << ")\n"; 
        return *this; 
    }

    ~A() 
    { 
        if(g_debug)
            std::cout << "A::~A(" << d_n << ")\n"; 
    }

    static void set_debug(bool i_on)
    {
        A::g_debug = i_on;
    }

    private:
    int d_n;
    static bool g_debug;
};

bool A::g_debug = false;

template<typename T>
void print_map_info(const T& i_map)
{
    std::cout << "size: " << i_map.size() << ", bucket count: " << i_map.bucket_count() 
    << ", load factor: " << i_map.load_factor() << "\n";
}

void test_map()
{
    {
        std::cout << "Test 1\n";
        std::unordered_map<int, A> m;
        for(int i = 0; i < 100; ++i)
        {
            print_map_info(m);
            m.emplace(i, 2*i);
        }
    }
    {
        std::cout << "Test 2\n";
        std::unordered_map<int, int> m { {1, 2}, {3, 4}};
        std::cout << m.contains(1) << "\n";
        std::cout << m.contains(0) << "\n";
    }
}

int main()
{
    test_map();
    return 0;
}
