#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << " ";
  }
  cout << endl;
}

void insertionSort(vector<int> &v) {
  int size = v.size();
  for (int i = 1; i < size; i++) {
    int key = v[i];
    int j = i - 1;

    // shift elements from 0 to i-1 
    while(j>= 0 && v[j] > key) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = key;
  }
}

int main() {

  vector<int> v;

  v.push_back(12);
  v.push_back(14);
  v.push_back(16);
  v.push_back(2);
  v.push_back(4);
  v.push_back(6);
  v.push_back(8);
  v.push_back(10);
  printVector(v);

  insertionSort(v);
  printVector(v);

  return 0;
}