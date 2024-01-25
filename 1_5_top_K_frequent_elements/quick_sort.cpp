# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Sort {  // 3 7 6 5 8 2 4 5
public:
  void quickSort(vector<int>& nums, int l, int h) {
    if (l < h) {
      int j = partition(nums, l, h);
      quickSort(nums, l, j - 1);
      quickSort(nums, j + 1, h);
    }
  }
private:
  int partition(vector<int>& nums, int l, int h) {
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
};

int main() {
  Sort s;
  vector<int> nums = { 3, 7, 6, 5, 1, 2 };

  s.quickSort(nums, 0, nums.size() - 1);

  cout << "Sorted : ";
  for (auto num : nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

// int partition(vector<int>& nums, int l, int h) {
  //   int pivot = h;
  //   int i = l, j = h - 1;
  //   while (i <= j) {
  //     while (i <= j && nums[i] <= nums[pivot]) {
  //       i++;
  //     }
  //     while (i <= j && nums[j] > nums[pivot]) {
  //       j--;
  //     }
  //     if (i < j) {
  //       swap(nums[j], nums[i]);
  //       i++;
  //       j--;
  //     }
  //   }
  //   swap(nums[i], nums[pivot]);
  //   return i;
  // }