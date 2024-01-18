# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (auto str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      map[key].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto pair : map) {
      ans.push_back(pair.second);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector <string> strs = { "eat","tea","tan","ate","nat","bat" };

  vector<vector<string>> ans = s.groupAnagrams(strs);

  for (auto i : ans) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}