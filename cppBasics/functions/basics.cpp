#include <iostream>
using namespace std;

void printGreetings();

int hello(string userName) {
    cout << "Hello " << userName << endl;
    return 0;
}

int main() {

    printGreetings();
    hello("Rajath");
    return 1;
}

void printGreetings() {
    cout << "Greetings" << endl;
}