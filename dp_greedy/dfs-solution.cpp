int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int cur_r, int cur_c, int source_color, vector<vector<int>> &x,
         vector<vector<int>> &state, vector<vector<int>> &ans,
         int target_color) {
  int h = x.size();
  int w = x[0].size();

  for (int dir = 0; dir < 4; dir++) {
    int nr = cur_r + dx[dir];
    int nc = cur_c + dy[dir];

    if (nr < 0 || nc < 0 || h <= nr || w <= nc || x[nr][nc] != source_color) {
      ans[cur_r][cur_c] = target_color;
      continue;
    }

    if (state[nr][nc]) {
      continue;
    }

    state[nr][nc] = 1;
    DFS(nr, nc, source_color, x, state, ans, target_color);
  }
}

class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &x, int r, int c,
                                  int target_color) {
    int h = x.size();
    int w = x[0].size();

    vector<vector<int>> state(h, vector<int>(w, 0));

    int source_color = x[r][c];

    state[r][c] = 1;
    vector<vector<int>> ans = x;
    DFS(r, c, source_color, x, state, ans, target_color);

    return ans;
  }
};
