#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int dd, mm;
    bool operator < (const NODE & OTHER) const{
        if(dd != OTHER.dd) return dd < OTHER.dd;
        return mm < OTHER.mm;
    }
} DP[1111][1111];

int A[1111], B[1111], k;

NODE add(NODE N, int m){
    NODE T;
    int nd = N.dd, nm = N.mm + m;
    if(nm > k) nd++, nm = m;
    T = {nd, nm};
    return T;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> k >> n;
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=n; i++) cin >> B[i];
    DP[0][0] = {1, 0};
    for(int i=1; i<=n; i++) DP[i][0] = add(DP[i - 1][0], B[i]);
    for(int i=1; i<=n; i++) DP[0][i] = add(DP[0][i - 1], A[i]);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            NODE nA = add(DP[i][j - 1], A[j]);
            NODE nB = add(DP[i - 1][j], B[i]);
            DP[i][j] = min(nA, nB);
        }
    }
    cout << DP[n][n].dd << "\n" << DP[n][n].mm << "\n";

    return 0;
}