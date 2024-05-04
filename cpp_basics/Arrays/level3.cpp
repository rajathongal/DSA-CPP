#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
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

void print1DArray(int arr[], int size) {
  cout << "Printing Array" << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
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
    for (int j = i; j < 4 - i; j++) {
      swap(a[i][j], a[j][i]);
    }
  }

  cout << "Transaposed Matrix is: " << endl;
  print2DArray(a, 4, 4);
}

void shiftNegativeNumbersLeftSide() {
  int arr[] = {0, -23, -7, 12, -10, 1, 40, -60, 89};
  int size = 7;

  int dropNegNumPos = 0;

  for (int index = 0; index < size; index++) {
    if (arr[index] < 0) {
      swap(arr[index], arr[dropNegNumPos]);
      dropNegNumPos++;
    }
  }

  print1DArray(arr, size);
}

void printVector(vector<int> v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << " ";
  }
  cout << endl;
}

void sortColorsInPlace() {
  // 0 - red, 1- white, 2-blue
  // input [2,0,1,2,2,0,1]
  // output [0,0,1,1,2,2,2]
  // leetcode 75
  // solve using 2 pointer without using any extra space

  vector<int> arr;
  arr.push_back(1);
  arr.push_back(0);
  arr.push_back(2);
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(0);
  arr.push_back(1);
  arr.push_back(0);

  cout << "Existing Array" << endl;
  printVector(arr);

  // approach
  // increment index
  // if 0 found swap index with left
  // if 2 found swap index with right
  // if 1 ignore

  int size = arr.size();
  int index = 0;
  int left = 0;
  int right = size - 1;

  while (index <= right) {
    if (arr[index] == 0) {
      swap(arr[index], arr[left]);
      left++;
      index++;
    } else if (arr[index] == 2) {
      swap(arr[index], arr[right]);
      right--; // do not increase index since the swapped element might be 2 or
               // 1
    } else {
      index++;
    }
  }

  printVector(arr);
}

void rightRotateArrayByKTimes() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);

  int size = nums.size();

  vector<int> ans(size);
  int k = 3; // k should be non negative

  for (int index = 0; index < size; index++) {
    int insertionIndex = (index + k) % size;
    ans[insertionIndex] = nums[index];
  }
  nums = ans;

  printVector(ans);
}

void findMissingNumberInArray() { // leetcode 268 O(n)
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(0);
  nums.push_back(1);

  // AP Arithmetic Progresseion

  int sum = 0;
  int size = nums.size();
  for (int i = 0; i < size; i++) {
    sum += nums[i];
  }

  int totalSum = ((size) * (size + 1)) / 2;
  int ans = totalSum - sum;
  cout << ans << endl;
}

// leetcode 2149 HW
// leetcode 2643
void findRowWithMaxOnes() {
  vector<vector<int> > mat;
  vector<int> a;
  vector<int> b;
  vector<int> c;
  vector<int> d;
  vector<int> e;

  a.push_back(1);
  a.push_back(0);
  a.push_back(0);
  a.push_back(0);

  b.push_back(0);
  b.push_back(1);
  b.push_back(1);
  b.push_back(0);

  c.push_back(0);
  c.push_back(1);
  c.push_back(1);
  c.push_back(0);

  d.push_back(1);
  d.push_back(1);
  d.push_back(1);
  d.push_back(0);

  e.push_back(0);
  e.push_back(0);
  e.push_back(1);
  e.push_back(0);

  mat.push_back(a);
  mat.push_back(b);
  mat.push_back(c);
  mat.push_back(d);
  mat.push_back(e);

  vector<int> ans;
  int n = mat.size();

  // will store max no of 1's in a row
  int oneCount = INT_MIN;
  // will store index no of max no of 1's row
  int rowNo = -1;

  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < mat[i].size(); j++) {
      if(mat[i][j] == 1) {
        count++;
      }
    }
    // after row completion compare count with oneCount
    if(count > oneCount) {
      oneCount = count;
      rowNo = i;
    }
  }

  ans.push_back(rowNo);
  ans.push_back(oneCount);

  printVector(ans);
}

void print2DVector(vector<vector<int> > arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

// leetcode 48 
void RotateImage() {
  // nxn 2d matrix 
  // in place means no additional array for answer

  vector<vector<int> > mat;
  vector<int> a;
  vector<int> b;
  vector<int> c;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  b.push_back(4);
  b.push_back(5);
  b.push_back(6);

  c.push_back(7);
  c.push_back(8);
  c.push_back(9);

  mat.push_back(a);
  mat.push_back(b);
  mat.push_back(c);

  int n = mat.size();

  // transpose
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(mat[i][j], mat[j][i]);
    }
  }

  // reverse each row
  for(int i=0; i<n; i++) {
    reverse(mat[i].begin(), mat[i].end());
  }

  print2DVector(mat);
  
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
  // transposeOfMatrix();
  // shiftNegativeNumbersLeftSide();
  // sortColorsInPlace();
  // rightRotateArrayByKTimes();
  // findMissingNumberInArray();
  // findRowWithMaxOnes();
  RotateImage();
  return 0;
}