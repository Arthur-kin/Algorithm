#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define FOR(i,a,b) for(int i = a; i < b;i++)

bool check(int target,vector<int>& cars,int m){
	int current_group_weight = 0;
	int require_group = 1;

	for (int weight : cars){
		if (weight > target) return false;
		if (current_group_weight + weight <= target){
			current_group_weight += weight;
		}else{
			require_group++;
			current_group_weight = weight;
		}
	}
	return require_group <= m;
   
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
        int n,m;
        cin >> n >> m;
       	
	vector<int> a(n);
	int max_car = 0;
	int total_weight = 0 ;

	FOR(i,0,n){ 
		cin >> a[i];
		total_weight += a[i];
		max_car = max(max_car,a[i]);
	}
	
	//二分收
	int low = max_car;
	int high = total_weight;
       
	int ans = 0;
	while(low <= high){
		int mid = low + (high - low)/2 ;
		if(check(mid,a,m )){
			ans = mid;
			high = mid -1;
		}else{
			low = mid+1;
		}

        }
	cout << ans << endl;
	return 0;
}
