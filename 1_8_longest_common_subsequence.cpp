# include <iostream>
# include <bits/stdc++.h>
using namespace std;

// set : follows binary search tree implementation

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int lcs = 0;
    unordered_set<int> numSet;
    for (auto num : nums) {
      numSet.insert(num);
    }

    for (auto num : numSet) {
      if (numSet.find(num - 1) == numSet.end()) {
        int len = 1;
        int seq = num;
        while (numSet.find(seq + 1) != numSet.end()) {
          len++;
          seq++;
        }
        lcs = max(lcs, len);
      }
    }

    return lcs;
  }
};

int main()
{
  vector<int> nums = { 100,4,200,1,3,2 };
  Solution s;

  cout << s.longestConsecutive(nums) << endl;

  return 0;
}