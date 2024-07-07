#include <iostream>
#include <vector>
using namespace std;

// Backtracking
// explore all possible soln
// once explored soln will not be explored again

// Permutation of a string
// Print all perma of a string
// abc -> abc, acb, bac, bca, cab, cba
// ab -> ab, ba
// n! soln available
void printSTRPerma(string &str, int index) {
  if (index >= str.length()) {
    cout << str << " ";

    return;
  }

  for (int j = index; j < str.length(); j++) {
    swap(str[index], str[j]);
    // RE
    printSTRPerma(str, index + 1);
    // backtracking -> do something after recursion ex bring back original state
    // of str
    swap(str[index], str[j]);
  }
}

// Rat in a maze

bool isSafeOrValidPath(vector< vector< int > > &maze, int srcX, int srcY,
                       int newX, int newY, int rows, int cols,
                       vector< vector< bool > > &visited) {
  if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
      maze[newX][newY] == 1 && visited[newX][newY] == false) {
    return true;
  }
  return false;
}

void ratInAMaze(vector< vector< int > > &maze, int rows, int cols, int srcX,
                int srcY, string &output, vector< vector< bool > > &visited) {
  // base cases

  // 1. src position is closed that means rat cannot move
  if (maze[0][0] == 0) {
    visited[0][0] = true;
    cout << "No PathExists" << endl;
    return;
  }
  // 2. destination coordinates row-1, col-1
  if (srcX == rows - 1 && srcY == cols - 1) {
    cout << output << endl;
    return;
  }

  // processing

  // up (row-1,col)
  // consider out of bound case for up
  // check is Safe
  int newXUp = srcX - 1;
  int newYUp = srcY;
  if (isSafeOrValidPath(maze, srcX, srcY, newXUp, newYUp, rows, cols,
                        visited)) {
    // mark visited
    visited[newXUp][newYUp] = true;

    // call RE
    output.push_back('U');
    ratInAMaze(maze, rows, cols, newXUp, newYUp, output, visited);
    output.pop_back();

    // unmark visited to explore other possibilities / backtracking
    visited[newXUp][newYUp] = false;
  }

  // right (row,col + 1)
  // consider out of bound case for right
  // check is Safe
  int newXRight = srcX;
  int newYRight = srcY + 1;
  if (isSafeOrValidPath(maze, srcX, srcY, newXRight, newYRight, rows, cols,
                        visited)) {
    // mark visited
    visited[newXRight][newYRight] = true;

    // call RE
    output.push_back('R');
    ratInAMaze(maze, rows, cols, newXRight, newYRight, output , visited);
    output.pop_back();

    // unmark visited to explore other possibilities / backtracking
    visited[newXRight][newYRight] = false;
  }

  // down (row+1,col)
  // consider out of bound case for down
  // check is Safe
  int newXDown = srcX + 1;
  int newYDown = srcY;
  if (isSafeOrValidPath(maze, srcX, srcY, newXDown, newYDown, rows, cols,
                        visited)) {
    // mark visited
    visited[newXDown][newYDown] = true;

    // call RE
    output.push_back('D');
    ratInAMaze(maze, rows, cols, newXDown, newYDown, output, visited);
    output.pop_back();

    // unmark visited to explore other possibilities / backtracking
    visited[newXDown][newYDown] = false;
  }

  // left (row,col-1)
  // consider out of bound case for left
  // check is Safe
  int newXLeft = srcX;
  int newYLeft = srcY - 1;
  if (isSafeOrValidPath(maze, srcX, srcY, newXLeft, newYLeft, rows, cols,
                        visited)) {
    // mark visited
    visited[newXLeft][newYLeft] = true;

    // call RE
    output.push_back('L');
    ratInAMaze(maze, rows, cols, newXLeft, newYLeft, output , visited);
    output.pop_back();

    // unmark visited to explore other possibilities / backtracking
    visited[newXLeft][newYLeft] = false;
  }
}

int main() {
  // string str1 = "abc";
  // printSTRPerma(str1, 0);

  vector< vector< int > > maze = {
      {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 1, 0}, {1, 1, 1, 1}};
  string output = "";
  int rows = maze.size();
  int cols = maze[0].size();
  int srcX = 0;
  int srcY = 0;
  vector< vector< bool > > visited(rows, vector< bool >(cols, false));
  visited[srcX][srcY] = true;
  ratInAMaze(maze, rows, cols, srcX, srcY, output, visited);
  return 0;
}