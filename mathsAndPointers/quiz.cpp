#include <iostream>
using namespace std;

void modifyValue(int* ptr) {
  (*ptr) *= 2;
}

void modifyArray(int* arr, int size) {
  for(int i=0; i<size;i++) {
   modifyValue(&arr[i]);
  }
}

void rer(int** ptr2, int** ptr1) {
  int* ii;
  ii = *ptr2;

  *ptr2 = *ptr1;
  *ptr1 = ii;
  **ptr1 *= **ptr2;
  **ptr2 += **ptr1;
} 

int main() {
  // int a =5, b=10, c=15;
  // int *arr[] = {&a, &b,&c};
  // cout << arr[1];

  // char arr[20];
  // int i;
  // for(i=0;i<10;i++) {
  //   *(arr + i) = 65 + i;
  //   *(arr + i) = '\0';
  //   cout << arr;

  // }
  //   cout << arr;

  // char* ptr;
  // char str[] = "abcdefg";
  // ptr = str;
  // ptr+= 5;
  // cout << ptr;

  // char st[] = "ABCD";
  // for (int i = 0; st[i] != '\0'; i++) {
  //   cout << st[i] << *(st) + i << *(i + st) << i[st] << endl;
  // }

  // int x = 5;
  // int* ptr = &x;

  // int y = 10;
  // int* ptr2 = &y;

  // int** ptr_ptr = &ptr;
  // int*** ptr_ptr_ptr = &ptr_ptr;

  // modifyValue(*ptr_ptr);
  // modifyValue(**ptr_ptr_ptr);
  // modifyValue(ptr2);

  // cout << "X: " << x << endl;
  // cout << "Y: " << y << endl;

  // int array[] = {1,2,3,4,5};
  // int* array_ptr = array;

  // modifyArray(array_ptr, 5);

  // cout << "Modified Array: ";
  // for(int i=0; i< 5;i++) {
  //   cout << array[i] << " ";
  // }
  // cout << endl;

  // int a = 32, *ptr = &a;
  // char ch = 'A', &cho = ch;

  // cho += a;
  // *ptr += ch;
  // cout << a << "," << ch << endl;

  // const int i = 20;
  // const int* ptr = &i;
  // int j = 15;
  // ptr = &i;
  // cout << i;

  // int num[5];
  // int* p;
  // p = num;
  // *p = 10;
  // p++;
  // *p = 20;
  // p = &num[2];
  // *p = 30;
  // p = num +3;
  // *p = 40;
  // p = num;
  // *(p+4) = 50;
  // for(int i = 0;i<5;i++) {
  //   cout << num[i] << ",";
  // }

  // int arr[] = {4,5,6,7};
  // cout << *arr;
  // int* p = (arr + 1);
  // cout << *arr + 10;

  // int a = 10;
  // int* ptr = &a;
  // cout << *ptr++;
  // cout << *ptr;

  // int a[] = {2,4,6,8,10};
  // int i,sum=0, *b=a+4;
  // for(i=0; i<5; i++) {
  //   sum = sum + (*b-i) - *(b-i);
  // }
  // cout << sum;

  // int var1 = 5,var2=10;
  // int* ptr1 = &var1, *ptr2 = &var2;
  // rer(&ptr1, &ptr2);
  // cout << var2 << " " << var1 << endl;

  int a[] = {10,20,30,40,50};
    int* p[] = {a, a+3, a+4, a+1, a+2};
    int** ptr = p;
    ptr++;
    cout << ptr-p<< **ptr;
    return 0;
}