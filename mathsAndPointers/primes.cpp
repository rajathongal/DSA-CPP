#include<iostream>
#include<vector>
using namespace std;

// Leetcode 204

// naive approach
// TC = O(n) + O(n-1) = O(n^2) 
// this solution exceeds time limit on leetcode
bool isPrimeNaive(int n) {
  if(n <= 1) return false;
  for(int i= 2; i<n ;i++) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int countPrimesNaive(int n) {
  int c = 0;
  for(int i=0; i< n; i++) {
    if(isPrimeNaive(i)) {
      ++c;
    }
  }
  return c;
}

// TC O(sqrt(n)) + O(n) = O(n sqrt(n))
bool isPrimeSQRT(int n) {
  if(n <= 1) return false;

  int sqrtN = sqrt(n);
  for(int i= 2; i<sqrtN ;i++) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int countPrimesSQRT(int n) {
  int c = 0;
  for(int i=0; i< n; i++) {
    if(isPrimeSQRT(i)) {
      ++c;
    }
  }
  return c;
}

// sieve of Eratosthenes method
// TC -> 
int countPrimesUsingSieveOfErastosthenes(int n) {
  if(n==0) return 0;

  vector<bool> prime(n, true); 
  prime[0] = prime[1] = false;

  int ans = 0;

  for(int i = 2; i < n; i++) {
    if(prime[i]) {
      ans++;

      int j = 2*i;
      while (j<n) {
        prime[j] = false;
        j += i;
      }
    }
  }

  return ans;
}
int main() {
  cout << "Naive Approach " << countPrimesNaive(20) << endl;
  cout << "SQRT Approach " << countPrimesSQRT(20) << endl;
  cout << "Sieve of Eratosthenes Approach " << countPrimesUsingSieveOfErastosthenes(20) << endl;


  return 0;
}