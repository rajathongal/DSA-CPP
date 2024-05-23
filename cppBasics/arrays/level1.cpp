#include<iostream>
using namespace std;

// Arrays
// Continious blocks of memory
// one of basic data structures of a particular datatype 
// Arrays are by default pass by reference

// static array - predefined array size ex int a[100]
// methods -
// address of op
// size of array

// example 

// int arr[101];
// char ch[102];
// bool flags[99];
// long num[88];
// short [1000];

//symbol table [learn more about it]
// getting address of var or an array 
// example
// &variableName
// int ar[10]; cout (&ar or ar ) bot gives out base address of array 

// to check size of an array 
// sizeof(variableName) ex sizeof(ar)

// array initialization implicit 
// int ar[] = { 1,2,3,4,5,6,7,8,9,10,11}

// array initialization explicit
// int arr[5] = {2,3,4} for the left out spaces in array 0 is stored

// int ar[n]; is a bad practise use dynamic arrays instead

// array indexing [important]
// array[0] 0 is an index and array[10] 10 is an index and end of array is n-1

// Taking input in an array 
// int arr[5]
// cin >> arr[0] takes input in specified array index
// cin >> arr[1]
// Can be taken input from for looops 

// arr[i] is also equal to 
// value at(base address + (datatypeSize * Index)) 
// above formula give address(memory location) of the index 

int main() {
    // access values using indexing 
    int a[4] = {10, 11, 42, 93};
    cout << a[0] << " " << a[1] << " " << endl;

    int n = 3;
    int arr[3];
    for(int i = 0; i < n; i++) {
        cout << "Enter the value for index " << i << endl;
        cin >> arr[i];
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " " << endl;
    }

    // linear search in an array 
    // find 3
    // flag represents value found or not
    // true - found false - not found
    // convert this into a function

    int b[5] = {0, 1, 2, 3, 4};
    bool bflag = false;

    for(int i = 0; i< sizeof(b); i++) {
        if(b[i] == 3) {
            bflag = 1;
            break;
        }
    }

    if(bflag == 1) {
        cout << "target found " << endl;
    } else {
        cout << "target not found " << endl;
    }

    // count 0's and 1's in an array 
    int c[10] = {0, 1, 2, 3, 4, 0, 1, 2, 1, 0};


    // minimum number in an array 
    // requires #include limits.h INT_MAX, INT_MIN
    // best practise
    // to find minimum / maximum number initialize the varibale with int_max and int_min
    // so that it does not overflow or search beyond its limits

    // maximum number in an array

    // Reverse an array
    // left > right break 

    // extreme print in an array 

}