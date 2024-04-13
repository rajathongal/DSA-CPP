#include<iostream>
using namespace std;

int age = 2000; // this is global variable accessible to all loops nested loops 

int main() {


    // Local varaibles 

    // i is not accessble here 
    for(int i = 0; i < 6; i++) {
        // i is a local variable for this for loop
        cout << i << endl;
    }
    // i is not accessble here 

    if(true) {
        int ab = 25; // ab is global scope for the inner if 
        if(true) {
            cout << ab << endl; // ab is accessible here 
            // we can also redfine variable here 

            int ab = 100;

            cout << ab << endl; // ab is now 100 only is second if loop level 

            // the nearest definition of variable ab is printed
        }
    }







    // Global Variable

    int a = 5;  // declare_variable
    int b;

    a = 5; //updation 

    // redfinition of variable cannot be done
    // int a = 100;

    for (int i = 0; i < a + 1; i++) {
        cout << i << a << endl; // a is accesible here as well 
    }

    cout << a << endl; // a is accesible here as well 

    return 0;
}