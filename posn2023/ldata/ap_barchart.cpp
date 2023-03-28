#include <bits/stdc++.h>
using namespace std;

int L[111111], R[111111];
long long A[111111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) cin >> A[i];
		for(int i=1; i<=n; i++){
			L[i] = i - 1;
			while(L[i] > 0 && A[i] <= A[L[i]]) L[i] = L[L[i]];
		}
		for(int i=n; i>=1; i--){
			R[i] = i + 1;
			while(R[i] <= n && A[i] <= A[R[i]]) R[i] = R[R[i]];
		}
		long long mx = 0;
		for(int i=1; i<=n; i++) mx = max(mx, A[i] * (R[i] - L[i] - 1));
		cout << mx << "\n";
	}
	
	return 0;
}
