# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int count[26] = { 0 };
    int m = s.length();
    int n = t.length();
    if (m != n) {
      return false;
    }
    for (int i = 0; i < m; i++) {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution sol;
  string s = "anagram";
  string t = "nagaram";
  cout << sol.isAnagram(s, t) << endl;

  return 0;
}