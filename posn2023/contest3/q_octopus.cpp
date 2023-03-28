#include <bits/stdc++.h>
using namespace std;

int A[111111], R[111111], L[111111], P[111111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k; cin >> n >> k;
	int sum = 0;
	for(int i=1; i<=k; i++){
		cin >> A[i];
		sum += A[i];
	}
	for(int i=1; i<=k; i++){
		R[i + 1] = R[i] + A[i];
		L[i] = sum - R[i];
	}
	for(int i=k+1; i<=n; i++){
		cin >> P[i] >> A[i];
		if(P[i] > k){
			A[i] += A[P[i]];
			P[i] = P[P[i]];
		}
	}
	
	int q; cin >> q;
	while(q--){
		int ans = 0, u, v; cin >> u >> v;
		if(P[u] == P[v] && P[u] != 0 && P[v] != 0){
			cout << abs(A[u] - A[v]) << "\n";
			continue;
		}
		else if(P[u] && !P[v]){
			ans += A[u];
			u = P[u];
		}
		else if(P[v] && !P[u]){
			ans += A[v];
			v = P[v];
		}
		else if(P[u] && P[v]){
			ans += A[u] + A[v];
			u = P[u];
			v = P[v];
		}
		ans += min({R[u] + L[v], abs(R[v] - R[u]), abs(L[v] - L[u])});
		cout << ans << "\n";
	}

	return 0;
}
