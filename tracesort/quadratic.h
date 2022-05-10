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
      for (; cur != first; --cur, --prev)
      {
        *cur = *prev;
      }
      *cur = element;
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
          *prev = element;
          break;
        }
      }
      *cur = element;
    }
  }
}