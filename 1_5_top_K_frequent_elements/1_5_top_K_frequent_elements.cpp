# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int partition(vector<pair<int, int>>& pairs, int l, int h) {
    int i = l - 1;
    for (int j = l; j < h; j++) {
      if (pairs[j].first < pairs[h].first) {
        i++;
        swap(pairs[i], pairs[j]);
      }
    }
    swap(pairs[i + 1], pairs[h]);
    return i + 1;
  }

  vector<int> quickSelect(vector<pair<int, int>>& pairs, int l, int h, int k) {
    int j = partition(pairs, l, h);
    cout << "j = " << j << endl;
    if (j < (pairs.size() - k)) {
      return quickSelect(pairs, j + 1, h, k);
    }
    else if (j > (pairs.size() - k)) {
      return quickSelect(pairs, l, j - 1, k);
    }
    else {
      vector<int> ans;
      do
      {
        ans.push_back(pairs[j].second);
        j++;
      } while (j < pairs.size());
      return ans;
    }
  }

public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (auto num : nums) {
      map[num]++;
    }
    vector<int> ans;

    vector<pair<int, int>> pairs;
    for (auto i : map) {
      pairs.push_back({ i.second, i.first });
    }

    return quickSelect(pairs, 0, pairs.size() - 1, k);
  }
};

int main()
{
  vector<int> nums = { 5,5,5,6,6,7 }; // {{1,3}, {2,2}, {3,1}}
  int k = 2;
  Solution s;
  vector<int> ans = s.topKFrequent(nums, k);
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl << "size = " << ans.size() << endl;
  return 0;
}