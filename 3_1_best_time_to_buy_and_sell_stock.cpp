# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int max_profit = 0;
    int buy = prices[0];

    for (int i = 1; i < n; i++) {
      max_profit = max(max_profit, prices[i] - buy);
      buy = min(buy, prices[i]);
    }

    return max_profit;
  }
};

int main()
{
  Solution s;
  vector<int> prices = { 7,6,4,3,2 };

  cout << s.maxProfit(prices) << endl;

  return 0;
}