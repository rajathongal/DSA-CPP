#include<iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Enter value of n" << endl;
    cin >> n;

    for(int row = 0; row < n; row = row + 1) {
        for(int col = 0; col < row + 1; col = col + 1) {
            cout << col + 1;
        }
        cout << endl;
    }
    return 0;
}