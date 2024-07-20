#include <iostream>
using namespace std;

inline void printNum(int num) {
  cout << num << endl;
  cout << num * 2 << endl;
  cout << num * 21 << endl;
  cout << num * 4 << endl;
  cout << num * 22 << endl;
}

int main() {

  // The actual code of printNum is inserted here as many times as called
  // THis is the reason behind consumption of space
  // But makes execution fasters
  // roughly 34856 bytes for normal function it would be much lesser.
  // above estimation is for this program only and may vary
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);
  printNum(10);

  // use inline only when function is small 
  // compilers also handle this automatically
  return 0;

}