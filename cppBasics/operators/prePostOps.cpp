#include<iostream>
using namespace std;

int main() {
    int a = 21;

    cout << ++a << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << --a << endl;
    cout << a << endl;
    cout << a-- << endl;
    cout << a << endl;
    int num = 10;
    cout << (++num) * (num++) << endl;
}