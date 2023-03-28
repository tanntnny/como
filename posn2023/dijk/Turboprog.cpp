#include <bits/stdc++.h>
using namespace std;

struct EDGE{
	int v, w;
	bool operator < (const EDGE & OTHER) const{
		return w > OTHER.w;
	}
};

priority_queue<EDGE> DIJK;
vector<EDGE> G[1111];
int D[1111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	for(int i=0; i<m; i++){
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	for(int i=1; i<=n; i++) D[i] = 1<<30;
	D[1] = 0;
	DIJK.push({1, 0});
	while(!DIJK.empty()){
		int u = DIJK.top().v, w = DIJK.top().w;
		DIJK.pop();
		for(auto v : G[u]){
			if(D[v.v] <= w + v.w) continue;
			D[v.v] = w + v.w;
			DIJK.push({v.v, D[v.v]});
		}
	}
	while(q--){
		int x; cin >> x;
		if(D[x] == 1<<30) cout << "-1\n";
		else cout << D[x] << "\n";
	}
	
	return 0;
}
