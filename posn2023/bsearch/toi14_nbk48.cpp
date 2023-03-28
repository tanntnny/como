#include<bits/stdc++.h>
using namespace std;

long long A[111111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for(int i=n-1; i>=1; i--){
		if(A[i] > A[i + 1]) A[i] = A[i + 1];
	}
	while(q--){
		long long x;
		cin >> x;
		cout << upper_bound(A + 1, A + 1 + n, x) - A - 1 << "\n";
	}

	return 0;
}
