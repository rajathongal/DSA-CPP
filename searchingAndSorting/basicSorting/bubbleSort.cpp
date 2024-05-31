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
// asc order
void bubbleSortASC(vector<int> &v) {
  int size = v.size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  printVector(v);
}

//dsc order
void bubbleSortDSC(vector<int> &v) {
  int size = v.size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (v[j] < v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  printVector(v);
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

  bubbleSortASC(v);
  bubbleSortDSC(v);

  return 0;
}