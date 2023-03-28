#include <bits/stdc++.h>
using namespace std;

long long A[5011], B[5011], DP[2][5011];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n, m; cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> A[i];
        for(int i=1; i<=m; i++) cin >> B[i];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                DP[i % 2][j] = max({DP[i % 2][j], DP[(i - 1) % 2][j], DP[i % 2][j - 1]});
                DP[i % 2][j] = max(DP[i % 2][j], DP[(i - 1) % 2][j - 1] + abs(A[i] - B[j]));
            }
        }
        cout << DP[n % 2][m] << "\n";
        memset(DP, 0, sizeof(DP));
    }

    return 0;
}