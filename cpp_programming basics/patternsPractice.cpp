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

void HalfPyramidRightToLeft() {
  int size;
  cout << "Enter size of Pyramid" << endl;
  cin >> size;

  // outer loop thru all rows
  for (int row = 0; row < size; row = row + 1) {
    // loop thru cols which is less than rows + 1
    for (int col = 0; col < row + 1; col = col + 1) {
      cout << "* ";
    }
    cout << endl;
  }
}

void HalfPyramidLeftToRight() {
  int size;
  cout << "Enter Size of Pyramid" << endl;
  cin >> size;
  for (int row = 0; row < size; row++) {
    // print spaces first
    for (int col = 0; col < (size - (row + 1)); col++) {
      cout << "  ";
    }

    for (int col = 0; col < row + 1; col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void Pyramid() {
  int size;
  cout << "Enter Size of Pyramid" << endl;
  cin >> size;
  for (int row = 0; row < size; row++) {
    // print spaces first
    for (int col = 0; col < (size - (row + 1)); col++) {
      cout << " ";
    }

    for (int col = 0; col < row + 1; col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void PyramidV2() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    int k = 0; // k denotes no of stars to be printed and it becomes zero after
               // every row
    for (int col = 0; col < (2 * rows) - 1; col++) {
      if (col < rows - row - 1) { // this is used to print trailing spaces
        cout << "  ";
      } else if (k < (2 * row + 1)) { // print star
        cout << "* ";
        k++; // increment k
      } else {
        cout << "  "; // ending spaces for row
      }
    }

    // after every col move to next line;
    cout << endl;
  }
}

void HollowHalfPyramidRightToLeft() {
  int size;
  cout << "Enter Size of Pyramid" << endl;
  cin >> size;

  // loop thru all rows
  for (int row = 0; row < size; row++) {
    // loop thru columns
    for (int col = 0; col < size; col++) {
      if (row == col || row == size - 1 || col == 0) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void HollowHalfPyramidLeftToRight() {

  int size = 5;
  for (int row = 1; row <= size; ++row) {
    // Print spaces for left alignment
    for (int col = size - row; col >= 1; --col) {
      cout << "  ";
    }
    // Print stars
    for (int col = 1; col <= row; ++col) {
      if (col == 1 || row == size || col == row) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl; // Move to the next line
  }
}

void HollowPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    int k = 0; // k denotes no of stars to be printed and it becomes zero after
               // every row
    for (int col = 0; col < (2 * rows) - 1; col++) {
      if (col < rows - row - 1) { // this is used to print trailing spaces
        cout << "  ";
      } else if (k < (2 * row + 1)) { // print star
        // since we were printing stars here directly
        // cout << "* ";

        // we will only print for borders left , right and bottom
        if (k == 0 || k == 2 * row || row == rows - 1) {
          // k is 0 after you enter a row and 2* row is end of the stars example
          // row 2 in pyramid we used to print 5 stars indexing from 0-4 and in
          // hollow pyramid k==0 is start and 2 time of row i.e 2*2 = 4 is the
          // end and to print the bottom stars we need to identify the row a
          // last row to do so we can compare row no === total no fo row
          // exaample total rows is 5 and r4 == row-1; r4 == 4; indexing starts
          // from 0; 0-4=5
          cout << "* ";
        } else {
          cout << "  "; //  spaces for between the stars
        }
        k++; // increment k
      } else {
        cout << "  "; // ending spaces for row
      }
    }

    // after every col move to next line;
    cout << endl;
  }
}

void InvertedLeftHalfPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    // print spaces
    for (int col = 0; col < row; col++) {
      cout << "  ";
    }

    for (int col = 0; col < rows - row; col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void InvertedHollowLeftHalfPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {

    for (int col = 0; col < rows; col++) {

      if (row == col || row == 0 || col == rows - 1) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void InvertedRightHalfPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < (rows - row); col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void InvertedHollowRightHalfPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < rows; col++) {
      if (col == rows - row - 1 || row == 0 || col == 0) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void InvertedPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;
  int cols = (2 * rows - 1);

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < row; col++) {
      cout << "  ";
    }
    for (int col = 0; col < (cols - (row * 2)); col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void InvertedHollowPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;
  int cols = (2 * rows - 1);

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      if (row == 0 || col == row || col == cols - row - 1) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void NumericHalfPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col <= row; col++) {
      cout << col + 1 << " ";
    }
    cout << endl;
  }
}

void InvertedNumericHalfPyramid() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < rows - row; col++) {
      cout << col + 1 << " ";
    }
    cout << endl;
  }
}

void Diamond() {
  int size;
  cout << "Enter Size of Diamond" << endl;
  cin >> size;

  // Upper half
  for (int row = 0; row < size; row++) {
    // printing spaces
    for (int col = 0; col < (size - row - 1); col++) {
      cout << "  ";
    }

    for (int col = 0; col < (2 * row + 1); col++) {
      cout << "* ";
    }
    cout << endl;
  }

  // below half except the middle
  for (int row = 0; row < size - 1; row++) {
    // print space
    for (int col = 0; col < (row + 1); col++) {
      cout << "  ";
    }

    // print stars
    for (int col = 0; col < (2 * size - 1) - (2 * (row + 1)); col++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void HollowDiamond() {
  int rows;
  cout << "Enter Size of Pyramid" << endl;
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    int k = 0; // k denotes no of stars to be printed and it becomes zero after
               // every row
    for (int col = 0; col < (2 * rows) - 1; col++) {
      if (col < rows - row - 1) { // this is used to print trailing spaces
        cout << "  ";
      } else if (k < (2 * row + 1)) { // print star
        // since we were printing stars here directly
        // cout << "* ";
        cout << k << 2*row << row;
        // we will only print for borders left , right 
        if (k == 0 || k == 2 * row ) {
          // k is 0 after you enter a row and 2* row is end of the stars example
          // row 2 in pyramid we used to print 5 stars indexing from 0-4 and in
          // hollow pyramid k==0 is start and 2 time of row i.e 2*2 = 4 is the
          // end and to print the bottom stars we need to identify the row a
          // last row to do so we can compare row no === total no fo row
          // exaample total rows is 5 and r4 == row-1; r4 == 4; indexing starts
          // from 0; 0-4=5
          cout << "* ";
        } else {
          cout << "  "; //  spaces for between the stars
        }
        k++; // increment k
      } else {
        cout << "  "; // ending spaces for row
      }
    }

    // after every col move to next line;
    cout << endl;
  }
}

int main() {
  // square();
  // rectangle();
  // hollowSquare();
  // hollowRectangle();
  // HalfPyramidRightToLeft();
  // HalfPyramidLeftToRight();
  // Pyramid();
  // HollowHalfPyramidRightToLeft();
  // HollowHalfPyramidLeftToRight();
  // PyramidV2();
  // HollowPyramid();
  // InvertedLeftHalfPyramid();
  // InvertedHollowLeftHalfPyramid();
  // InvertedRightHalfPyramid();
  // InvertedHollowRightHalfPyramid();
  // InvertedPyramid();
  // InvertedHollowPyramid();
  // NumericHalfPyramid();
  // InvertedNumericHalfPyramid();
  // Diamond();
  HollowDiamond();
  return 0;
}