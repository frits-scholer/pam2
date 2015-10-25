#include <vector>
#include <iostream>
#include <numeric>

int main() {
  std::vector<int> v(10), w(4);
  std::iota(v.begin(), v.end(), 2);
  std::iota(w.begin(), w.end(), -2);
  v.insert(v.begin(),w.begin(),w.end());
  for (auto n: v) std::cout << n << " ";
  std::cout << std::endl;
}
