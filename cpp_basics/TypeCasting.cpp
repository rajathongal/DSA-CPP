#include <iostream>
using namespace std;
/*
Type Casting

Allows you to change the data type of a variabe from one type to another.

UseCase

Crucial when you need to perform operations involving variables
of different datatypes, ensuring that the data is handled correctly

possible conversions
char -> int
int -> char
float -> int
int -> float
float -> double

Types of TypeCasting
1. Automatic Type Casting ( Implicit TypeCasting)

Compiler automatically compiles one data type to another during an operation
This happens when you perform operations involving variables of different data
types, and the compiler promotes one type to a larger type to maintain
precision.

2. Explicit TypeCasting

Manual TypeCasting
Allows you to explicitly specify the desired data type during an assignment or
operation

Usage -
you can use the casting operator which is represented by parantheses containing
the target datatype

example num1 + (int)num2

*/

void ImplicitTypeCastingExample() {
  // Implicit typecasting example

  // int -> float and float -> int
  int num1 = 10;
  float num2 = 5.5;

  float result = num1 + num2; // here num1 is converted to float
  // if num2 was converted to int then there would be information loss
  // compiler will always try to maintain the integrity of the data provided
  cout << result << endl;

  int result2 = num1 + num2;
  cout << result2 << endl;
  // info loss and num1 is stil converted to floated and while storing it in
  // result2 variable typecasting is made to int to store it in a int variable

  // char -> int and int -> char
  // compiler stores chars in ASCII values

  char ch = 'A';
  int a = ch + 1;
  cout << a << endl;
  char b = a;
  cout << b << endl;
}

void ExplicitTypeCastingExample() {
  int num1 = 10;
  float num2 = 55.5;

  int result = num1 + (int)num2;
  float result2 = num1 + (int)num2; // explicit conversion stored in implicit variable
  cout << result << endl << result2 << endl;
  
  // double to int
  double pi = 3.14159265;
  int intPi = (int)pi;

  // float to char
  float floatNum = 69.39;
  char charVal = (char)floatNum;

  cout << intPi << endl << charVal << endl;

  int a = 10;
  int b = 3.3;
  float c = a/b;
  cout << c << endl;

}

int main() {
  ImplicitTypeCastingExample();
  ExplicitTypeCastingExample();
  return 0;
}

// Important Info
// int / int = int
// int / float = float
// float / int = float