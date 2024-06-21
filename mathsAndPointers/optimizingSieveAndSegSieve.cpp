#include <cmath> // for sqrt
#include <iostream>
#include <vector>
using namespace std;
#define M 1000000007

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
void printSegSieveVector(vector< bool > v, int L) {
  cout << "Printing Seg Sieve Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    if (v[i]) {
      cout << (i + L) % M << " ";
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
  // but if num itself is 25 outer loop is trying to run but inner loop wont
  // executes so for outer loop start with 2 and run till sqrt of num 2 -> 4 5
  // -> 25
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

// get prime in range of (left, right)
// segmented sieve
// R-L <= 10 ^ 6 then only create sieve
// array limit size 21

// steps
// 1. generate all primes responsible to mark seg sieve
// using normal sieve N = sqrt R
// 2. for all primes in normal sieve store primes in base primes
// 3. find first index to start marking
// ex if L - 110 /  R - 120 then / basePrime[0] -> resembles -> 110 /
// basePrime[20] -> 130
// firstMultiple = (L / prime) * prime
// 110 / 2 * 2 = 110 completely divisible
// but 110 / 3 * 3 = 108 which is less than L
// so we add prime to L
// if first multiple < L then firstmultiple += prime
// int j = i * i ;
// in seg sieve int j = max(firstMul, prime * prime)
vector< bool > SegmentedSieveOfE(long long int L, long long int R) {
  // use normal sieve to mark seg sieve sqrt(R)
  vector< bool > sieve = SieveOfE(sqrt(R));
  // base primes will be used to mark
  // sieve return bool vector ot true false fro prime
  // we store prime numbers in base primes vector
  vector< long long int > basePrimes;

  // get base prime
  for (long long int i = 0; i < sieve.size(); i++) {
    if (sieve[i]) {
      basePrimes.push_back(i);
    }
  }

  vector< bool > segSieve(R - L + 1, true);
  if (L == 1 || L == 0) {
    segSieve[L] = false;
  }

  for (auto prime : basePrimes) {
    long long int first_mul = (L / prime) * prime;
    first_mul = first_mul < L ? first_mul + prime : first_mul;
    long long int j = max(first_mul, prime * prime);
    while (j <= R) {
      // j-L is to fit in right array indexes as it start from 0-sizeofR
      segSieve[j - L] = false;
      j += prime;
    }
  }
  return segSieve;
}

long long primeProduct(long long L, long long R) {
  vector< bool > segSieve = SegmentedSieveOfE(L, R);
  long long int ans = 1;
  for (long long int i = 0; i < segSieve.size(); i++) {
    if (segSieve[i]) {
      long long int actualPrime = (L + i) % M;
      ans = (ans * actualPrime) % M;
    }
  }
  return ans;
}

int main() {
  // int num = 200;
  // vector< bool > sieve = SieveOfE(num);
  // printSieveVector(sieve);

  long long int L = 110;
  long long int R = 130;
  // vector< bool > SegSieve = SegmentedSieveOfE(L, R);
  // printSegSieveVector(SegSieve, L);
  
  cout << primeProduct(L, R) << endl;
  return 0;
}