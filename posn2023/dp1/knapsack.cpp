#include<bits/stdc++.h>
using namespace std;

int DP[111][11111], P[111], W[111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> P[i] >> W[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j < W[i]) DP[i][j] = DP[i - 1][j];
            else DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + P[i]);
        }
    }
    cout << DP[n][m] << "\n";

    return 0;
}