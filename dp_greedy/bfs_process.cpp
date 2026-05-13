#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &x, int r, int c, int target_color) {
        int h = x.size();
        int w = x[0].size();

        vector<pair<int, int>> Q(h * w, {0, 0});
        vector<vector<int>> state(h, vector<int>(w, 0));

        int head = 0, tail = 1;
        Q[0] = {r, c};
        state[r][c] = 1;

        auto ans = x;
        int source_color = x[r][c];

        while (tail - head) {
            int cur_r = Q[head].first;
            int cur_c = Q[head].second;
            head++;

            for (int dir = 0; dir < 4; dir++) {
                int nr = cur_r + dx[dir];
                int nc = cur_c + dy[dir];

                if (nr < 0 || nc < 0 || h <= nr || w <= nc || x[nr][nc] != source_color) {
                    ans[cur_r][cur_c] = target_color;
                    continue;
                }

                if (state[nr][nc]) continue;

                Q[tail++] = {nr, nc};
                state[nr][nc] = 1;
            }
        }
        return ans;
    }
};

// 輔助函式：用來印出網格
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << "  ";
        }
        cout << "\n";
    }
    cout << "----------------\n";
}

int main() {
    Solution sol;
    
    // 建立 4x4 的測試地圖
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 1, 2},
        {1, 1, 1, 2},
        {2, 2, 2, 2}
    };

    cout << "【原始地圖 (Input)】\n";
    printGrid(grid);

    // 起點座標 (0,0)，目標顏色設為 3
    int start_r = 0, start_c = 0, target = 3;
    
    // 執行演算法
    vector<vector<int>> result = sol.colorBorder(grid, start_r, start_c, target);

    cout << "【著色後的地圖 (Output)】\n";
    printGrid(result);

    return 0;
}