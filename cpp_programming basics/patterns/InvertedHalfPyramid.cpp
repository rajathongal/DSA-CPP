#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter value of n" << endl;
    cin >> n;

    for (int row = 0; row < n; row = row + 1) {
        for (int col = 0; col < n - row; col = col + 1) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}