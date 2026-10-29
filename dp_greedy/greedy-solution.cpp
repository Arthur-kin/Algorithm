//「這整串數字裡，出現次數最多的那個霸王數字，牠的出現次數（max_count）到底有沒有超過陣列總長度（$n$）的一半？」
class Solution {
  public:
    int minLengthAfterRemovals(vector<int>& x) {//sort過的
      int n = x.size();

      int value = x[0];//先把`value`設成第一個數字，然後從第二個數字開始往下走，看看什麼時候遇到不同的數字了
      int count = 1;
      int max_count = 0;

      for (int i = 1; i < n; i++) {
        if (x[i] - value) {// 0＝false 代表遇到同個數字了 ！＝true 代表遇到不同的數字了
          max_count = max(max_count, count);// 遇到不同的數字了，更新max_count

          value = x[i];// 切換數字了，更新value
          count = 0;// 切換數字了，count歸零
        } 
        count++;// 同數字的count累加
      }
      max_count = max(max_count, count);// 最后一个数的count 因為最後一個數的count不會在迴圈裡面被更新

      return max(n & 1, (max_count << 1) - n);// 意思是如果有一家獨大(right)的話 就一定是true，如果是勢均力敵的話 右邊一定小於0 左邊就看n的奇偶性了，如果n是偶數的話 就是0，如果n是奇數的話 就是1
    }
};
