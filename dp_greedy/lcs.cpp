class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> t(2, vector<int>(m, 0));

    int cur = 0, pre = 1;

    for (int c = 0; c < n; c++) {
      t[cur][0] = text2[c] == text1[0] ? 1 : t[pre][0];

      for (int r = 1; r < m; r++) {
        if (text1[r] == text2[c]) {
          t[cur][r] = t[pre][r - 1] + 1;
        } else {
          t[cur][r] = max(t[cur][r - 1], t[pre][r]);
        }
      }

      cur ^= 1, pre ^= 1;
    }

    return t[pre][m - 1];
  }
};
