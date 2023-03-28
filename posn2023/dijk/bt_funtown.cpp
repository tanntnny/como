#include <bits/stdc++.h>
using namespace std;

struct EDGE{
	int v, w;
	bool operator < (const EDGE & OTHER) const{
		return w > OTHER.w;
	}
};

priority_queue<EDGE> DIJK;
vector<EDGE> G[1111111];
int DIS[1111111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--){
		int n, m; cin >> n >> m;
		for(int i=0; i<m; i++){
			int u, v, w; cin >> u >> v >> w;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		for(int i=1; i<=n; i++) DIS[i] = 1<<30;
		int a; cin >> a;
		for(int i=0; i<a; i++){
			int u; cin >> u;
			DIS[u] = 0;
			DIJK.push({u, 0});
		}
		while(!DIJK.empty()){
			int u = DIJK.top().v, w = DIJK.top().w;
			DIJK.pop();
			for(auto x : G[u]){
				if(DIS[x.v] > w + x.w){
					DIS[x.v] = w + x.w;
					DIJK.push({x.v, w + x.w});
				}
			}
		}
		cin >> a;
		int mn = 1<<30;
		for(int i=0; i<a; i++){
			int v; cin >> v;
			mn = min(mn, DIS[v]);
		}
		cout << mn << "\n";
	}

	return 0;
}
