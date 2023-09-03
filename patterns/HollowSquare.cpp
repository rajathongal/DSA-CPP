#include<iostream>
using namespace std;

int main() {

    // Input
    int num;
    cout << "Enter Value of n" << endl;
    cin >> num;

    // rows outer loop
    for(int row = 0; row < num; row=row+1) {
        // columns inner loop
        for(int col = 0; col < num; col=col+1) {
            if(row == 0 || row == num -1 || col == 0 || col == num -1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 1;
}