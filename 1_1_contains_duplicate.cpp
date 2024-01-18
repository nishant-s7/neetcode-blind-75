# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    bool dup = false;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] == nums[i]) {
        dup = true;
        break;
      }
    }
    return dup;
  }
};

int main()
{
  Solution s;
  vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };

  cout << s.containsDuplicate(nums) << endl;

  return 0;
}