#include <iostream>
using namespace std;

void sumOfNumbers(int a, int b, int c) {
    int answer = a + b + c;
    cout << "Answer is " << answer << endl;
    return; // do not send any data with return.
}

int sumByreturn(int a, int b, int c) {
    int answer = a + b + c;
    return answer;
}

int main() {

    // cout << "enter 3 numbers " << endl;
    sumOfNumbers(3,5,7);

    int sum = sumByreturn(2,6,9);
    cout << "Sum " << sum << endl;
    return 1;
}