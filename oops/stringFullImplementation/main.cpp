#include <iostream>
#include "MyString.h"
#include <string>

using namespace std;

int main()
{
    MyString a = "Lakshay";
    MyString b = " Kumar";
    a+=b;
    cout<<a<<endl;

    a.erase(70, 1);
    cout<<a<<endl;

    // string a = "Lakshay";
    // string b = " Kumar";
    // string c = a + b;
    // cout<<c<<endl;
    return 0;
}