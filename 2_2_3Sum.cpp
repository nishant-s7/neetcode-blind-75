# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int start = i + 1, end = n - 1;
      while (start < end) {
        int sum = nums[i] + nums[start] + nums[end];
        if (sum > 0) {
          end--;
        }
        else if (sum < 0) {
          start++;
        }
        else {
          ans.push_back({ nums[i], nums[start], nums[end] });
          start++;
          end--;
          while ((start < end) && (nums[start - 1] == nums[start])) start++;
          while ((start < end) && (nums[end + 1] == nums[end])) end--;
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = { -1,0,1,2,-1,-4 };

  vector<vector<int>> ans = s.threeSum(nums);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}