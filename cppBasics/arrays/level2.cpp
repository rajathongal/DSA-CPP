#include<iostream>
#include<cmath>

using namespace std;

// Arrays are by default pass by reference

void solve(int arr[],  int n) {
    arr[0] = 100;
}

int getUnique(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = ans^arr[i];
    }
    return ans;
}

void printPairs(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}

void sortZeroToOne(int arr[], int n) {
    int zerCount = 0;
    int oneCount = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            zerCount++;
        }
        if(arr[i] == 1) {
            oneCount++;
        }
    }
    int i = 0;
    for(i = 0; i < zerCount; i++) {
        arr[i] = 0;
    }
    for (int j = i; j < n; j++) {
        arr[j] = 1;
    }

    // using whle loop
    // int index = 0;
    // while(zerCount--) {
    //     arr[index] = 0;
    //     index++;
    // }

    // while(oneCount--) {
    //     arr[index] = 1;
    //     index++;
    // }


}

void shiftArray(int arr[], int n) {
    int temp = arr[n-1];

    // right shift
    for(int i = n-1; i >= 1; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    // hw left shift
}

int main() {
    int a[5] = {1, 2, 3, 4 };
    int n= 5;

    solve(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    cout << endl;

    // unique // needs a fix
    int b[] = { 1, 1, 3, 4, 3, 4, 10, 8, 10};
    int size = sizeof(b);

    int finalAns = getUnique(b, size);
    cout << finalAns << endl;

    // triplets pairs 
    int c[] = {10, 20, 30};
    printPairs(c, 3);

    for(int i = 0; i <n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << a[i] << ", " << a[j] << ", " << a[k] << endl;
            }
        }

    }

    // sorting 
    // count 0's and 1's and place it in a sep aarray

    int arr[] = { 0,1,1,0,1,0,0,0,1,0,0,0};
    int nn = 12;
    sortZeroToOne(arr, nn);
    for(int i = 0; i < nn; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // shift array elements by 1 place 
    // exaple 
    // 10 20 30
    // end result 
    // 30 10 20 
    // arr[i + 1] = arr[i] willl not work  
    // use a temp var 
    // arr[i] = arr[i - 1]

    int arrb[] = {10, 20, 30, 40, 50, 60};
    int bn = 6;

    shiftArray(arrb, bn);


    for(int i = 0; i <n; i++) {
        cout << arrb[i] << " ";
    }
    cout << endl;

}

// find Unique element 
// each element occurs multiple times
// exceppt one element, find that 
// XOR same value 0 diff value 1

// print all pairs of a n array 
// int arr[] = {2, 3}
// ans
// 2,3 // 2,2 3,3
// 3,2

// triplets of a n array

// sort 0's and 1's 

// shift array element by 1