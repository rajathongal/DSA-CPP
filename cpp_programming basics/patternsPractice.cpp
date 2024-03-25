#include<iostream>
using namespace std;

void square() {

    int size;
    cout << "Enter the value of size" << endl;
    cin >> size;

    //rows outer loop 
    for(int row = 0; row < size; row++) {
        // colmus inner loop
        for(int col = 0; col < size; col++) {
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
    for(int row = 0; row < rows; row++) {
        // inner loop cols 
        for(int col = 0; col < cols; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void hollowSquare() {
    
}

int main () {
    // square();
    // rectangle();
    return 0;
}