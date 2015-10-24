#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

template <typename B,   //B models bidirectional iterator
	  typename O>   //O models output iterator
O reverse_copy(B first, B last, O result) {
  while (first != last) {
    --last;
    *result = *last;
    ++result;
  }
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
  std::cout << "v:\n";
  print<char>(v.begin(), v.end());
  std::vector<char> w;
  reverse_copy(v.begin(), v.end(), std::back_inserter(w));
  std::cout << "w after reverse:\n";
  print<char>(w.begin(), w.end());
}
