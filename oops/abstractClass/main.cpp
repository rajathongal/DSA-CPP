#include "Bird.h"
#include <iostream>
using namespace std;

void birdDoesSomething(Bird *&bird) {
  bird->eat();
  bird->fly();
}

int main() {
  // You need to call sparrow using Bird interface
  Bird *bird = new Sparrow();
  birdDoesSomething(bird);


  bird = new Eagle();
  birdDoesSomething(bird);


  // THis would be inaccessible
  // Sparrow *sp = new Sparrow();
  // sp->eat();

  // Bird *b2 = new Bird(); 
  // You cannot change or create a new object on the interface class
  return 0;
}