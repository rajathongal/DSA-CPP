#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char *data;    // Pointer to store string data
    size_t length; // Size of the string

public:
    // Default constructor
    MyString();

    // Parameterized constructor
    MyString(const char *str);

    // Copy constructor
    MyString(const MyString &other);

    // Destructor
    ~MyString();

    // Assignment operator
    MyString &operator=(const MyString &other);

    // Concatenation (+=) operator
    MyString &operator+=(const MyString &other);

    // Subscript ([]) operator
    char &operator[](size_t index);

    // Get size of the string
    size_t size() const;

    // Check if string is empty
    bool empty() const;

    // Return C-style string
    const char *c_str() const;

    // Append string
    void append(const MyString &other);

    // Find substring
    int find(const MyString& substr) const;

    // Erase substring
    void erase(size_t pos, size_t len);

    // Overload insertion operator for easy output
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif // MYSTRING_H
