#include <bits/stdc++.h>
using namespace std;

struct EDGE{
	int v, w;
	bool operator < (const EDGE & OTHER) const{
		return w > OTHER.w;
	}
};

priority_queue<EDGE> DIJK;
vector<EDGE> G[111111];
int DIS[111111], M[111111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, st, en; cin >> n >> m >> st >> en;
	for(int i=0; i<m; i++){
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	for(int i=1; i<=n; i++) DIS[i] = 1<<30;
	int check = -1;
	DIJK.push({st, 0});
	while(!DIJK.empty()){
		int u = DIJK.top().v, w = DIJK.top().w;
		DIJK.pop();
		if(M[u] >= 2 || DIS[u] == w) continue;
		M[u]++;
		DIS[u] = w;
		if(u == en){
			if(w > check && check != -1){ cout << w << "\n"; return 0; }
			else check = w;
		}
		for(auto x : G[u]){
			DIJK.push({x.v, w + x.w});
		}
	}

	return 0;
}
