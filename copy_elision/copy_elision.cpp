#include <iostream>
#include "spy.h"

int main()
{
  {
    Spy t = Spy(Spy(Spy("hello")));
  }
  {
      auto s = Spy("Bye"); // no copy, no move, just construction of Spy from string
  }
  return 0;
}