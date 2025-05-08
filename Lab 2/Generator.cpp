#include<bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2005;

int n, m;

bool g[N][N];
int sz=0;

signed main(){
	cin >> n >> m;


	if(m < 0.5 *n*(n-1)/2){
		// build spanning tree
		vector<int> in={1}, out;
		for(int x=2; x<=n; x++) out.push_back(x);
		for(int i=0; i<n-1; i++){
			int u = in[rng()%in.size()];

			int j = rng()%out.size();
			int v = out[j];
			swap(out[j], out.back()); out.pop_back();
			in.push_back(v);

			if(u>v) swap(u,v);
			g[u][v] = true;
			sz++;
		}

		// add random edges
		while(sz < m){
			int u = rng()%n+1, v = rng()%n+1;
			if(u>v) swap(u,v);
			sz -= g[u][v];
			g[u][v] = true;
			sz += g[u][v];
		}

	}
	else{
		// build complete graph
		for(int u=1; u<=n; u++){
			for(int v=u+1; v<=n; v++){
				sz -= g[u][v];
				g[u][v] = true;
				sz += g[u][v];
			}
		}

		// remove random edges
		while(sz > m){
			int u = rng()%n+1, v = rng()%n+1;
			if(u>v) swap(u,v);
			sz -= g[u][v];
			g[u][v] = false;
			sz += g[u][v];
		}

	}
	assert(sz==m);

	cout << n << " " << m << '\n';
	for(int u=1; u<=n; u++){
		for(int v=u+1; v<=n; v++){
			if(g[u][v]){
				int w = rng()%100'000;
				cout << u << " " << v << " " << w << "\n";
			}
		}
	}
	
}