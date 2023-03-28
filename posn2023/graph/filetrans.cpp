#include <bits/stdc++.h>
using namespace std;

vector<int> G[1111];
int M[1111], itr = 0;

void DFS(int u, int p){
	M[u] = itr;
	for(auto v : G[u]){
		if(M[v] == itr) continue;
		DFS(v, u);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	for(int i=0; i<m; i++){
		int u, v; cin >> u >> v;
		G[u].push_back(v);
	}
	while(q--){
		itr++;
		int u, v; cin >> u >> v;
		DFS(u, 0);
		cout << (M[v] == itr ? "Yes\n" : "No\n");
	}

	return 0;
}
