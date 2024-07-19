#include "MyString.h"
#include <cstring> // for strcpy, strlen, etc.
#include <utility> // for std::swap

// Default constructor
MyString::MyString() : data(new char[1]), length(0)
{
    data[0] = '\0';
}

// Parameterized constructor
MyString::MyString(const char *str) : data(new char[strlen(str) + 1]), length(strlen(str))
{
    strcpy(data, str);
}

// Copy constructor
MyString::MyString(const MyString &other) : data(new char[other.length + 1]), length(other.length)
{
    strcpy(data, other.data);
}

// Destructor
MyString::~MyString()
{
    delete[] data;
}

// Assignment operator
MyString &MyString::operator=(const MyString &other)
{
    if (this == &other)
    {
        return *this; // Return *this to deal with self-assignment
    }

    // Free existing resources
    delete[] data;

    // Copy data from other string
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);

    return *this;
}

// Concatenation (+=) operator
MyString &MyString::operator+=(const MyString &other)
{
    char *newData = new char[length + other.length + 1];
    strcpy(newData, data);
    strcat(newData, other.data);

    // Free old memory and assign new data
    delete[] data;
    data = newData;
    length += other.length;

    return *this;
}

// Subscript ([]) operator
char &MyString::operator[](size_t index)
{
    if (index >= length)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Get size of the string
size_t MyString::size() const
{
    return length;
}

// Check if string is empty
bool MyString::empty() const
{
    return length == 0;
}

// Return C-style string
const char *MyString::c_str() const
{
    return data;
}

// Append string
void MyString::append(const MyString &other)
{
    *this += other;
}

// Overload insertion operator for easy output
std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.c_str();
    return os;
}

// Find substring
int MyString::find(const MyString& substr) const {
    if (substr.length > length) return -1;

    for (size_t i = 0; i <= length - substr.length; ++i) {
        size_t j;
        for (j = 0; j < substr.length; ++j) {
            if (data[i + j] != substr.data[j]) {
                break;
            }
        }

        // If the inner loop ran fully, that means we found our string.
        if (j == substr.length) {
            return i;
        }
    }
    return -1;
}

// Erase substring
void MyString::erase(size_t pos, size_t len) {
    if (pos >= length) {
        throw std::out_of_range("Position out of range");
    }
    
    if (len == 0) {
        return;
    }
    
    if (len > length - pos) {
        len = length - pos; // Erase till the end if len exceeds the string length from pos
    }

    // Calculate new length
    size_t newLength = length - len;
    
    // Create new data array
    char *newData = new char[newLength + 1];
    
    // Copy characters before 'pos'
    strncpy(newData, data, pos);
    
    // Copy characters after 'pos + len'
    strcpy(newData + pos, data + pos + len);
    
    // Null-terminate the new string
    newData[newLength] = '\0';
    
    // Delete old data and replace with new data
    delete[] data;
    data = newData;
    
    // Update length
    length = newLength;
}


