#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <iterator>

template <typename I1, typename I2>
std::pair<I1,I2> swap_ranges_n(I1 first, I2 first2, int n) {
  while (n) {
    std::swap(*first, *first2);++first;++first2;
    n--;
  }
  return std::pair<I1, I2>(first, first2);
}

template <typename I, //I models forward iterator
	  typename J> //J models integer
I reverse_n (I first, J n) {
  if (n == 0) return first;
  if (n == 1) return ++first;
  I middle = reverse_n(first, n/2);
  if (n%2 == 1) ++middle;
  I result = reverse_n(middle, n/2);
  swap_ranges_n(first, middle, n/2);
  return result;
}

template <class T, class I>
void print(I first, I last) {
  std::ostream_iterator<T> oi(std::cout," ");
  std::copy(first, last, oi);
  std::cout << std::endl;
}

int main() {
  std::vector<char> v(26);
  std::iota(v.begin(), v.end(), 'a');
  print<char>(v.begin(), v.end());
  reverse_n(v.begin(), v.size());
  std::cout << "after reverse:\n";
  print<char>(v.begin(), v.end());
}
