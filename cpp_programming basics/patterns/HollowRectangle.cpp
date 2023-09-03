#include<iostream>
using namespace std;

int main() {
    int ROWS;
    int COLS;

    cout << "Enter the number of Rows" << endl;
    cin >> ROWS;

    cout << "Enter the number of Columns" << endl;
    cin >> COLS;

    // outer loop rows
    for(int row = 0; row < ROWS; row=row+1) {
        // inner loop cols
        for(int col = 0; col < COLS; col=col+1) {
            // for first and last row print stars
            if(row == 0 || row == ROWS - 1) {
                cout << "* ";
            } else {
                // for first and last column print stars
                if(col == 0 || col == COLS - 1) {
                    cout << "* ";
                } else { 
                    cout << "  "; // otherwise print space
                }
            } 
        }
        cout << endl;
    }

    return 1;
}