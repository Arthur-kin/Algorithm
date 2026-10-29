class Solution {
public:
  int change(int total, vector<int> &coins) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(total + 1, -1));

    return GetAns(coins, total, n - 1, dp);
  }

  int GetAns(vector<int> &coins, int total, int idx, vector<vector<int>> &dp) {
    if (!total) {// 達陣條件 !total，表示剛好扣完，找到一種組合
      return 1;
    }

    if (dp[idx][total] >= 0) {// 快取命中
      return dp[idx][total];
    }
    // ans是用來存放分支 A 和分支 B 的結果，最後再寫入快取表 dp[idx][total]。
    int ans = idx ? GetAns(coins, total, idx - 1, dp) : 0;// 分支 A：不使用這個硬幣
    //same int ans;if (idx != 0) {ans = GetAns(coins, total, idx - 1, dp);} else {ans = 0;}

    if (total >= coins[idx]) {
      ans += GetAns(coins, total - coins[idx], idx, dp);// 分支 B：使用這個硬幣
    }

    dp[idx][total] = ans;// 寫入快取
    return ans;
  }
};
