#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template <typename I> //I models bidirectional iterator
std::pair<I, I>
reverse_until(I first, I middle, I last) {
  while (first != middle && middle != last) {
    --last;
    std::swap(*first, *last);
    ++first;
  }
  return std::make_pair(first, last);
}

template <typename I> //I models bidirectional iterator
I rotate(I first, I middle, I last) {
  if (first == middle) return last;
  if (middle == last) return first;
  std::reverse(first, middle);
  std::reverse(middle, last);
  std::pair<I, I> new_middle =
    reverse_until(first, middle, last);
  std::reverse(new_middle.first, new_middle.second);
  if (middle != new_middle.first) {
    return new_middle.first;
  } else {
    return new_middle.second;
  }
}

int main() {
  std::vector<int> v {1,2,3,4,5,6,7,8};
  for (auto n:v) std::cout << n << " ";
  std::cout << std::endl;
  std::vector<int>::iterator it = ::rotate(v.begin(), v.begin()+5, v.end());
  for (auto n:v) std::cout << n << " ";
  std::cout << "\trotation point at " << *it << std::endl;
}
