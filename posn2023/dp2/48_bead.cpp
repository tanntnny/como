#include<bits/stdc++.h>
using namespace std;

const int MOD = 100;

int A[111], DP[111][111], M[111][111], ans = 0, n;

int F(int l, int r){
    if(l == r) return A[l];
    if(DP[l][r] != INT_MAX) return DP[l][r];
    int mn = 1<<30;
    for(int k=l; k<r; k++){
        int ll = F(l, k);
        int rr = F(k + 1, r);
        int sum = (ll + rr) % MOD;
        int mul = M[l][k] + M[k + 1][r] + ll * rr;
        // cout << l << " " << r << " " << rr << "\n";
        if(mul < mn) mn = mul, DP[l][r] = sum, M[l][r] = mul;
    }
    return DP[l][r];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        cin >> n;
        for(int i=1; i<=n; i++) cin >> A[i];
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) DP[i][j] = INT_MAX;
        F(1, n);
        cout << M[1][n] << "\n";
        memset(A, 0, sizeof(A));
        memset(M, 0, sizeof(M));
    }

    return 0;
}