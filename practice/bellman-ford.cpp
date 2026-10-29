#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i,a,b) for(int i= a,a<b,i++)
#define 

struct Edge {
	int u,v,w;
};

signed main(){
	int num_vertices = 3;
	vector<Edge> edges;

	edges.push_back({1, 0, 5}); // B -> A, w=5
    edges.push_back({2, 1, 3}); // C -> B, w=3
    edges.push_back({2, 0, 6}); // C -> A, w=6
    
	const int INF = 1e9;

	vector<int> dis(num_vertices -1, INF);

	dis[2] = 0;
    
	   for (int i = 0 ;i < num_vertices - 1;i++){
		bool updated = false;
		for (auto edge : edges){
			if(dis[edge.u] != INF && dis[edge.u] + edge.w < dis[edge.v]){
				dis[edge.v] = dis[edge.u] + edge.w;
			}
		}
		if (!updated) break;
	}
    bool has_negative_cycle = false;
    for (auto edge : edges) {
        if (dis[edge.u] != INF && dis[edge.u] + edge.w < dis[edge.v]) {
            has_negative_cycle = true;
            break;
        }
    }

    if (has_negative_cycle) {
        cout << "No solution (Contains negative cycle)" << endl;
    } else {
        cout << "A = " << dis[0] << ", B = " << dis[1] << ", C = " << dis[2] << endl;
    }

    return 0;
}
	
