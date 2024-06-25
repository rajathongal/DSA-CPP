#include <iostream>
#include <vector>
using namespace std;

void solve(int *arr, int size) {
  cout << "size of array inside func: " << sizeof(arr) << endl;
  cout << "Inside solve -> arr: " << arr << endl;
  cout << "Inside solve -> &arr: " << &arr << endl;
  *arr = *arr + 1;
}

void l2() {
  int a[5] = {1, 2, 3, 4, 5};

  int *ptr1 = a; // not &a when dealing with arrays of any datatypes

  // Pointer to an array.
  // &a gives five pointer or one pointer for each element in array
  // so you need to tell ptr explicitly the size
  // else you can use above syntax
  int(*ptr)[5] = &a; // same -> pointer to an array of 5

  // array of pointers
  // int* arr[5];

  cout << (*ptr)[2] << endl;

  // char ch[10] = "Rajath";
  // char* cptr = &ch;
  cout << "size of array inside func: " << sizeof(a) << endl;
  cout << "Inside main -> a: " << a << endl;
  cout << "Inside main -> &a: " << &a << endl << endl;

  solve(a, 5);
  for (int i = 0; i < 5; i++) {
    cout << a[i] << " ";
  }
  cout << endl << *(a + 2) << endl;
}

void multiPointer() {
  int a = 5;
  int *p = &a;
  int **q = &p;

  cout << a << " " << &a << endl;
  cout << p << " " << &p << " " << *p << endl;
  cout << q << " " << &q << " " << *q << " " << **q << endl;

  int b = 10;
  int *pb = &a;
  int **pc = &pb; // &a not possible
}

void multiPointer2() {
  int a = 10;
  int *p = &a;
  int **q = &p;

  // not possible as it needs a pointer of pointer which exists already
  int **r = &p;

  int ***s = &q;

  cout << *s << " " << ***s << " " << **q << " " << **s << endl;
  cout << *q << " " << *p << " " << **r << endl;
  cout << p << " " << &s << " " << &q << endl;
  cout << **s + 1 << endl;
}

// pass by value or copy of *p
void solve2(int *p) {
  // adding 5 to pointer value so the p changes
  *p = *p + 5;
}

// if int* &p -> then it will become reference and value would
// change to some garbage random value since the change will be
// made to address of p and not to the value of it
void solve3(int *p) {
  // since p is a copy and you are adding 1 to p so nothing effects
  // to main function
  p = p + 1;
}

void solve4(int* &p) {
  // since &p is address of p pointer itself modifying it would
  // lead to garbage value as you are changing the base address of pointer p
  // to main function
  p = p + 1;
}


void morePointers() {
  int a = 5;
  int *p = &a;

  cout << p << endl;
  cout << &p << endl;
  cout << *p << endl;
  // solve2(p);  // adds 5 to a
  // solve3(p);  // doesn;t affect
  solve4(p);
  cout << p << endl;
  cout << &p << endl;
  cout << *p << endl;
}

int main() {
  // l2();
  // multiPointer();
  // multiPointer2();
  morePointers();
  return 0;
}