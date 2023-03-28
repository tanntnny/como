#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int st, en, w;
    bool operator < (const NODE & OTHER) const{
        return en < OTHER.en;
    }
} A[111111];

int DP[111111], B[111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> A[i].st >> A[i].en >> A[i].w;
    sort(A, A + n);
    for(int i=1; i<=n; i++) B[i] = A[i].en;
    for(int i=1; i<=n; i++){
        int idx = lower_bound(B, B + n, A[i].st) - B - 1;
        DP[i] = max(DP[i - 1], DP[idx] + A[i].w);
    }
    cout << DP[n] << "\n";

    return 0;
}