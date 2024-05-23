#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i < 5; i++) {
        cout << i << endl;

        if(i == 2) {
            break;
        }
    }

    for(int i = 0; i < 5; i++) {
        cout << "hello" << endl;
        continue;
        cout << "I will not appear in terminal " << endl;
    }
    return 0;
}