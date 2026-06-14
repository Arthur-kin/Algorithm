 #include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int change(int total, vector<int> &coins) {
        int n = coins.size();
        // 初始化全部為 -1 的 DP 快取表
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));

        cout << "=== 開始尋找找零組合 ===" << endl;
        cout << "可用硬幣: ";
        for(int c : coins) cout << c << " ";
        cout << "\n目標金額: " << total << "\n\n";

        // 多傳入一個 depth=0，純粹為了印出漂亮的縮排
        int result = GetAns(coins, total, n - 1, dp, 0); 

        cout << "\n=== 遞迴結束，最終 DP 快取表狀態 ===" << endl;
        printDP(dp, coins);

        return result;
    }

    int GetAns(vector<int> &coins, int total, int idx, vector<vector<int>> &dp, int depth) {
        // 根據深度產生空白縮排，讓印出來的字有「樹狀」的感覺
        string indent(depth * 4, ' '); 
        
        cout << indent << "-> 進入 GetAns(idx=" << idx << " [硬幣 " << coins[idx] << "], 剩餘金額=" << total << ")\n";

        // 【達陣條件】
        if (!total) {
            cout << indent << "   [+] 剛好扣完！找到 1 種組合，回傳 1\n";
            return 1;
        }

        // 【快取命中】
        if (dp[idx][total] >= 0) {
            cout << indent << "   [★] 快取命中！dp[" << idx << "][" << total << "] 已經是 " << dp[idx][total] << "，直接抄答案\n";
            return dp[idx][total];
        }

        // 【分支 A：不使用這個硬幣】
        cout << indent << "   [分支 A] 不使用 " << coins[idx] << "，往前找 idx-1\n";
        int ans = 0;
        if (idx > 0) {
            ans = GetAns(coins, total, idx - 1, dp, depth + 1);
        } else {
            cout << indent << "      (idx 已經是 0，前面沒硬幣了，分支 A 方法數為 0)\n";
        }

        // 【分支 B：使用這個硬幣】
        if (total >= coins[idx]) {
            cout << indent << "   [分支 B] 嘗試使用 1 個 " << coins[idx] << " (剩下 " << total - coins[idx] << " 元)\n";
            // 注意這裡傳入的還是 idx，代表可以重複使用
            ans += GetAns(coins, total - coins[idx], idx, dp, depth + 1);
        } else {
            cout << indent << "   [分支 B] 錢不夠 (" << total << " < " << coins[idx] << ")，無法使用這枚硬幣\n";
        }

        // 【寫入快取】
        cout << indent << "   [寫入] 更新 dp[" << idx << "][" << total << "] = " << ans << "，並回傳\n";
        dp[idx][total] = ans;
        return ans;
    }

private:
    // 輔助函式：印出 DP 表格
    void printDP(const vector<vector<int>>& dp, const vector<int>& coins) {
        cout << "       金額: ";
        for (int j = 0; j < dp[0].size(); ++j) cout << j << "\t";
        cout << "\n------------------------------------------------\n";
        for (int i = 0; i < dp.size(); ++i) {
            cout << "idx=" << i << " (" << coins[i] << "元): ";
            for (int j = 0; j < dp[i].size(); ++j) {
                if (dp[i][j] == -1) cout << "-\t"; // 還沒算過的印成 '-'
                else cout << dp[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    Solution sol;
    
    // 設定簡單的測資：用 [1, 2] 湊出 3 元
    vector<int> coins = {1, 2};
    int total = 3;
    
    int ways = sol.change(total, coins);
    cout << "\n最終答案: 總共有 " << ways << " 種湊法\n";
    
    return 0;
}
