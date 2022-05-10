#pragma once

template<typename It, typename Pred>
void insertion_sort(It first, It last, Pred p)
{
  if (first == last)
    return;  // empty sequence, nothing to do

  It current = first;
  ++current;

  for (; current != last; ++current)
  {
    auto element = *current;
    It cur = current;
    It prev = cur;

    --prev;
    if (p(element, *first))
    {
      // insert element on the first place
      for (; prev != first; --cur, --prev)
      {
        *cur = *prev;
      }
      *cur = *prev;
      *prev = element;
    }
    else
    {
      for (; cur != first; --cur, --prev)
      {
        if (p(element, *prev))
        {
          *cur = *prev;
        }
        else
        {
          *cur = element;
          break;
        }
      }
    }
  }
}