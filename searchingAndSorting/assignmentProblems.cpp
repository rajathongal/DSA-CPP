#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;

// Leetcode 532 K diff pairs

// using two pointer
void kDiffPairsUsingTwoPointer() {
  vector< int > nums;
  // int k = 2;
  // nums.push_back(3);
  // nums.push_back(1);
  // nums.push_back(4);
  // nums.push_back(1);
  // nums.push_back(5);

  // int k = 0;
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);

  int k = 1;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);

  // sort the vector
  sort(nums.begin(), nums.end());

  int i = 0;
  int j = 1;
  int size = nums.size();
  set< pair< int, int > > answer;

  while (j < size) {
    int difference = nums[j] - nums[i];

    if (difference == k) {
      answer.insert(make_pair(nums[i], nums[j]));
      i++;
      j++;
    } else if (difference > k) {
      i++;
    } else
      j++;

    if (i == j)
      j++;
  }

  cout << "Unique K-Diff pair count by two pointer method is: " << answer.size()
       << endl;
}

// using binary search
int binarySearch(vector< int > &nums, int start, int end, int target) {

  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (nums[mid] == target) {
      return mid;
    } else if (target > nums[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }

  return -1;
}

void kDiffPairsUsingBinarySearch() {
  vector< int > nums;
  int k = 2;
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(1);
  nums.push_back(5);

  sort(nums.begin(), nums.end());
  set< pair< int, int > > answer;
  for (int i = 0; i < nums.size(); i++) {
    if (binarySearch(nums, i + 1, nums.size() - 1, abs(nums[i] + k)) != -1) {
      answer.insert(make_pair(nums[i], nums[i] + k));
    }
  }

  cout << "K-Diff Pairs count using binary search is: " << answer.size()
       << endl;
}

// leetcode 658
void findKClosestElementsUsingTwoPointers() {
  vector< int > nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);

  int k = 4;
  int x = -1;

  int low = 0;
  int high = nums.size() - 1;

  while (high - low >= k) {
    if (x - nums[low] > nums[high] - x) {
      low++;
    } else {
      high--;
    }
  }

  for (int i = low; i <= high; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
}

// k closest element using Binary Search
int lowerBound(vector< int > &nums, int target) {
  int start = 0, end = nums.size() - 1;
  int ans = end; // overflow

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (nums[mid] >= target) {
      ans = mid;
      end = mid - 1;
    } else if (target > nums[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

void findKClosestElementsUsingBinarySearch() {
  vector< int > nums;
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(8);
  nums.push_back(10);

  int k = 2;
  int x = 15;

  int high = lowerBound(nums, x);
  int low = high - 1;

  while (k--) {
    if (low < 0) {
      high++;
    } else if (high >= nums.size()) {
      low--;
    } else if (x - nums[low] > nums[high] - x) {
      high++;
    } else {
      low--;
    }
  }

  for (int i = low + 1; i < high; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
}

void exponentialSearch() {
  vector< int > nums;
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(11);
  nums.push_back(13);
  nums.push_back(14);
  nums.push_back(15);
  nums.push_back(56);
  nums.push_back(70);

  int target = 13;
  int size = nums.size();
  int ans = -1;

  if (nums[0] == target) {
    ans = 0;
  }

  int i = 1;

  while (i < size && nums[i] <= target) {
    i *= 2; // or i = i * 2 or i = i<< 1
  }

  ans = binarySearch(nums, i / 2, min(i, size - 1), target);

  cout << "The target is at index: " << ans << endl;
}

// Book Allocation problem

// Allocate Minimum Number of Pages from N books to M students

// Given that there are N books and M students. Also given are the number of
// pages in each book in ascending order. The task is to assign books in such a
// way that the maximum number of pages assigned to a student is minimum, with
// the condition that every student is assigned to read some consecutive books.

// Print that minimum number of pages. Example : Input: N = 4, pages[] = {12,
// 34, 67, 90}, M = 2 Output: 113 Explanation: There are 2 number of students.
// Books can be distributed in following combinations: [12] and [34, 67, 90] ->
// Max number of pages is allocated to student ‘2’ with 34 + 67 + 90 = 191 pages
// [12, 34] and [67, 90] -> Max number of pages is allocated to student ‘2’ with
// 67 + 90 = 157 pages [12, 34, 67] and [90] -> Max number of pages is allocated
// to student ‘1’ with 12 + 34 + 67 = 113 pages Of the 3 cases, Option 3 has the
// minimum pages = 113.

// Naive Approach: The simplest approach to solve this
// problem is to find all permutations to distribute N books among M students,
// and return the minimum page allocation among them.

// Efficient Approach:
// Another way to solve this problem is to use Binary Search, based on this
// idea: Case 1: When no valid answer exists. If the number of students is
// greater than the number of books (i.e, M > N), In this case at least 1
// student will be left to which no book has been assigned. Case 2: When a valid
// answer exists.

// The maximum possible answer could be when there is only one
// student. So, all the book will be assigned to him and the result would be the
// sum of pages of all the books.

// The minimum possible answer could be when
// number of student is equal to the number of book (i.e, M == N) , In this case
// all the students will get at most one book. So, the result would be the
// maximum number of pages among them (i.e, maximum(pages[])). Hence, we can
// apply binary search in this given range and each time we can consider the mid
// value as the maximum limit of pages one can get. And check for the limit if
// answer is valid then update the limit accordingly.

bool isPossibleAnswer(int APageInBooks[], int NBooks, int MStudents, int solOrMid) {
  // we need to store the total number of books or pages allocated to a
  // particular student
  //  we do that with below variable and reset for next student
  int currentAllocationPageSum = 0;

  // we need a counter to store the number of student for whom the book are
  // allocated we increment the counter once the student has sufficient books or
  // pages
  int studentCounter = 1;

  // iterate through all books
  for (int i = 0; i < NBooks; i++) {

    // if the current (i-th) book's page number itself is greater than
    // solution/mid then return current mid is not the solution
    if (APageInBooks[i] > solOrMid) {
      return false;
    }

    // if the current (i-th) book's page number when added to sum of previously
    // allocated pages sum exceeds the solution / mid
    if (currentAllocationPageSum + APageInBooks[i] > solOrMid) {
      // increase student counter to start allocating to the next student
      studentCounter++;

      // reset the sum to collect the number of pages to be allocated to the
      // next student
      currentAllocationPageSum = APageInBooks[i];

      // check if increment student counter is exceeding the total students
      // if false then total of students have already been allocated a book
      // so there are still a few books left but no students
      // so return false
      if (studentCounter > MStudents) {
        return false;
      }
    } else {

      // if the current (i-th) book's page number when added to sum of
      // previously allocated pages sum
      // does not exceed the solution / mid
      // then the current student can take another book or pages so 
      // add the current pages to the sum
      currentAllocationPageSum += APageInBooks[i];
    }
  }


  // when the program reaches here then all students have been allocated sufficient number of books 
  // and there are not any leftovers and there exists a possible solution
  return true;
}

void bookPartition() {
  int NBooks = 4;
  int APageInBooks[] = {12, 34, 67, 90};
  int MStudents = 2;

  // problem states every allocation should contagious
  // meaning for every student shoud get a book and if there are insufficent
  // books then return -1 to denote there is no possible solution
  if (MStudents > NBooks) {
    cout << "Insufficient Books available" << endl;
    return;
  }

  int start = 0;
  int ans = -1;
  // accumulate gets the total sum of array provided
  // we have to find in search space so end would be the total sum of all pages
  // of all books
  int end = accumulate(APageInBooks, APageInBooks + NBooks, 0);

  while (start <= end) {
    // we will find mid from 0 to totalSum of all pages in all books and move
    // ahead from there
    int mid = (start + end) >> 1; // equivalent to start + end / 2

    // cout << end << "  " << mid << endl; // to check the movement of end and
    // mid througout the program

    // if there is a possible answer store the answer and try to minimize the
    // answer for best possible outcome move left to minimize
    if (isPossibleAnswer(APageInBooks, NBooks, MStudents, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      // if there is no possible answer in current search space then move right
      // to expand and search in more number of pages
      start = mid + 1;
    }
  }

  cout << "The answer is: " << ans << endl;
}

int main() {
  // kDiffPairsUsingTwoPointer();
  // kDiffPairsUsingBinarySearch();
  // findKClosestElementsUsingTwoPointers();
  // findKClosestElementsUsingBinarySearch();
  // exponentialSearch();
  bookPartition();
  return 0;
}