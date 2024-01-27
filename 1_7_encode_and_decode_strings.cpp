# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string encode(vector<string>& strs) {
    string encoded = "";
    for (auto s : strs) {
      for (auto c : s) {
        encoded += to_string(int(c));
        encoded += "+";
      }
      encoded += ',';
    }
    return encoded;
  }

  vector<string> decode(string s) {
    vector<string> decoded;
    int ascii = 0;
    string word = "";
    bool negativeFlag = false;
    for (auto c : s) {
      if (c == '+') {
        if (negativeFlag) {
          ascii *= -1;
        }
        word += char(ascii);
        ascii = 0;
      }
      else if (c == ',') {
        decoded.push_back(word);
        word = "";
      }
      else if (c == '-') {
        negativeFlag = true;
      }
      else {
        ascii = (ascii * 10) + int(c - '0');
      }
    }
    return decoded;
  }
};

int main()
{
  vector<string> strs = { "EmojiTest 😊","🌟✨🌟✨🌟","🤖👽🤖👽" };
  Solution s;

  string enc = s.encode(strs);
  cout << "Encoded : " << enc << endl;

  vector<string> dec = s.decode(enc);
  cout << "Decoded : ";
  for (auto i : dec) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}