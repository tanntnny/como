#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int L[111], A[111], S[11111111], T[111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t; cin >> n >> m >> t;
	for(int i=1; i<=n; i++) cin >> L[i];
	for(int i=1; i<=n; i++) cin >> A[i];
	for(int i=1; i<=m; i++){ cin >> S[i]; S[i] += S[i - 1]; }
	for(int i=1; i<=t; i++) cin >> T[i];
	sort(L + 1, L + 1 + n);
	sort(A + 1, A + 1 + n);
	for(int q=1; q<=t; q++){
		int Q[22];
		memset(Q, 0, sizeof(Q));
		cin >> Q[0];
		for(int i=1; i<n; i++) cin >> Q[i];
		Q[n] = m + 1;
		bool check = false;
		do{
			check = false;
			for(int i=1; i<=n && !check; i++){
				int last = Q[i - 1], cnt = 0;
				while(last < Q[i]){
					last = upper_bound(S + last, S + Q[i], S[last-1] + L[i] - A[i]) - S;
					cnt++;
					if(cnt > T[q]){ check = true; break; }
				}
			}
		} while(check && next_permutation(A + 1, A + 1 + n));
		if(check) cout << "F\n";
		else cout << "P\n";
	}

	return 0;
}
