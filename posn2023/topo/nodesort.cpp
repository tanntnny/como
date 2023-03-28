#include <bits/stdc++.h>
using namespace std;

vector<int> G[55555];
priority_queue<int> H;
int D[55555], ANS[55555];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--){
		int n, m; cin >> n >> m;
		for(int i=0; i<m; i++){
			int u, v; cin >> v >> u;
			G[u].push_back(v);
			D[v]++;
		}
		for(int i=1; i<=n; i++) if(!D[i]) H.push(-i);
		int idx = 0, a = -1;
		while(!H.empty()){
			int u = -H.top();
			H.pop();
			if(!H.empty()) a = idx;
			ANS[idx++] = u;
			for(int v : G[u]){
				D[v]--;
				if(!D[v]) H.push(-v);
			}
		}
		if(a == -1 && idx == n){
			cout << "Same ";
			for(int i=0; i<idx; i++) cout << ANS[i] << " ";
		}
		else if(a != -1 && idx == n){
			cout << "Different ";
			swap(ANS[a], ANS[a + 1]);
			for(int i=0; i<idx; i++) cout << ANS[i] << " ";
		}
		else cout << "Never";
		cout << "\n";
		for(int i=1; i<=n; i++) G[i].clear();
		memset(D, 0, sizeof(D));
		memset(ANS, 0, sizeof(ANS));
	}

	return 0;
}
