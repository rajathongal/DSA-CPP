#include <iostream>
#include <vector>
using namespace std;

void printSieveVector(vector< bool > v) {
  cout << "Printing Sieve Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    if (v[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
}


// TC 
// nlog(logn)
vector< bool > SieveOfE(long long int num) {
  // create a sieve array of size Num telling isprime
  vector< bool > sieve(num + 1, true);
  sieve[0] = sieve[1] = false;

  // for (long long int i = 2; i <= num; i++) {
  // optimisation 2
  // outer loop start with i = 2 and go till root of num
  // 25 root = 5
  // inner loop says i = 5 and j becomes 25 and start with 25 for marking 
  // but if num itself is 25 outer loop is trying to run but inner loop wont executes
  // so for outer loop start with 2 
  // and run till sqrt of num
  // 2 -> 4
  // 5 -> 25 
  for (long long int i = 2; i * i <= num; i++) {

    if (sieve[i] == true) {
      // long long int j = i * 2;
      // optimisation 1
      // since 2*3 is marked so no need to mark 3*4 similarly we
      // can start with multiple of prime number
      long long int j = i * i;
      while (j <= num) {
        sieve[j] = false;
        j += i;
      }
    }
  }

  return sieve;
}

int main() {
  int num = 200;
  vector< bool > sieve = SieveOfE(num);
  printSieveVector(sieve);
  return 0;
}