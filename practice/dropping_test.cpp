#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define ALL(v) v.begin(),v.end()

bool check(double target, int n , int k, vector<double>& a,vector<double>& b ){
    vector<double> v(n);
    FOR(i,0,n){
        v[i] = a[i] - target*b[i];
    }
    sort(ALL(v),greater<double>());
    
    double sum = 0;
    int keep_count = n - k;
    FOR(i,0,keep_count){
        sum += v[i];
    }
    return sum>= 0;
}

signed main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n, k;
     cin >> n >> k;

     vector<double> a(n);
     vector<double> b(n);

     FOR(i,0,n){ cin >> a[i];}
     FOR(i,0,n){ cin >> b[i];}

     //二分
    double low = 0.0,high= 1.0;

    FOR(iter,0,100){
        double mid = low + (high - low)/2;
        if (check(mid,n,k,a,b)){
            low = mid ;
        }else{
            high = mid;
        }
    }
    int final_score = round(low*100);

    cout << final_score << endl;

    return 0;
}

