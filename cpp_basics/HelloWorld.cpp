#include<iostream>
using namespace std;

int main() {

    cout << "Hello world!" << endl;

    // int -> 4 bytes
    int num = 50;
    cout << num << endl << &num << endl << sizeof(num) << endl;

    // char -> 1 byte
    char ch = 'k';
    cout << ch << endl << &ch << endl << sizeof(ch) << endl;

    // float -> 4 byte
    float fl = 0.09;
    cout << fl << endl << &fl << endl << sizeof(fl) << endl;

    // long -> 8 byte
    long l = 1223232;
    cout << l << endl << &l << endl << sizeof(l) << endl;

    // boolean - 1byte 
    bool t = true;
    bool f = false;
    cout << t << endl << f << endl << sizeof(t) << endl << sizeof(f) << endl;

    int a = 1;
    int b = 2;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a / b << endl;
    cout << a % b << endl;
    cout << a * b << endl;

    cout << (a>b) << endl;
    cout << (a<b) << endl;
    cout << (a>=b) << endl;
    cout << (a<=b) << endl;
    cout << (a!=b) << endl;
    cout << (a==b) << endl;

    int marks;

    cout << "Enter Marks" << endl;
    cin >> marks;
    cout << marks << endl;
    return 0;
}