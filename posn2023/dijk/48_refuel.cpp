#include <bits/stdc++.h>
using namespace std;

struct EDGE{
	int v, w, f;
	bool operator < (const EDGE & OTHER) const{
		return w > OTHER.w;
	}
};

priority_queue<EDGE> DIJK;
vector<EDGE> G[1111];
int A[1111], D[111][1111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--){
		int n, m; cin >> n >> m;
		for(int i=0; i<n; i++) cin >> A[i];
		for(int i=0; i<m; i++){
			int u, v, w; cin >> u >> v >> w;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		int ca, st, en; cin >> ca >> st >> en;
		for(int i=0; i<=100; i++) for(int j=0; j<n; j++) D[i][j] = 1<<30;
		D[0][st] = 0;
		DIJK.push({st, 0, 0});
		while(!DIJK.empty()){
			int u = DIJK.top().v, w = DIJK.top().w, f = DIJK.top().f;
			DIJK.pop();
			if(D[f + 1][u] > w + A[u] && f + 1 <= ca){
				D[f + 1][u] = w + A[u];
				DIJK.push({u, w + A[u], f + 1});
			}
			for(auto x : G[u]){
				if(f - x.w >= 0){
					if(D[f - x.w][x.v] > w){
						D[f - x.w][x.v] = w;
						DIJK.push({x.v, w, f - x.w});
					}
				}
			}
		}
		if(D[0][en] == 1<<30) cout << "-99\n";
		else cout << D[0][en] << "\n";
		memset(D, 0, sizeof(D));
		memset(A, 0, sizeof(A));
		for(int i=0; i<n; i++) G[i].clear();
	}

	return 0;
}
