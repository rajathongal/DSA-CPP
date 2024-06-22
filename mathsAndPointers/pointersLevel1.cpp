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
  int* fptr = &f;
  int* pptr = fptr;
  int* qptr = fptr;

  cout << endl << f << " " << &f << endl;
  cout << fptr << " " << &fptr << " " << *fptr << endl;
  cout << pptr << " " << &pptr << " " << *pptr << endl;
  cout << qptr << " " << &qptr << " " << *qptr << endl;

}

int main() {
  pointersInit();
  return 0;
}