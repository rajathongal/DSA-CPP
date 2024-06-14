#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int findLength(char ch[], int size) {
  int length = 0;

  // for(int i=0; i< size; i++) {
  //   if(ch[i] == '\0') {
  //     break;
  //   } else {
  //     length++;
  //   }
  // }

  while (ch[length] != '\0') {
    length++;
  }

  return length;
}

// sequence of chars
void initChars() {
  // init char arrays
  char ch[20];

  // char array input
  // cin >> ch;
  cin.getline(ch, 20);

  // cout << ch << endl;

  // printing using loop
  // for (int i = 0; i < 20; i++) {
  //   cout << "At Index: " << i << " " << ch[i] << endl;
  // }

  // char temp = ch[6]; // enter 5 chars to verify null value
  // int value = (int)temp; // to get ASCII value of NULL typecast to int
  // cout << "Printing integer value of null char in entered chars array: "
  //      << value << endl;

  // char withSpaceAndTab[100];
  // cin.getline(withSpaceAndTab, 100); // try giving input as: hi iam a
  // sentence with spaces and        tab cout << withSpaceAndTab << endl;

  int len = findLength(ch, 20);
  cout << "Length: " << len << endl;
  cout << "Using In built function: " << strlen(ch) << endl;
}

void reverseString() {
  // 2 pointer

  char ch[100];
  cin.getline(ch, 100);
  int size = strlen(ch);

  int i = 0;
  int j = size - 1;

  while (i < j) {
    swap(ch[i], ch[j]);
    i++;
    j--;
  }

  cout << ch << endl;
}

void convertToUpperCase() {
  char ch[100];
  cin.getline(ch, 100);
  int size = strlen(ch);
  int index = 0;
  while (index < size) {
    char currentChar = ch[index];

    // check if currentchar is a lowerCase if yes then convert to upper case
    if (currentChar >= 'a' &&
        currentChar <= 'z') { // to avoid spaces and tab from conversion and
                              // only for small chars
      ch[index] = currentChar - 'a' + 'A';
    }

    index++;
  }

  cout << ch << endl;
}

void replaceAtWithSpace() {
  char ch[100];
  cin.getline(ch, 100);
  int size = strlen(ch);
  int index = 0;

  while (index < size) {
    char currentChar = ch[index];
    if (currentChar == '@') {
      ch[index] = ' ';
    }
    index++;
  }

  cout << ch << endl;
}

void checkPalindrome() {
  char ch[100];
  cin.getline(ch, 100);
  int size = strlen(ch);

  int i = 0;
  int j = size - 1;

  while (i <= j) {
    if (ch[i] == ch[j]) {
      i++;
      j--;
    } else {
      cout << "Not Palindrome" << endl;
      return;
    }
  }

  cout << "Palindrome" << endl;
}

void stringsInit() {
  string name;
  string str;

  // cin >> name;
  // cout << name << endl;
  // cout << "Printing first char of string is: " << name[0] << endl;

  // int index = 0;

  // while(name[index] != '\0') {
  //   cout << "Index: " << index << " charecter: " << name[index] << endl;
  //   index++;
  // }

  getline(cin, str); // Enter hello world
  cout << str << endl;

  // inbuilt functions
  // size
  // empty
  // push_back
  // pop_back
  // append
  // at
  // substr
  // compare
  // erase

  cout << "Length of string: " << str.length() << endl;
  cout << "isEmpty of name string: " << name.empty() << endl;
  cout << "isEmpty of STR string: " << str.empty() << endl;

  cout << "Char at 0 in str string: " << str.at(0) << endl;
  cout << "Front char and back char in str string: " << str.front()
       << " Back: " << str.back() << endl;

  string appendStr = "Greetings ! ";
  appendStr.append(str);
  cout << "After appending: " << appendStr << endl;

  // erase
  appendStr.erase(9, 2);
  cout << "After erase: " << appendStr << endl;

  // insert a string at a given location
  string insertionText = "Rajath ";

  appendStr.insert(10, insertionText);
  cout << "After insertion: " << appendStr << endl;

  // push pop
  appendStr.push_back('s');
  cout << "After push back: " << appendStr << endl;

  appendStr.pop_back();
  cout << "After pop back: " << appendStr << endl;

  // find str in str
  // npos is for not found or no position
  if (appendStr.find(str) == string::npos) {
    cout << "Not Found" << endl;
  } else {
    cout << "Found" << endl;
  }

  if (appendStr.find("Hallu") == string::npos) {
    cout << "Not Found" << endl;
  } else {
    cout << "Found" << endl;
  }

  // compare if strings match
  string cmpStrOne = "Raja";
  string cmpStrTwo = "Raja";
  string cmpStrThree = "Rajat";

  if (cmpStrOne.compare(cmpStrTwo) != 0) {
    cout << "Not Match" << endl;
  } else {
    cout << "Match" << endl;
  }

  if (cmpStrThree.compare(cmpStrTwo) != 0) {
    cout << "Not Match" << endl;
  } else {
    cout << "Match" << endl;
  }

  // generate substring or select certail part of string 
  cout << "Substring: " << appendStr.substr(10, 5) << endl;
}

int main() {
  // initChars();
  // reverseString();
  // convertToUpperCase();
  // replaceAtWithSpace();
  // checkPalindrome();
  stringsInit();
  return 0;
}