#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void print2DVector(vector<vector<int> > arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

void TwoDVector() {
  // vector<int> arr           ----> 1D Vector
  vector<vector<int> > arr; // ---> 2D Vector
  vector<vector<int> > arrb(5, vector<int>(10, 201));
  print2DVector(arrb);
}

// Jagged Array
void JaggedArray() {
  vector<vector<int> > arr; // ---> 2D Vector 

  // multiple 1-D vector of different size
  vector<int> vect1(5, 10);
  vector<int> vect2(2, 1);
  vector<int> vect3(10, -1);

  arr.push_back(vect1);
  arr.push_back(vect2);
  arr.push_back(vect3);

  print2DVector(arr);

}

int main() {
  TwoDVector();
  JaggedArray();
  return 0;
}