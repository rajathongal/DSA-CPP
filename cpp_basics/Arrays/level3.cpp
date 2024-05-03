#include <iostream>
#include <limits.h>
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

void MaxNumber() {
  int a[3][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
  };

  int max_number = INT_MIN;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] > max_number) {
        max_number = a[i][j];
      }
    }
  }

  cout << "Max Number is " << max_number << endl;
}

void MinNumber() {
  int a[3][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
  };

  int min_number = INT_MAX;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] < min_number) {
        min_number = a[i][j];
      }
    }
  }

  cout << "Minimum Number is " << min_number << endl;
}

void rowWiseSum() {
  int a[3][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
  };

  for (int i = 0; i < 3; i++) {
    int rowSum = 0;
    for (int j = 0; j < 4; j++) {
      rowSum += a[i][j];
    }
    cout << "Sum of Row: " << i << " is: " << rowSum << endl;
  }
  cout << endl;
}

void colWiseSum() {
  int a[3][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
  };

  for (int i = 0; i < 4; i++) {
    int colSum = 0;
    for (int j = 0; j < 3; j++) {
      colSum += a[j][i];
    }
    cout << "Sum of Col: " << i << " is: " << colSum << endl;
  }
  cout << endl;
}

void diagonalSum() {
  int a[4][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
      {110, 2000, 30, 2},
  };

  int diaSum = 0;
  for (int i = 0; i < 4; i++) {
    diaSum += a[i][i];
  }

  cout << "Diagonal Sum: " << diaSum << endl;
}

void diagonalCrossSum() {
  int a[4][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
      {110, 2000, 30, 2},
  };

  int diaCrossSum = 0;
  int size = 4;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        diaCrossSum += a[i][j];
      } else if (j == size - i - 1) {
        diaCrossSum += a[i][j];
      }
    }
  }

  cout << "Diagonal Cross Sum is: " << diaCrossSum << endl;
}

void transposeOfMatrix() {
  int a[4][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
      {110, 2000, 30, 2},
  };

  cout << "Matrix is: " << endl;
  print2DArray(a, 4, 4);

  // for (int i = 0; i < 4; i++) {
  //   for (int j = i; j < 4; j++) {
  //     swap(a[i][j], a[j][i]);
  //   }
  // }

  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 4 - i ; j++) {
      swap(a[i][j], a[j][i]);
    }
  }

  cout << "Transaposed Matrix is: " << endl;
  print2DArray(a, 4, 4);
}

int main() {
  // example1();
  // example2();
  // MaxNumber();
  // MinNumber();
  // rowWiseSum();
  // colWiseSum();
  // diagonalSum();
  // diagonalCrossSum();
  transposeOfMatrix();
  return 0;
}