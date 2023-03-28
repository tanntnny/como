#include <bits/stdc++.h>
using namespace std;

struct NODE{int u, w;};

queue<NODE> QU;
vector<int> G[1111];
int A[1111];
bool M[1111][1111];

void BFS(int i, int w){
	QU.push({i, w});
	while(!QU.empty()){
		int u = QU.front().u, w = QU.front().w;
		QU.pop();
		for(auto v : G[u]){
			if(v == i) continue;
			if(A[v] != 1<<30) continue;
			A[v] = w + 1;
			QU.push({v, w + 1});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q; cin >> q;
	while(q--){
		int n, m, k, st; cin >> n >> m >> k >> st;
		for(int i=0; i<m; i++){
			int u, v; cin >> u >> v;
			G[u].push_back(v);
		}
		for(int i=1; i<=n; i++) A[i] = 1<<30;
		A[st] = 0;
		BFS(st, 0);
		int mn = 1<<30, idx = -1;
		for(int i=1; i<=n; i++){
			QU.push({i, 0});
			while(!QU.empty()){
				int u = QU.front().u, w = QU.front().w;
				QU.pop();
				for(auto v : G[u]){
					if(v == i){
						if((w + 1) * (k - 1) + A[i] < mn) mn = A[i] + (w + 1) * (k - 1), idx = i;
						while(!QU.empty()) QU.pop();
						break;
					}
					if(M[i][v]) continue;
					M[i][v] = true;
					QU.push({v, w + 1});
				}
			}
		}
		if(idx != -1) cout << mn << " " << idx << "\n";
		else cout << "-1\n";
		memset(A, 0, sizeof(A));
		memset(M, 0, sizeof(M));
		for(int i=1; i<=n; i++) G[i].clear();
		while(!QU.empty()) QU.pop();
	}

	return 0;
}
