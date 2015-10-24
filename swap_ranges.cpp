#include <iostream>
#include <vector>
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

template <class T>
T RandomNumber() {
  return T(rand()%99+1);
}

template <class T>
void printrandom(T n) {
  ostream_iterator<T> oi(cout," ");
  generate_n(oi,10,RandomNumber<T>);
  cout << endl;
  }

int main() {
  vector<int> v;
  srand(static_cast<unsigned int>(time(NULL)));
  generate_n(back_inserter(v),10,RandomNumber<int>);
  vector<int> w(10,2);
  cout << "v: ";
  print<int>(v.begin(),v.end());
  cout << "w: ";
  print<int>(w.begin(),w.end());
  swap_ranges(v.begin(), v.begin()+5,w.begin());
  cout << "After swap: \n";
  cout << "v: ";
  print<int>(v.begin(),v.end());
  cout << "w: ";
  print<int>(w.begin(),w.end());
  cout << "10 random numbers\n";
  printrandom<int>(10);
}
