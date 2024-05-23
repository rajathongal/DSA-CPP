#include <iostream>
using namespace std;

int main() {
  
    int num = 7;

    if(num%2 == 0) {
        cout << "Even" << endl;
    }
    else {
        cout << "Odd" << endl;
    }

    // differntiating output
    cout << endl << "-----------" << endl;

    int num2 = 0;

    if(num2 > 0) {
        cout << "Positive " << endl;
    }
    else if(num2 < 0) {
        cout << "negative" << endl;
    }
    else {
        cout << "zero" << endl;
    }

    // differntiating output
    cout << endl << "-----------" << endl;


    int i=1;
    for(; ; ) { //infinite loopin 
        cout << "value of i is :" << i << endl;
        if(i<5) {
            cout << "babbar" << endl;
            i=i+1;
        }
        // to avoid infinite looping
        else {
            break;
        }
        
    }

    // differntiating output
    cout << endl << "-----------" << endl;

    for(int i=0; i<3; i=i+1) {
		cout<< endl << "Outer Loop " << i << endl << endl; 
		
		for(int j=0; j<3; j=j+1) {
			cout << "inner loop " << j << endl;
		}
		
	}

    // differntiating output
    cout << endl << "-----------" << endl;

    for(int i=0; i<5; i=i+1) {
		cout << "A" << " ";
	}

    // differntiating output
    cout << endl << "-----------" << endl;

    for(int i=10 ;i>=0; i= i - 3) {
		cout << i << endl;
	}

    // differntiating output
    cout << endl << "-----------" << endl;

    for(int i=10; i<=12; i=i+1) {
		cout << "Monica, my darlo" << endl;
	}

    // differntiating output
    cout << endl << "-----------" << endl;
  

    int a = 20;
	int b = 10;

	cout << (a == b) << endl;

    // differntiating output
    cout << endl << "-----------" << endl;

    cout << a + b << endl;
	cout << a - b << endl;
	cout << a*b << endl;
	cout << a/b << endl;
	cout << b % a << endl; 
	// garbage value
	int num3;
	num3 = 12;
	cout << num3 << endl;

     // differntiating output
    cout << endl << "-----------" << endl;

    
    return 0;
}