#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct EDGE{
	int v, w;
	bool operator < (const EDGE & OTHER) const{
		return w > OTHER.w;
	}
};

priority_queue<EDGE> DIJK;
vector<EDGE> G[11111];
int D1[11111], D2[11111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, st, en, k; cin >> n >> m >> st >> en >> k;
	for(int i=0; i<m; i++){
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int i=0; i<n; i++) D1[i] = D2[i] = 1<<30;
	D1[st] = 0;
	DIJK.push({st, 0});
	while(!DIJK.empty()){
		int u = DIJK.top().v, w = DIJK.top().w;
		DIJK.pop();
		for(auto x : G[u]){
			if(D1[x.v] < w + x.w) continue;
			D1[x.v] = w + x.w;
			DIJK.push({x.v, D1[x.v]});
		}
	}
	D2[en] = 0;
	DIJK.push({en, 0});
	while(!DIJK.empty()){
		int u = DIJK.top().v, w = DIJK.top().w;
		DIJK.pop();
		for(auto x : G[u]){
			if(D2[x.v] < w + x.w) continue;
			D2[x.v] = w + x.w;;
			DIJK.push({x.v, D2[x.v]});
		}
	}
	int mn = 1<<30, idx = st;
	for(int i=0; i<n; i++){
		if(D2[i] < mn && D1[i] <= k){
			mn = D2[i];
			idx = i;
		}
	}
	cout << idx << " " << D1[idx] << " " << D2[idx] << "\n";

	return 0;
}
