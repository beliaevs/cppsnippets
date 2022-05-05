#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
class Holder
{
  public:
  Holder(std::vector<int> data): d_data(std::move(data)){}
  const std::vector<int>& get() const {
    return d_data;
  }
  private:
  std::vector<int> d_data;
};

Holder getHolder()
{
    Holder ret({1, 4, 3, 6, 5, 7});
    return ret;
}

class StringHolder
{
    public:
    StringHolder(std::string name): d_name(std::move(name)){}
    const std::string& get() const {
        return d_name;
    }
    private:
    std::string d_name;
};

StringHolder getStringHolder()
{
    StringHolder ret("Hi baby");
    return ret;
}

int main()
{
  std::cout << getStringHolder().get() << "\n"; // OK
  [[maybe_unused]] const auto& name = getStringHolder().get(); 
  //std::cout << name << "\n"; // UB: name is dangling ref
  // OK, getholder() temporary lives till the end of full expression
  std::ranges::for_each(getHolder().get(), [](auto&& e) { std::cout << e << " ";} );
  std::cout << "\n";
  /*
  // UB: getHolder dies even before begin() and end() of it are accessed
  for(auto e: getHolder().get()) { 
      // UB: range-based for loop stores get() result in invisible 
      // reference, which becomes invalid
    std::cout << e << " ";
  }
  std::cout << "\n";
  */
}