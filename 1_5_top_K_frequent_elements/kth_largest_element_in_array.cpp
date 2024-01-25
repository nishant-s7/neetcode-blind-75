# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Quick Select
  int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, k, 0, nums.size() - 1);
  }

  // Sorting
  int findKthLargest1(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }

  // Heap
  int findKthLargest2(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (auto num : nums) {
      pq.push(num);
    }
    while (--k) {
      pq.pop();
    }
    return pq.top();
  }

private:
  int partition(vector<int>& nums, int l, int h) {
    int pivot = rand() % (h - l + 1) + l;
    swap(nums[pivot], nums[h]);
    int i = l - 1;
    for (int j = l; j < h; j++) {
      if (nums[j] < nums[h]) {
        i++;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[h], nums[i + 1]);
    return i + 1;
  }

  int quickSelect(vector<int>& nums, int k, int l, int h) {
    int j = partition(nums, l, h);
    cout << j << " ";
    if (j < (nums.size() - k)) {
      return quickSelect(nums, k, j + 1, h);
    }
    else if (j > (nums.size() - k)) {
      return quickSelect(nums, k, l, j - 1);
    }
    else {
      return nums[j];
    }
  }
};

int main()
{
  vector<int> nums = { 3,2,1,5,6,4 };
  int k = 2;
  Solution s;

  cout << s.findKthLargest2(nums, k) << endl;

  return 0;
}