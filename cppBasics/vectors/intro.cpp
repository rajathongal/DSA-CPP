#include <iostream>
#include <vector> // needs header
using namespace std;

void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i] << endl;
  }
}

void basicArrayOps() {
  // static memory allocation of an array
  int arr[5] = {1, 2, 4, 5, 7};
  printArray(arr, 5);

  // dynamic memory allocation but not shrink
  int size;
  cout << "enter size of dynamic array" << endl;
  cin >> size;
  int *ar = new int[size];
  // the value stored will be either 0 or garbage if
  // not entered any
  // can not add more elements then specified size taken from user
  printArray(ar, 4);
}

void printVector(vector<int> v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << endl;
  }
  cout << endl;
}

void printVectorNativeMethod(vector<char> v) {
  // for each loop
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;

}

// header is required
void vectors() {
  // init methods
  vector<int> v;         // init
  vector<int> a(10, 33); // (size, prefillValue), this allows pre allocation and
                         // can expand and shrink

  v.push_back(1);  // insert
  v.push_back(12); // insert
  v.push_back(13); // insert

  // print
  printVector(v);

  v.pop_back(); // pop
  printVector(v);

  v.pop_back(); // pop
  printVector(v);

  // capacity and size
  vector<int> n;

  while (n.size() < 10) {
    int d;
    cout << endl << "Enter vector element" << endl;
    cin >> d;
    n.push_back(d);
    cout << "Capacity: " << n.capacity() << " Size: " << n.size() << endl;
  }

  // to remove all the data in the vector
  n.clear();

  v.push_back(100); // insert
  v.push_back(10);  // insert

  printVector(a);

  // Copying vector
  vector<int> b(10, 1);
  vector<int> c(b);
  printVector(b);
  printVector(c);

  // available with all datatypes
  vector<char> chars;

  chars.push_back('a');
  chars.push_back('b');
  chars.push_back('c');
  chars.push_back('y');
  chars.push_back('z');

  // more on vector inbuilt methods
  cout << "Front element: " << chars.front() << endl
       << "Back element: " << chars.back() << endl;

  printVectorNativeMethod(chars);
}

int main() {
  // basicArrayOps();
  vectors();
  return 0;
}