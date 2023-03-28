#include <bits/stdc++.h>
using namespace std;

int DP[1111][111111], P[1111], W[1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> W[i];
    for(int i=1; i<=n; i++) cin >> P[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            DP[i][j] = DP[i - 1][j];
            if(j < W[i]) continue;
            DP[i][j] = max(DP[i][j], DP[i - 1][j - W[i]] + P[i]);
        }
    }
    cout << DP[n][k] << "\n";

    return 0;
}