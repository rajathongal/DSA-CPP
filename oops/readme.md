# Behaviour of space in classes

## Empty Classes

```c++
class EmptyC {
  // This is an empty class to demonstrate space occupied by classes
};
```

Empty classes occupy only 1 byte of space

## Classes with variables and functions declared in it

```c++
class Student {
  int id;
  int age;
  bool isPresent;

  void study() { cout << "Studying" << endl; };
  void bunk() { cout << "Bunking" << endl; };
  void sleep() { cout << "Sleeping" << endl; };
  void writeAssignment() { cout << "Writing Assignments" << endl; };
};

int main() {
  cout << sizeof(Student) << endl;
}
```

Here the size of ints is considered and the answer would be surprisingly 12bytes

- Functions are allotted space only when they are called.
- Ints are of 4 bytes -> `8 bytes for 2 ints`.
- Bool is of 1 byte -> `1 byte for one bool variable`.
- The final answer should have been `9 bytes`.
- But `the answer would be 12 bytes`.
- Because ->
- Considering Computer Architecture and CPU, CPU occupies 4 to 8 bytes in memory bus minimum,
depending upon the Architecture, it will be easy to do operations on fixed size than random size of 1 byte or 2 byte `CPU will add padding size` for the `remaing space in 4 or 8 byte` to process operations fast and obviously `memory is wasted` `but the speed of execution is increased`.
- This happens in newer computers and compilers and old computers will return `9 bytes`.
- Compiler might pick the `chunks in most repeated biggest data type` provided in the code block.
- Or you can say align sum of datatypes in the boundary of biggest datatype in codeblock.
- Try

```c++
class Student {
  double id;
  double age;
  bool isPresent;

  void study() { cout << "Studying" << endl; };
  void bunk() { cout << "Bunking" << endl; };
  void sleep() { cout << "Sleeping" << endl; };
  void writeAssignment() { cout << "Writing Assignments" << endl; };
};

int main() {
  cout << sizeof(Student) << endl;
}
```

`The answer will be 8 + 8 + 8 (instead of bool's 1byte) = 24bytes`

- `Important` -> The compiler will bring down the size for lesser size datatype variable to the nearest multiple of biggest datatype.

For example

```c++
class Student {
  double id;
  double age;
  char initials;
  bool isPresent;

  void study() { cout << "Studying" << endl; };
  void bunk() { cout << "Bunking" << endl; };
  void sleep() { cout << "Sleeping" << endl; };
  void writeAssignment() { cout << "Writing Assignments" << endl; };
};

int main() {
  cout << sizeof(Student) << endl;
}
```

The answer will be 24 bytes -> 2 double vars will occupy 8 bytes and now we have char and bool of 1 byte each left, the compiler will allocate 4 bytes each or you can say 4*4=8 (or double's size).
