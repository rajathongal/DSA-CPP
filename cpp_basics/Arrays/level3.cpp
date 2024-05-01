#include <iostream>
using namespace std;

void print2DArray(int arr[][4], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
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

}

int main() {
  example1();
  return 0;
}