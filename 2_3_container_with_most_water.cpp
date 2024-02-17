# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;
    int start = 0, end = n - 1;
    while (start < end) {
      maxWater = max(maxWater, (min(height[start], height[end]) * (end - start)));
      if (height[start] < height[end]) {
        start++;
      }
      else {
        end--;
      }
    }
    return maxWater;
  }
};

int main()
{
  Solution s;
  vector<int> height = { 1,8,6,2,5,4,8,3,7 };

  cout << s.maxArea(height) << endl;

  return 0;
}