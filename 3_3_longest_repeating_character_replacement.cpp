# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int freq[26], l = 0, n = s.length(), mostFreq = 0, maxLen = 0;
    for (int r = 0; r < n; r++) {
      freq[s[r] - 'A']++;
      mostFreq = max(mostFreq, freq[s[r] - 'A']);

      int toBeChanged = (r - l + 1) - mostFreq;
      if (toBeChanged > k) {
        freq[s[l] - 'A']--;
        l++;
      }

      maxLen = max(maxLen, (r - l + 1));
    }
    return maxLen;
  }
};

int main()
{
  Solution s;
  string str = "ABAB";
  cout << s.characterReplacement(str, 2) << endl;
  return 0;
}