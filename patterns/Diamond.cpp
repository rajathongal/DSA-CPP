#include<iostream>
using namespace std;

int main() {

    int n;
    int num;
    cout << "Enter the value of n" << endl;
    cin >> num;

    n = num / 2; // to print n rows 

    for (int row = 0; row < n; row = row + 1) {
        for (int col = 0; col < n - row - 1; col = col + 1) {
            cout << " ";
        }

        for (int col = 0; col < row + 1; col = col + 1) {
            cout << "* ";
        }
        cout << endl;
    }

    for (int row = 0; row < n; row = row + 1) {
        for (int col = 0; col < row; col = col + 1) {
            cout << " ";
        }

        for (int col = 0; col < n - row; col = col + 1) {
            cout << "* ";
        }

        cout << endl;
    }
    
    return 0;
}