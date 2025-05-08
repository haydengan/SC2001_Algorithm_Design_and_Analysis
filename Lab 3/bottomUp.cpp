#include<bits/stdc++.h>
using namespace std;

const int C = 1e6;

int n, c;
int dp[C];

signed main(){	
	cin >> n >> c;

	for(int i=0; i<n; i++){
		int w, p;
		cin >> w >> p;

		for(int x=0; x<=c; x++){
			dp[x+w] = max(dp[x+w], dp[x]+p);
		}
	}

	cout << dp[c] << "\n";
}