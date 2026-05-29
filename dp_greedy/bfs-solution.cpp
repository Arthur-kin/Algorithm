int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &x, int r, int c,
                                  int target_color) {
    int h = x.size(); //high
    int w = x[0].size(); //width

    vector<pair<int, int>> Q(h * w, {0, 0}); //h*w大小的queue
    vector<vector<int>> state(h, vector<int>(w, 0));// whether cross

    int head = 0;
    int tail = 1;
    Q[0] = {r, c};
    state[r][c] = 1;

    auto ans = x; //answer_pic
    int source_color = x[r][c];//r-c color

    while (tail - head) {//抵達tail的位置
      int cur_r = Q[head].first;
      int cur_c = Q[head].second;

      head++;//目前進度在哪 慢慢追趕到tail

      for (int dir = 0; dir < 4; dir++) {// 上下左右探索
        int nr = cur_r + dx[dir];
        int nc = cur_c + dy[dir];

        if (nr < 0 || nc < 0 || h <= nr || w <= nc ||
            x[nr][nc] != source_color) {
          ans[cur_r][cur_c] = target_color;// change myself
          continue;
        }

        if (state[nr][nc]) {
          continue;
        }

        Q[tail++] = {nr, nc};//這邊tail是為了先把需要探索的都記錄下來
        state[nr][nc] = 1;
      }
    }

    return ans;
  }
};
