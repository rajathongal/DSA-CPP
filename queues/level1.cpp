#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue< int > q;

  q.push(1);
  q.push(2);

  cout << "Size of Queue: " << q.size() << endl;
  cout << "Is Queue Empty ? " << q.empty() << endl;

  q.pop();
  q.pop();
  cout << "Is Queue Empty ? " << q.empty() << endl;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  cout << "Queue front: " << q.front() << " back: " << q.back() << endl;
}