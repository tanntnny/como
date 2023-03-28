#include <bits/stdc++.h>
using namespace std;
struct EDGE{
	int u, v, w;
} G[1111];

int DIS[1111], DIS2[1111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k, t; cin >> n >> m >> k >> t;
	for(int i=1; i<=m; i++) cin >> G[i].u >> G[i].v >> G[i].w;
	for(int i=1; i<=k; i++){
		cin >> G[i+m].u >> G[i+m].v >> G[i+m].w;
		G[i+m].w = -G[i+m].w;
	}
	while(t--){
		int s; cin >> s;
		for(int i=1; i<=n; i++) DIS[i] = 1<<30;
		DIS[s] = 0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m+k; j++){
				int u = G[j].u, v = G[j].v, w = G[j].w;
				if(DIS[u] == 1<<30) continue;
				if(DIS[u] + w < DIS[v]) DIS[v] = DIS[u] + w;
			}
			if(i == n - 1) for(int j=1; j<=n; j++) DIS2[j] = DIS[j];
		}
		for(int i=1; i<=n; i++){
			if(DIS[i] != DIS2[i] || DIS[i] == 1<<30) cout << "-1 ";
			else cout << DIS[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
