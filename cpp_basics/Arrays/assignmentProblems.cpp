#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void FindPivotIndex() {}

void FindPivotIndexBruteForce() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(7);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(5);
  nums.push_back(6);

  for (int i = 0; i < nums.size(); ++i) {
    int lsum = 0;
    int rsum = 0;

    // lsum
    for (int j = 0; j < i; j++)
      lsum += nums[j];

    // rsum
    for (int j = i + 1; j < nums.size(); ++j)
      rsum += nums[j];

    if (lsum == rsum)
      cout << "Pivot Index is " << i << endl;
  }
}

// for pivot index below is the tried solution but doesnot satisfy all the cases
//   vector<int> nums;
//   // nums.push_back(1);
//   // nums.push_back(7);
//   // nums.push_back(3);
//   // nums.push_back(6);
//   // nums.push_back(5);
//   // nums.push_back(6);

//   // nums.push_back(1);
//   // nums.push_back(2);
//   // nums.push_back(3);

//   nums.push_back(2);
//   nums.push_back(1);
//   nums.push_back(-1);

//   int left = 0;
//   int right = nums.size() - 1;
//   int leftSum = 0;
//   int rightSum = 0;
//   int index = 0;

//   while (index <= right) {
//     // handling left Sum
//     if (left == 0) {
//       left++;
//     } else {
//       leftSum += nums[left - 1];
//       left++;
//     }

//     // handling right Sum
//     if (right == nums.size() - 1) {
//       rightSum += nums[right];
//       right--;
//     } else if (!(right - 1 == left || right == left || index == right ||
//                  right < index)) {
//       rightSum += nums[right];
//       right--;
//     }

//     index++;
//     if (rightSum == leftSum) {
//       cout << left << " " << right << " " << index << " " << rightSum << " "
//            << leftSum << endl;
//       if (index == 0) {
//         cout << "Pivot Index is: " << index << endl;

//       } else {
//         cout << "Pivot Index is: " << index - 1 << endl;
//       }
//       return;
//     }
//   }

//   cout << left << " " << right << " " << index << " " << rightSum << " "
//        << leftSum << endl;

//   cout << "Pivot Index is: " << -1 << endl;

int main() {
  FindPivotIndex();
  FindPivotIndexBruteForce();
  return 0;
}