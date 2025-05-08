#include<bits/stdc++.h>
using namespace std;
const int N = 100;
const int C = 1e6;

int n, c;
int w[N], p[N];

int P(int x){
	int ret = 0;
	for(int i=0; i<n; i++) if(x>=w[i]){
		ret = max(ret, P(x-w[i])+p[i]);
	}
	return ret;
}

signed main(){	
	cin >> n >> c;

	for(int i=0; i<n; i++){
		cin >> w[i] >> p[i];
	}

	cout << P(c) << "\n";
}