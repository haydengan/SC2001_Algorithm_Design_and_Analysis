#include<bits/stdc++.h>
using namespace std;

#define V vector
const int N = 3000;
const int INF = 1e9;

int n, m;
int g[N][N];

int d[N];
bool vis[N];

signed main(){

	// initialization
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;

		g[u][v] = w;
	}
	for(int x=1; x<=n; x++){
		d[x] = INF;
	}

	clock_t startTime = clock();
	
	d[0] = 2*INF;
	d[1] = 0;
	for(int _=0; _<n; _++){
		// find node with min dist
		int x = 0;
		for(int y=1; y<=n; y++) if(!vis[y] && d[y]<d[x]) x = y;
		assert(x!=0);
		vis[x] = true;

		// propagate
		for(int y=1; y<=n; y++) if(g[x][y]){
			d[y] = min(d[y], d[x]+g[x][y]);
			vis[y]=false;
		}
	}

	// output time
	clock_t endTime = clock();
    long long timeElapsedMs = ceil(1000000ll * (endTime - startTime) / CLOCKS_PER_SEC);
    cout << timeElapsedMs << endl; // CPU runtime in us
    // cout << n << "," << m << "," << 0 << "," << timeElapsedMs << endl; // CPU runtime in us
}