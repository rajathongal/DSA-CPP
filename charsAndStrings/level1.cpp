#include <iostream>
#include <vector>
using namespace std;

void initChars() {
  // init char arrays
  char ch[20];

  // char array input
  // cin >> ch;

  // cout << ch << endl;

  // printing using loop
  // for (int i = 0; i < 20; i++) {
  //   cout << "At Index: " << i << " " << ch[i] << endl;
  // }

  // char temp = ch[6]; // enter 5 chars to verify null value 
  // int value = (int)temp; // to get ASCII value of NULL typecast to int
  // cout << "Printing integer value of null char in entered chars array: "
  //      << value << endl;

  char withSpaceAndTab[100];
  cin.getline(withSpaceAndTab, 100); // try giving input as: hi iam a sentence with spaces and        tab
  cout << withSpaceAndTab << endl;

}

int main() {
  initChars();
  return 0;
}