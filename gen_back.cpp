#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T, class I>
void print(I first, I last) {
  ostream_iterator<T> oi(cout," ");
  copy(first, last, oi);
  cout << endl;
  }
int RandomNumber() {
  return rand()%99+1;
}
int main() {
  deque<int> v;
  int nitems = 26;
  srand(static_cast<unsigned int>(time(NULL)));
  //one way to fill vector with random numbers
  generate_n(front_inserter(v),nitems, RandomNumber);
  vector<char> w;
  generate_n(back_inserter(w),nitems,[](){return 'a'+rand()%26;});
  cout << "v: ";
  print<int>(v.begin(),v.end());
  cout << "w: ";
  print<char>(w.begin(), w.end());
}
