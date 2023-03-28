#include <bits/stdc++.h>
using namespace std;

struct EDGE{
	int v, w, f, t;
	bool operator < (const EDGE & OTHER) const{
		return w > OTHER.w;
	}
};

priority_queue<EDGE> DIJK;
vector<EDGE> G[111];
int P[111], D[3][111][111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> P[i];
	int st, en, ca, m; cin >> st >> en >> ca >> m;
	for(int i=0; i<m; i++){
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int i=0; i<=100; i++) for(int j=1; j<=n; j++) D[0][i][j] = D[1][i][j] = 1<<30;
	D[0][0][st] = 0;
	DIJK.push({st, 0, 0, 0});
	while(!DIJK.empty()){
		int u = DIJK.top().v, w = DIJK.top().w, f = DIJK.top().f, t = DIJK.top().t;
		DIJK.pop();
		if(f + 1 <= ca){
			if(D[t][f + 1][u] > w + P[u]){
				D[t][f + 1][u] = w + P[u];
				DIJK.push({u, w + P[u], f + 1, t});
			}
		}
		if(t == 0){
			if(D[1][ca][u] > w){
				D[1][ca][u] = w;
				DIJK.push({u, w, ca, 1});
			}
		}
		for(auto x : G[u]){
			if(f - x.w >= 0){
				if(D[t][f - x.w][x.v] > w){
					D[t][f - x.w][x.v] = w;
					DIJK.push({x.v, w, f - x.w, t});
				}
			}
		}
	}
	cout << min(D[0][ca][en], D[1][ca][en]) << "\n";
	
	return 0;
}
