#include<iostream>
#include<cmath>
using namespace std;

// Method 1 by Division
int decimalToBinaryDivisionMethod(int n) {
    // Division Method
    int binaryNumber = 0;
    int i = 0;
    while(n>0) {
        int bit = n % 2;
        // cout << bit << endl;
        binaryNumber = bit * pow(10, i++) + binaryNumber;
        n = n / 2;
    }
    return binaryNumber;
}

// Method 2 by Bitwise operator
int decimalToBinaryBitwiseMethod(int n) {
    // Bitwise Method
    int binaryNumber = 0;
    int i = 0;
    while(n>0) {
        int bit = (n & 1);
        // cout << bit << endl;
        binaryNumber = bit * pow(10, i++) + binaryNumber;
        n = n >> 1;
    }
    return binaryNumber;
}

int binaryToDecimal(int n) {
    int decimal = 0;
    int i = 0;

    while (n) {
        int bit = n % 10;
        decimal = decimal + bit * pow(2, i++); // can be done using bitwise home work
        n /= 10;
    }
    return decimal;
} 



int main() {
    int n;
    int binaryNumber;

    cout << "Enter a decimal value" << endl;
    cin >> n;
    int binary = decimalToBinaryDivisionMethod(n);
    cout << binary << endl;
    int binaryBitwise = decimalToBinaryBitwiseMethod(n);
    cout << binaryBitwise << endl;

    cout << "Enter a Binary value - example for 23 -> 10111" << endl;
    cin >> binaryNumber;

    cout << binaryToDecimal(binaryNumber) << endl;

}