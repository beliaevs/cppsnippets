#pragma once

#include <vector>
#include <functional>

enum class RegistryID
{
  Tests,
  Demos
};

class Registry
{
public:
  using Actions = std::vector<std::function<void()>>;

  template<RegistryID N>
  static void run()
  {
    for (const auto& a : getActions<N>())
      a();
  }

  template<RegistryID N>
  static Actions& getActions()
  {
    static Registry reg;
    return reg.d_actions;
  }

private:
  Registry() = default;
  Actions d_actions;
};

template<RegistryID N>
class Registrator
{
public:
  explicit Registrator(std::function<void()> i_action)
  {
    Registry::getActions<N>().push_back(std::move(i_action));
  }
};
