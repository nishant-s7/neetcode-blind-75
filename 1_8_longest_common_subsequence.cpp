# include <iostream>
# include <bits/stdc++.h>
using namespace std;

// set : follows binary search tree implementation

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int lcs = 0;
    unordered_set<int> numSet;
    for (auto num : nums) {
      numSet.insert(num);
    }

    for (auto num : nums) {
      if (numSet.count(num - 1) == 0) {
        int len = 1;
        int seq = num + 1;
        while (numSet.count(seq) == 1) {
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