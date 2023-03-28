#include <bits/stdc++.h>
using namespace std;

int A[111], DP[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=m; i++){
        DP[i] = 1<<30;
        for(int j=1; j<=n; j++){
            if(i < A[j]) continue;
            DP[i] = min(DP[i], DP[i - A[j]] + 1);
        }
    }
    if(DP[m] == 1<<30) cout << "0\n";
    else cout << DP[m] << "\n";

    return 0;
}