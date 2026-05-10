class Solution {
  public:
    int minLengthAfterRemovals(vector<int>& x) {
      int n = x.size();

      int value = x[0];
      int count = 1;
      int max_count = 0;

      for (int i = 1; i < n; i++) {
        if (x[i] - value) {
          max_count = max(max_count, count);

          value = x[i];
          count = 0;
        } 
        count++;
      }
      max_count = max(max_count, count);

      return max(n & 1, (max_count << 1) - n);
    }
};
