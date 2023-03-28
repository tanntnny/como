#include <bits/stdc++.h>
using namespace std;

long long A[1111111], DP[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++){ cin >> A[i]; A[i] += A[i - 1]; }
    int q; cin >> q;
    while(q--){
        long long m; cin >> m;
        for(int i=1; i<=n; i++){
            DP[i] = DP[i - 1] + (A[i] - A[i - 1]);
            if(i - k > 0) DP[i] = min(DP[i], DP[i - k] + m + (A[i] - A[i - k]) / 2);
        }
        cout << DP[n] << "\n";
        memset(DP, 0, sizeof(DP));
    }

    return 0;
}