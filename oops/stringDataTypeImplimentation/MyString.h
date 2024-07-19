#ifndef MYSTRING_H // if the directive is not defined, then define the my string directive
#define MYSTRING_H

#include<iostream>

class MyString {
  private:
    char *data; // pointer to char array data
    int length; // size of string
  public:
    // default ctor
    MyString();

    // Parameterised constructor
    MyString(const char *str);

    // copy ctor
    MyString(const MyString &other);

    // dtor
    ~MyString();

    int size() const;

    bool empty() const;

    const char *c_str() const;

    char operator[](int index);

    // find substring
    int find(const MyString &substr) const;

    // overload << insertion operator for easy output
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif