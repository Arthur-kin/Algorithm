#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i,a,b) for(int i = a;i < b; i++)
#define F first
#define S second
#define endl '\n'

bool canDistribution(const vector<int>& cakes, int target,int k){
      if (target == 0) return true;

      int count = 0;

      for (int length : cakes) {
            count += length / target;
      }
      
      return count >= k;
}


signed main()
{
      ios::sync_with_stdio(0);
      cin.tie(0);
      int n;int k;
      cin >> n >> k;
      
      vector<int> cakes(n);
      int total_length = 0;
      int max_cake  = 0;

      FOR(i,0,n){
            cin >> cakes[i];
            total_length += cakes[i];
            max_cake = max(max_cake, cakes[i]);
      }
      
      if (total_length < k){
            cout << 0 << endl;
            return 0; 
      }
      
      // binary search
      int low = 1;
      int high = max_cake;
      int ans = 0;
      
      while(low <= high){

            int mid = low + (high - low) / 2;

            if (canDistribution(cakes, mid, k)){
                  ans = mid;
                  low = mid + 1;
            }else{
                  high = mid - 1;
            }
      }
      cout << ans << endl;
      return 0;
}
