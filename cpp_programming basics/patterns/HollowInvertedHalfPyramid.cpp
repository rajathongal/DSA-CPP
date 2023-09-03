#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter the valur of n" << endl;
    cin >> n;

    for (int row = 0; row < n; row = row + 1) {

        for ( int col = 0; col < n-row; col = col + 1) {
            if(row == 0 || col == 0) {
                cout << "* ";
            } else {
                if(col == n - row -1) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }

    // Another approach
    // for (int row = 0; row < n; row = row + 1) {
    //     for (int col = 0; col < n; col = col + 1) {
    //         if(row == 0 || col == 0 || col == n - row - 1) {
    //             cout << "* ";
    //         } else {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }
}