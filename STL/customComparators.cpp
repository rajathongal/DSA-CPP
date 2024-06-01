#include <algorithm>
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

void print2DVector(vector<vector<int> > arr) {
  cout << "Printing 2D Vector" << endl;

  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

bool oneDArrayDescendingOrderComparator(int &a, int &b) { return a > b; }

bool twoDArrayDescendingOrderOnFirststIndexComparator(vector<int> &a, vector<int> &b) {
  return a[1] > b[1];
}

int main() {

  // custom comparator on 1d vector
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

  sort(v.begin(), v.end()); // asc order
  printVector(v);

  sort(v.begin(), v.end(), oneDArrayDescendingOrderComparator); // dsc order
  printVector(v);

  // custom comparator on 2d vector
  vector<int> row1;
  vector<int> row2;
  vector<int> row3;

  row1.push_back(1);
  row1.push_back(2);
  row1.push_back(3);
  row1.push_back(4);

  row2.push_back(5);
  row2.push_back(6);
  row2.push_back(7);
  row2.push_back(8);

  row3.push_back(9);
  row3.push_back(10);
  row3.push_back(11);
  row3.push_back(12);

  vector<vector<int> > arr;
  arr.push_back(row1);
  arr.push_back(row2);
  arr.push_back(row3);

  print2DVector(arr);

  sort(arr.begin(), arr.end(), twoDArrayDescendingOrderOnFirststIndexComparator);
  print2DVector(arr);

  return 0;
}