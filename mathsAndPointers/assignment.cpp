#include <iostream>
using namespace std;

void probOne() {
  float f = 10.5;
  float p = 2.5;
  float *ptr = &f;
  (*ptr)++;
  *ptr = p;
  cout << *ptr << " " << f << " " << p << endl;
}

void probTwo() {
  int a = 7;
  int b = 17;
  int *c = &b;
  *c = 7;
  cout << a << " " << b << endl;
}

void probThree() {
  int *ptr = 0; // Null pointer
  int a = 10;
  // runtime error here because you cannot dereference a null pointer *ptr =
  // something not possible
  // fix -> ptr = &a
  *ptr = a;
  cout << *ptr << endl;
}

void probFour() {
  // which of the following gives the memory address of
  // variable b pointed by pointer a
  int b = 10;
  int *a = &b;
  cout << a << " " << &b << endl;
}

void probFive() {
  char ch = 'a';
  char *ptr = &ch;
  ch++;
  cout << *ptr << endl;
}

void probSix() {
  int a = 7;
  int *c = &a;
  // the address of "a" var will be added with 4 byte which will give some
  // random garbage value

  c = c + 1;
  cout << a << " " << *c << endl;
}

void probSeven() {
  int a = 7;
  int *c = &a;
  cout << c << endl;

  c = c + 3;
  cout << c << endl;
}

void probEight() {
  double a = 7;
  double *c = &a;
  cout << c << endl;

  c = c + 1;
  cout << c << endl;
}

void probNine() {
  // assume int takes 4bytes and int pointer takes 8 bytes
  int a[5];
  int *c;
  cout << sizeof(a) << " " << sizeof(c) << endl;
}

void probTen() {
  int a[] = {1, 2, 3, 4};
  cout << *(a) << " " << *(a + 1) << endl;

  int b[3] = {1, 2, 3};
  cout << *(a + 2) << endl;
}

void probEleven() {
  // int a[] = {1, 2, 3, 4};
  // int* p = a++; // compilation error a++ = a = a + 1 // runtime error
  // // *p is a stack of location or constant pointer
  // cout << *p << endl;
}

void probTwelve() {
  int arr[] = {4, 5, 6, 7};
  int *p = (arr + 1); // 4 + 1
  cout << *arr + 9 << " " << *p << " " << *(p + 1) << endl;
}

void probThirteen() {
  char b[] = "xyz";
  char *c = &b[0];
  cout << c << " " << *c << endl;
}

void probFourteen() {
  char s[] = "hello";
  char *p = s;
  cout << s[0] << " " << p[0] << endl;
}

void probFifteen() {
  char arr[20];
  int i;
  for (i = 0; i < 10; i++) { // i will exit after i = 10
    *(arr + i) = 65 + i;
  }

  *(arr + i) = '\0';

  // after the loop i will be 10
  // arr + 10 will be pointing at 10
  // so at index 10 the value of null will be inserted and the same can be seen
  // in below cout statement
  // when null char is converted to int it will result in zero value
  cout << (int)arr[10] << endl;

  cout << arr << endl;
}

void probSixteen() {
  char* ptr;
  char str[] = "abcdefg";
  ptr = str;
  ptr += 5;
  cout << ptr << " " << *ptr << endl;
}

void probSeventeen() {
  int numbers[5];
  int* p;
  p = numbers;
  *p = 10;

  p = &numbers[2];
  *p = 20;

  p--;
  *p = 30;

  p = numbers + 3;
  *p = 40;

  p = numbers;
  *(p+4) = 50;

  for(int i=0; i < 5; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

int main() {
  // probOne();
  // probTwo();
  // probThree();
  // probFour();
  // probFive();
  // probSix();
  // probSeven();
  // probEight();
  // probNine();
  // probTen();
  // probEleven();
  // probTwelve();
  // probThirteen();
  // probFourteen();
  // probFifteen();
  // probSixteen();
  probSeventeen();
  return 0;
}