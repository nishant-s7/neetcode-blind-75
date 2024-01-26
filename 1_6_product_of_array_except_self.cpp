# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }
    int next = 1;
    for (int i = n - 2; i >= 0; i--) {
      next *= nums[i + 1];
      ans[i] *= next;
    }
    return ans;
  }
};

int main()
{
  vector<int> nums = { 1,2,3,4 };
  Solution s;

  vector<int> ans = s.productExceptSelf(nums);

  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}