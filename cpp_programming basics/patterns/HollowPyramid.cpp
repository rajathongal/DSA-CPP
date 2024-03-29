#include<iostream>
using namespace std;

int main() {

    int rows = 5;
    
    for (int i = 1; i <= rows; ++i) {
        // Print leading spaces
        for (int j = 1; j <= rows - i; ++j) {
            cout << "  ";
        }

        // Print stars (first and last of the row, and the bottom row)
        for (int k = 1; k <= 2 * i - 1; ++k) {
            if (k == 1 || k == 2 * i - 1 || i == rows) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }

        cout << endl; // Move to the next line
    }
    return 0;
}