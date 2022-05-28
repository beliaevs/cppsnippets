#include <iostream>
#include <thread>
#include <string>
#include <string_view>

class ThreadSpy
{
public:
  explicit ThreadSpy(std::string name) : d_name(std::move(name))
  {
    std::cout << getFullName() << " created in thread #" << std::this_thread::get_id() << "\n";
  }

  ThreadSpy(const ThreadSpy& other) : d_name(other.d_name)
  {
    std::cout << getFullName() << " copied in thread #" << std::this_thread::get_id() << "\n";
  }

  ThreadSpy(ThreadSpy&& other) : d_name(std::move(other.d_name))
  {
    std::cout << getFullName() << " moved in thread #" << std::this_thread::get_id() << "\n";
  }

  ThreadSpy& operator=(const ThreadSpy& rhs)
  {
    std::cout << getFullName() << " = " << rhs.getFullName() << " in thread #" << std::this_thread::get_id() << "\n";
    d_name = rhs.d_name;
    return *this;
  }

  ThreadSpy& operator=(ThreadSpy&& rhs)
  {
    std::cout << getFullName() << " moved by = " << rhs.getFullName() << " in thread #" << std::this_thread::get_id()
              << "\n";
    d_name = std::move(rhs.d_name);
    return *this;
  }

  ~ThreadSpy()
  {
    std::cout << getFullName() << " is deleted in thread #" << std::this_thread::get_id() << "\n";
  }

  std::string getFullName() const
  {
    return "ThreadSpy(" + d_name + ")";
  }

private:
  std::string d_name;
};

int main()
{
  std::cout << "Hardware concurrency: " << std::thread::hardware_concurrency() << "\n";
  ThreadSpy a("initial"), b("argument");
  std::cout << "creating lambda\n";
  auto f = [a](ThreadSpy arg) { std::cout << a.getFullName() << ", " << arg.getFullName() << "\n"; };
  std::cout << "creating thread\n";
  std::thread t1(f, b);
  t1.join();
  return 0;
}