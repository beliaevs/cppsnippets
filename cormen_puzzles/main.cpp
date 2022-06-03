#include<iostream>
#include<vector>

// count inversions using nlog(n) comparisons
// Cormen 2-4 

template<typename It>
int count_inversions(It first, It last)
{
  const auto len = last - first;
  if (len < 2)
    return 0;
  if (len == 2)
  {
    if (*first < *(last - 1))
    {
      return 0;
    }
    else
    {
      std::swap(*first, *(last - 1));
      return 1;
    }
  }
   
  It mid = first + len / 2;
  int half1 = count_inversions(first, mid);
  int half2 = count_inversions(mid, last);
  std::vector<typename It::value_type> buffer(len);
  It p1 = first; 
  It p2 = mid;
  It out = buffer.begin();
  int count = 0;
  while ((p1 != mid) && (p2 != last))
  {
    if (*p1 < *p2)
      *out++ = *p1++;
    else
    {
      count++;
      *out++ = *p2++;
    }
  }
  if (p1 != mid)
  { 
    std::copy(p1, mid, out);
    count += (mid - p1 - 1) * (last - mid);
  }
  else
    std::copy(p2, last, out);
  std::copy(buffer.begin(), buffer.end(), first);
  return half1 + half2 + count;
}


int main()
{
  std::vector<int> v{ 4, 3, 2, 1 };

  std::cout << count_inversions(v.begin(), v.end()) << "\n";
  return 0;
}