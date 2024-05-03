#include <iostream>
using namespace std;

void print2DArray(int arr[][4], int rows, int cols) {
  cout << "Printing Array" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void print2DArrayColWise(int arr[][4], int rows, int cols) {
  cout << "Printing Array" << endl;

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

bool findTargetIn2DArray(int arr[][4], int rows, int cols, int target) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (arr[i][j] == target) {
        return true;
      }
    }
  }
  return false;
}

void printTarget(bool result, int target) {
  if (result == true) {
    cout << "Target " << target << " Found" << endl;
  } else {
    cout << "Target " << target << " Not Found" << endl;
  }
}

void example1() {
  // 2d arrays
  // continious memory like linear array
  // formula c * (i + j) c-> totalcols
  int a[2][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}};
  int b[1][2];
  int c[][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}};
  print2DArray(c, 2, 4);
  print2DArrayColWise(c, 2, 4);

  int d[3][4];

  int rows = 3;
  int cols = 4;
  cout << "Enter elements for array input" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << "Enter Element for row: " << i << " and col: " << j << endl;
      cin >> d[i][j];
    }
  }

  print2DArray(d, 3, 4);
}

void example2() {
  int a[2][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}};
  bool result;
  result = findTargetIn2DArray(a, 2, 4, 60);
  printTarget(result, 60);
  result = findTargetIn2DArray(a, 2, 4, 90);
  printTarget(result, 90);
}

int main() {
  // example1();
  example2();
  return 0;
}