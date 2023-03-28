#include <bits/stdc++.h>
using namespace std;

vector<int> ANS, G[111111];
priority_queue<int> H;
int D[111111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--){
		int n, m; cin >> n >> m;
		for(int i=0; i<m; ++i){
			int u, v; cin >> u >> v;
			G[u].push_back(v);
			D[v]++;
		}
		for(int i=1; i<=n; ++i) if(!D[i]) H.push(-i);
		while(!H.empty()){
			int u = -H.top();
      H.pop();
			ANS.push_back(u);
			for(int v : G[u]){
				D[v]--;
				if(!D[v]) H.push(-v);
			}
		}
		if(ANS.size() != n) cout << "No\n";
		else{
			cout << "Yes ";
			for(int u : ANS) cout << u << " ";
			cout << "\n";
		}
		memset(D, 0, sizeof(D));
		for(int i=1; i<=n; ++i) G[i].clear();
		ANS.clear();
	}

	return 0;
}
