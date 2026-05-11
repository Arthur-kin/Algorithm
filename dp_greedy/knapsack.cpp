class Solution {
public:
  int change(int total, vector<int> &coins) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(total + 1, -1));

    return GetAns(coins, total, n - 1, dp);
  }

  int GetAns(vector<int> &coins, int total, int idx, vector<vector<int>> &dp) {
    if (!total) {// 達陣條件
      return 1;
    }

    if (dp[idx][total] >= 0) {// 快取命中
      return dp[idx][total];
    }

    int ans = idx ? GetAns(coins, total, idx - 1, dp) : 0;// 分支 A：不使用這個硬幣
    if (total >= coins[idx]) {
      ans += GetAns(coins, total - coins[idx], idx, dp);// 分支 B：使用這個硬幣
    }

    dp[idx][total] = ans;// 寫入快取
    return ans;
  }
};
