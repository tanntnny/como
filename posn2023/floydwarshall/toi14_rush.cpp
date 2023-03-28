#include <bits/stdc++.h>
using namespace std;

int ADJ[555][555];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) ADJ[i][j] = 1<<28;
	for(int i=1; i<=m; i++){
		int u, v, w; cin >> u >> v >> w;
		ADJ[u][v] = min(ADJ[u][v], w);
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				ADJ[i][j] = min(ADJ[i][j], ADJ[i][k] + ADJ[k][j]); 
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			cout << (ADJ[i][j] == 1<<28 ? 0 : ADJ[i][j]) << " ";
		cout << "\n";
	}

	return 0;
}
