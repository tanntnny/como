#include <bits/stdc++.h>
using namespace std;

int P[555555];

int findroot(int u){
	if(P[u] == u) return u;
	return P[u] = findroot(P[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	for(int i=1; i<=n; i++) P[i] = i;
	while(q--){
		char opr;
		int x, y; cin >> opr >> x >> y;
		if(opr == 'c'){
			P[findroot(x)] = findroot(y);
		}
		else{
			if(findroot(x) != findroot(y)) cout << "no\n";
			else cout << "yes\n";
		}
	}

	return 0;
}
