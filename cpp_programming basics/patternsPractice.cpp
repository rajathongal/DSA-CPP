#include <iostream>
using namespace std;

void square() {

  int size;
  cout << "Enter the value of size" << endl;
  cin >> size;

  // rows outer loop
  for (int row = 0; row < size; row++) {
    // colmus inner loop
    for (int col = 0; col < size; col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void rectangle() {
  int rows;
  int cols;

  cout << "Enter the number of rows" << endl;
  cin >> rows;
  cout << "Enter the number of columns" << endl;
  cin >> cols;

  // rows outer loop
  for (int row = 0; row < rows; row++) {
    // inner loop cols
    for (int col = 0; col < cols; col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void hollowSquare() {
  int size;
  cout << "Enter the Size " << endl;
  cin >> size;

  // rows outer loop
  for (int row = 0; row < size; row++) {
    // cols inner loops
    for (int cols = 0; cols < size; cols++) {
      if (row == 0 || row == size - 1 || cols == 0 || cols == size - 1) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void hollowRectangle() {
  int noOfRows;
  int noOfCols;

  cout << "Enter the number of rows" << endl;
  cin >> noOfRows;
  cout << "Enter the number of columns" << endl;
  cin >> noOfCols;

  // outer loop rows
  for (int row = 0; row < noOfRows; row = row + 1) {
    // inner for cols
    for (int col = 0; col < noOfCols; col = col + 1) {
      if (row == 0 || row == noOfRows - 1 || col == 0 || col == noOfCols - 1) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void HalfPyramid() {
     
}

int main() {
  // square();
  // rectangle();
  // hollowSquare();
  // hollowRectangle();
  return 0;
}