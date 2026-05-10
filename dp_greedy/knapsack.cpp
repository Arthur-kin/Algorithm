class Solution {
public:
  int change(int total, vector<int> &coins) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(total + 1, -1));

    return GetAns(coins, total, n - 1, dp);
  }

  int GetAns(vector<int> &coins, int total, int idx, vector<vector<int>> &dp) {
    if (!total) {
      return 1;
    }

    if (dp[idx][total] >= 0) {
      return dp[idx][total];
    }

    int ans = idx ? GetAns(coins, total, idx - 1, dp) : 0;
    if (total >= coins[idx]) {
      ans += GetAns(coins, total - coins[idx], idx, dp);
    }

    dp[idx][total] = ans;
    return ans;
  }
};
