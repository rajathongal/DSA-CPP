#include <iostream>
using namespace std;

void solve(int& a) { // get actual varibale address and any operation made here can be seen in main function as well 
    a++;
    cout << "Print inside solve " << a << endl;
}

void solve2(int& a) {
    a--;
    a = a * 10;
    cout << "Print inside solve " << a << endl;
}

int main() {
    int a = 5;
    solve(a);
    cout << "Print inside main "<<  a << endl;

    a++;
    solve2(a);
    cout << "Print inside main "<<  a << endl;

}

