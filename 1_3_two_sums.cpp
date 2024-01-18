# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    int n = nums.size(), complement;

    for (int i = 0; i < n; i++) {
      complement = target - nums[i];
      if (map.count(complement)) {
        return { map[complement], i };
      }
      map[nums[i]] = i;
    }

    return {};
  }
};

int main()
{
  Solution s;
  vector<int> nums = { 2,7,11,15 };
  int target = 9;

  vector<int> ans = s.twoSum(nums, target);
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}