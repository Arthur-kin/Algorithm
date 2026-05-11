class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> t(2, vector<int>(m, 0));

    int cur = 0, pre = 1;

    for (int c = 0; c < n; c++) {
      t[cur][0] = text2[c] == text1[0] ? 1 : t[pre][0];//確認 text2[c] 是否和 text1[0] 匹配，匹配的話就把 t[cur][0] 設為 1，否則繼續沿用 t[pre][0] 的結果 

      for (int r = 1; r < m; r++) {//固定 text2[c]，從 text1[1] 開始往上
        if (text1[r] == text2[c]) {
          t[cur][r] = t[pre][r - 1] + 1;
        } else {
          t[cur][r] = max(t[cur][r - 1], t[pre][r]); // 這裡的 t[cur][r - 1] 是因為 text2[c] 不匹配，所以只能繼續沿用 text1[r - 1] 的結果
        }
      }

      cur ^= 1, pre ^= 1;
    }

    return t[pre][m - 1];
  }
};
