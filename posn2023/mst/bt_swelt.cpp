#include <bits/stdc++.h>
using namespace std;

struct EDGE{
	int u, v, w;
	bool operator < (const EDGE & OTHER) const{
		return w > OTHER.w;
	}
};

priority_queue<EDGE> H;

int P[111111], A[222222], SZ[111111], W[222222];

int root(int u){
	if(P[u] == u) return u;
	return P[u] = root(P[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	for(int i=0; i<m; i++){
		int u, v, w; cin >> u >> v >> w;
		H.push({u, v, w});
	}
	for(int i=1; i<=n; i++) P[i] = i, SZ[i] = 1;
	int idx = 1;
	while(!H.empty()){
		int u = H.top().u, v = H.top().v, w = H.top().w;
		H.pop();
		int ru = root(u);
		int rv = root(v);
		if(ru != rv){
			SZ[ru] += SZ[rv];
			P[rv] = ru;
		}
		A[idx] = max(A[idx - 1], SZ[ru]);
		W[idx] = w;
		idx++;
	}
	while(q--){
		int x; cin >> x;
		int idx = upper_bound(W + 1, W + 1 + m, x) - W;
		if(A[idx - 1] == 0) cout << "1\n";
		else cout << A[idx - 1] << "\n";
	}

	return 0;
}
