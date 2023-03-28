#include <bits/stdc++.h>
using namespace std;

char A[1111];
int DP[1111][1111];

int F(int l, int r){
    if(l == r) return 0;
    if(DP[l][r] != -1) return DP[l][r];
    if(A[l] == A[r]) DP[l][r] = 1 + F(l + 1, r - 1);
    for(int k=l; k<r; k++) DP[l][r] = max(DP[l][r], F(l, k) + F(k + 1, r));
    return DP[l][r];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> A[i];
    memset(DP, -1, sizeof(DP));
    cout << F(1, n) << "\n";

    return 0;
}