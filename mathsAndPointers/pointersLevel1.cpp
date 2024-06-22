#include <iostream>
#include <vector>
using namespace std;

void pointersInit() {
  int a = 5;
  cout << "Value of Variable: " << a << endl;
  cout << "Address of Variable: " << &a << endl;

  // pointer create
  int *ptr = &a;

  // acccess pointer
  cout << "Accessing Pointer itself: " << ptr << endl;
  cout << "Accessing Pointer Value: " << *ptr << endl;
  cout << "Accessiing Size of int pointer: " << sizeof(ptr) << endl;

  // pointer with different datatypes
  char ch = 'k';
  char *chptr = &ch;
  cout << "Accessiing Size of char pointer: " << sizeof(chptr) << endl;

  long num = 10;
  long *lptr = &num;

  cout << "Accessiing Size of char pointer: " << sizeof(lptr) << endl;

  // the answer of size of different datatype pointers are same why ?
  // because ptr variable stores only address
  // so answer for 32 bit system might be 4 and for 64 bit will be 8

  // do not declare pointer empty it store illegal random garbage value
  // instead point it to zero ex int* ptr = 0; or nullptr

  int b = 100;
  int *bptr = &b;
  cout << "Before: " << bptr << " " << *bptr << endl;

  bptr += 1; // gives next + 1byte memory address
  cout << "After: " << bptr << " " << *bptr << endl;

  int c = 100;
  int *cptr = &c;
  cout << "Before: " << cptr << " " << *cptr << endl;

  c += 1;
  cout << "After: " << cptr << " " << *cptr << endl;

  *cptr = *cptr + 1;
  cout << "After: " << cptr << " " << *cptr << endl;

  int d = 200;
  int *dptr = &d;

  cout << endl << d << endl;
  cout << &d << endl;
  cout << dptr << endl;
  cout << *dptr << endl;
  cout << &dptr << endl;
  cout << (*dptr)++ << endl;
  cout << *dptr << endl;

  cout << ++(*dptr) << endl;
  cout << *dptr << endl;

  *dptr = *dptr / 2;
  cout << (*dptr) << endl;
  *dptr = *dptr - 2;
  cout << (*dptr) << endl;

  int e = 5;
  int *eptr = &e;

  cout << endl << e << endl;
  cout << &e << " " << eptr << " " << &eptr << endl;
  cout << *eptr << endl;

  // pointer copy
  int *q = eptr;
  cout << endl << q << endl;
  cout << &q << " " << *q << endl;

  int f = 50;
  int *fptr = &f;
  int *pptr = fptr;
  int *qptr = fptr;

  cout << endl << f << " " << &f << endl;
  cout << fptr << " " << &fptr << " " << *fptr << endl;
  cout << pptr << " " << &pptr << " " << *pptr << endl;
  cout << qptr << " " << &qptr << " " << *qptr << endl;
}

void arrayPointers() {
  int arr[5] = {10, 20, 30, 40, 50};

  cout << arr << " " << &arr << " " << &arr[0] << endl;
  cout << arr[0] << endl;

  cout << *arr << endl;

  cout << *arr + 1 << endl;
  cout << *(arr) + 1 << endl;

  cout << *(arr + 1) << endl;
  cout << *(arr + 2) << endl;
  cout << *(arr + 3) << endl;

  cout << *(arr + 3) + 3 << endl;

  cout << 1 [arr] << " or " << arr[1] << endl;

  // int a = 11;
  // int* p = &a;
  // p = p+1;
  // cout << *p << endl; // garbage value

  // arr = arr + 1; // not possible in arrays

  int *p = arr;
  int *q = arr + 1; // arr + 1 possible for storing/updating in pointers

  cout << endl << arr << " " << &arr << " " << arr[0] << " " << &arr[0] << endl;
  cout << p << " " << &p << " " << *p << endl;
  cout << q << " " << &q << " " << *q << endl;
  cout << *p + 1 << " " << *(p) + 2 << endl;
  cout << *(q) + 2 << " " << *q + 4 << " " << *(q + 2) << endl;
  cout << sizeof(arr) << " " << sizeof(p) << endl;

  char ch[50] = "statement";
  char *chptr = ch; // or you can use &ch both gives base address of array

  cout << endl << chptr << endl;                 // print entire string
  cout << *chptr << " " << *(chptr + 1) << endl; // gives ch[0]
  cout << &ch << " " << &chptr << " " << &ch[0] << endl;

  char ch2[50] = "statement";
  char *cptr = &ch2[0];

  cout << endl << ch2 << endl;
  cout << &ch2 << " " << *(ch + 3) << " " << cptr << " " << &cptr << endl;
  cout << *(cptr + 3) << " " << cptr + 2 << " " << *cptr << " " << cptr + 8
       << endl;

  cout << endl;

  char ch3 = 'a';
  char *ch3ptr = &ch3;
  cout << ch3ptr << endl; // print a and untill null char is found with garbage values

  cout << endl;

  char ch4[10] = {'a'};
  char *ch4ptr = ch4; // &ch4 will give address of all 10 location's base address but pointer declared is for only one char
  cout << ch4ptr << endl;
}

int main() {
  // pointersInit();
  arrayPointers();
  return 0;
}