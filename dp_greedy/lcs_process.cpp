#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // 宣告 2 列的滾動陣列
        vector<vector<int>> t(2, vector<int>(m, 0));
        int cur = 0, pre = 1;

        cout << "=== 初始狀態 ===" << endl;
        printState(t, text1, cur, pre);

        // 開始比對
        for (int c = 0; c < n; c++) {
            cout << "\n=== 第 " << c + 1 << " 輪：處理 text2[" << c << "] = '" << text2[c] << "' ===" << endl;

            // 處理第 0 格 (邊界)
            t[cur][0] = text2[c] == text1[0] ? 1 : t[pre][0];

            // 處理後續格子
            for (int r = 1; r < m; r++) {
                if (text1[r] == text2[c]) {
                    t[cur][r] = t[pre][r - 1] + 1;
                } else {
                    t[cur][r] = max(t[cur][r - 1], t[pre][r]);
                }
            }

            // 【重點】在交換之前，印出剛寫完的陣列長相
            printState(t, text1, cur, pre);

            // 交換新舊指標 (開關切換)
            cur ^= 1, pre ^= 1;
        }

        cout << "\n=== 最終結果 ===" << endl;
        // 注意：因為最後一輪結束時多執行了一次切換，所以答案在 pre 身上
        cout << "回傳 t[pre][" << m - 1 << "] (也就是 t[" << pre << "][" << m - 1 << "]) = " << t[pre][m - 1] << endl;

        return t[pre][m - 1];
    }

private:
    // 輔助函式：用來印出目前的陣列狀態與指標位置
    void printState(const vector<vector<int>>& t, const string& text1, int cur, int pre) {
        int m = text1.size();
        
        // 印出 text1 的字元當作表格標題
        cout << "       字元: ";
        for (char ch : text1) cout << " '" << ch << "' ";
        cout << "\n       索引: ";
        for (int i = 0; i < m; ++i) cout << " [" << i << "] ";
        cout << "\n----------------------------------------\n";

        // 印出 t[0] 這條線
        if (cur == 0) cout << "cur -> t[0] |";
        else          cout << "pre -> t[0] |";
        for (int i = 0; i < m; ++i) cout << "  " << t[0][i] << " |";
        cout << (cur == 0 ? " (剛剛寫入這條)" : " (作為參考資料)") << "\n";

        // 印出 t[1] 這條線
        if (cur == 1) cout << "cur -> t[1] |";
        else          cout << "pre -> t[1] |";
        for (int i = 0; i < m; ++i) cout << "  " << t[1][i] << " |";
        cout << (cur == 1 ? " (剛剛寫入這條)" : " (作為參考資料)") << "\n";
    }
};

int main() {
    Solution sol;
    
    // 你可以隨意修改這兩個字串來觀察變化
    string text1 = "abcd";
    string text2 = "cda";
    
    cout << "目標：尋找 text1 (\"" << text1 << "\") 與 text2 (\"" << text2 << "\") 的最長公共子序列\n" << endl;
    
    sol.longestCommonSubsequence(text1, text2);
    
    return 0;
}
