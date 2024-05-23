#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

void AreaOfRectangle() {
  double width, length;
  cout << "Enter width and length of the rectangle" << endl;
  cin >> width >> length;
  double area = width * length;
  cout << area << endl;
}

void binaryToDecimal() {
  int binary;
  int decimal = 0, i = 0, remainder;
  cout << "Enter Binary Number" << endl;

  cin >> binary;

  while (binary > 0) {
    remainder = binary % 10;
    binary /= 10;
    decimal += remainder * pow(2, i);
    ++i;
  }
  cout << decimal << endl;
  return;
}

void PrintNPrimeNumbers() {
  int n, flag = 1;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    flag = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        flag = 0;
      }
    }
    if (flag == 1) {
      cout << i << endl;
    }
  }
}

void ReverseNumber() {
  int n, a = 0;
  cin >> n;
  int z = n, digits = 0;
  while (z != 0) {
    z = z / 10;
    digits++;
  }
  while (n != 0) {
    int k = n % 10, z = digits - 1;
    while (z--) {
      k = k * 10;
    }
    a = a + k;
    digits--;
    n = n / 10;
  }
  cout << a;
}

bool checkMember(int n) {
  int f1 = 1, f2 = 1;
  if (n == 0 && n == 1) {
    return true;
  } else {
    while (1) {
      int temp = f1 + f2;
      f1 = f2;
      f2 = temp;
      if (temp == n) {
        return true;
      } else if (temp > n) {
        return false;
      }
    }
  }
}

/*
Pattern for N = 4
   1
  212
 32123
4321234
*/

void PyramidPattern() {
  int n;
  cin >> n;
  int i = 0, gaps = n - 1;
  while (i < n) {
    int k = 0, gaps = n - 1 - i;
    while (k < gaps) {
      cout << " ";
      k++;
    }
    int num = i + 1;
    while (num > 0) {
      cout << num;
      num = num - 1;
    }
    k = 2;
    while (k <= (i + 1)) {
      cout << k;
      k++;
    }
    k = 0;
    while (k < gaps) {
      cout << " ";
      k++;
    }
    i++;
    cout << "\n";
  }
}

/*
Pattern for N = 5
1234554321
1234**4321
123****321
12******21
1********1
*/

void Pattern() {
  int n;
  cin >> n;
  int i = 0;
  while (i < n) {
    int count = n - i, k = 1;
    while (k <= count) {
      cout << k;
      k++;
    }
    count = n - i;
    int stars = 2 * i;
    while (stars > 0) {
      cout << "*";
      stars--;
    }
    count = n - i;
    while (count > 0) {
      cout << count;
      count--;
    }
    cout << "\n";
    i++;
  }
}

void SecondLargestNumber() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (n == 0 || n == 1) {
    cout << INT_MIN;
  } else {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (max < arr[i]) {
        max = arr[i];
      }
    }
    int second = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (max > arr[i] && arr[i] > second) {
        second = arr[i];
      }
    }
    cout << second;
  }
}

void Pattern2(){
  int i,j,n;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            cout<<n-i+1;
            
        }
        cout<<endl;
        
    }
}


int main() {
  // AreaOfRectangle();
  // binaryToDecimal();
  // PrintNPrimeNumbers();
  // ReverseNumber();
  // cout << checkMember(7) << endl << checkMember(593) << endl <<
  // checkMember(21) << endl; PyramidPattern(); Pattern();
  // SecondLargestNumber();
  Pattern2();
  return 0;
}