#include<bits/stdc++.h>
using namespace std;

#define V vector
const int N = 3000;
const int INF = 1e9;

int n, m;
V<pair<int,int>> adj[N];

int d[N];

signed main(){

	// initialization
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v,w});
	}
	for(int x=1; x<=n; x++){
		d[x] = INF;
	}

	clock_t startTime = clock();
		
	priority_queue<pair<int,int>> que;
	que.push({-0,1});
	while(!que.empty()){
		// find node with min dist
		auto[dist,x] = que.top(); que.pop();
		if(d[x] <= -dist) continue;
		d[x] = -dist;

		// propagate
		for(auto[y,w] : adj[x]){
			que.push({-(d[x]+w), y});
		}
	}

	// output time
	clock_t endTime = clock();
    long long timeElapsedMs = ceil(1000000ll * (endTime - startTime) / CLOCKS_PER_SEC);
    cout << timeElapsedMs << endl; // CPU runtime in us
    // cout << n << "," << m << "," << 1 << "," << timeElapsedMs << endl; // CPU runtime in us
}