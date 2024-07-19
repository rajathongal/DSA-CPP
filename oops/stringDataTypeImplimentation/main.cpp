#include<iostream>
using namespace std;
#include "MyString.h"

int main() {

  MyString s("codeHelp");
  MyString b = "LoveLakshay";

  cout << s << endl;
  cout << b << endl;

  cout << s[0] << endl;

  cout << s.find("Help") << endl;

  return 0;
}