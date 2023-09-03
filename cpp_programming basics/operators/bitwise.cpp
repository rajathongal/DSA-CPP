#include<iostream>
using namespace std;

int main() {

    int a = 5;
    int b = 1;
    bool bo = false;

    // bitwise and
    cout << (a & b) << endl;

    // bitwise or 
    cout << (a | b) << endl;

    // bitwise not 
    cout << ~a << endl;
    cout << ~bo << endl;

    //bitwise xor
    cout << (a ^ b) << endl;

    //left shift
    cout << (a << b) << endl;

    // right shift
    cout << (a >> b) << endl;

    unsigned int num = -1;
    cout << (num >> 1) << endl;

    //garbage value
    cout << (a << -1) << endl;  // will throw warning and garbage value

}