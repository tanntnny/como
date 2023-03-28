#include <bits/stdc++.h>
using namespace std;

int A[111111], P[111111];

int root(int u){
	if(P[u] == u) return u;
	return P[u] = root(P[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	for(int i=1; i<=n; i++){
		P[i] = i;
		cin >> A[i];
	}
	while(q--){
		int x, y; cin >> x >> y;
		if(root(x) == root(y)){
			cout << "-1\n";
			continue;
		}
		if(A[root(x)] > A[root(y)]){
			cout << root(x) << "\n";
			A[root(x)] += A[root(y)]/2;
			P[root(y)] = root(x);
		}
		else if(A[root(x)] < A[root(y)]){
			cout << root(y) << "\n";
			A[root(y)] += A[root(x)]/2;
			P[root(x)] = root(y);
		}
		else if(root(x) < root(y)){
			cout << root(x) << "\n";
			A[root(x)] += A[root(y)]/2;
			P[root(y)] = root(x);
		}
		else{
			cout << root(y) << "\n";
			A[root(y)] += A[root(x)]/2;
			P[root(x)] = root(y);
		}
	}

	return 0;
}
