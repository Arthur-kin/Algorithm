int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &x, int r, int c,
                                  int target_color) {
    int h = x.size(); //high
    int w = x[0].size(); //width

    vector<pair<int, int>> Q(h * w, {0, 0}); //h*w大小的queue
    vector<vector<int>> state(h, vector<int>(w, 0));// whether cross 也是h*w的二維陣列

    int head = 0;
    int tail = 1;
    Q[0] = {r, c};//r c is the source point
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
          ans[cur_r][cur_c] = target_color;// 滿足其一，代表自己是邊界點，在答案圖上塗色
          continue;// 既然此方向遇到邊界或異色，就不用把這個鄰居放進 Queue 了
        }

        if (state[nr][nc]) {// 如果已經探索過了，就不需要再放進 queue 了 0代表沒探索過，1代表探索過了 
          continue;
        }
        // 走到這，說明鄰居是「未探索過」且「同色」的點，它是連通元件的內部，要繼續擴展 BFS
        Q[tail++] = {nr, nc};// 將鄰居放入 Queue 尾端（Push）
        state[nr][nc] = 1;// 標記鄰居已拜訪
      }
    }

    return ans;
  }
};

 