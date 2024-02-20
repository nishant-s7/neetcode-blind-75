# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n == 0) return 0;
    int maxLength = 1, left = 0;
    int positions[128];
    for (int i = 0; i < 128; i++) {
      positions[i] = -1;
    }

    for (int right = 0; right < n; right++) {
      if (positions[int(s[right])] >= left) {
        left = positions[int(s[right])] + 1;
      }
      positions[int(s[right])] = right;
      maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
  }
};

int main()
{
  Solution s;
  string str = "abcabcbb";
  cout << s.lengthOfLongestSubstring(str) << endl;

  return 0;
}