class Solution {
  public:
    int minLengthAfterRemovals(vector<int>& x) {
      int n = x.size();

      int value = x[0];
      int count = 1;
      int max_count = 0;

      for (int i = 1; i < n; i++) {
        if (x[i] - value) {// 0＝false 代表遇到同個數字了 ！＝true 代表遇到不同的數字了
          max_count = max(max_count, count);// 遇到不同的數字了，更新max_count

          value = x[i];
          count = 0;// 切換數字了，count歸零
        } 
        count++;// 同數字的count累加
      }
      max_count = max(max_count, count);// 最后一个数的count 因為最後一個數的count不會在迴圈裡面被更新

      return max(n & 1, (max_count << 1) - n);
    }
};
