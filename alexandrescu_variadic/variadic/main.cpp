#include<iostream>
#include<variant>
#include<typeinfo>

class Sentinel
{
public:
  ~Sentinel()
  {
    std::cout << "~Sentinel\n";
  }
};

template<typename... Ts> class mytype_sequence {};

template<typename Seq> 
class head
{
};

template<typename T, typename... Ts>
class head<mytype_sequence<T, Ts...>>
{
public:
  using res = T;
};

template<typename T> using head_v = typename head<T>::res;

template<typename T>
class tail {};

template<typename T, typename... Ts>
class tail<mytype_sequence<T, Ts...>>
{
public:
  using res = mytype_sequence<Ts...>;
};

template<typename Seq> using tail_v = typename tail<Seq>::res;
 
template<typename T, typename Ts>
class cons {};

template<typename T, typename... Ts>
class cons<T, mytype_sequence<Ts...>>
{
public:
  using res = mytype_sequence<T, Ts...>;
};

template<typename T, typename Seq>
using cons_v = typename cons<T, Seq>::res;

int main()
{
  std::variant<int, Sentinel> v;
  v = Sentinel();

  {
    using myseq_t = mytype_sequence<char, int, double>;
    using myhead = head_v<myseq_t>;
    using mytail = tail_v<myseq_t>;
    using add_float = cons_v<float, myseq_t>;
    std::cout << typeid(myhead).name() << "\n";
    std::cout << typeid(mytail).name() << "\n";
    std::cout << typeid(add_float).name() << "\n";
  }

  return 0;
}