#include <bits/stdc++.h>
using namespace std;

int DP[1111][1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        string s, r; cin >> s >> r;
        int n = s.length(), m = r.length();
        s = " " + s, r = " " + r;
        for(int i=1; i<=n; i++) DP[i][0] = i;
        for(int i=1; i<=m; i++) DP[0][i] = i;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i] == r[j]) DP[i][j] = DP[i - 1][j - 1];
                else DP[i][j] = min({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]}) + 1;
            }
        }
        cout << DP[n][m] << "\n";
        memset(DP, 0, sizeof(DP));
    }

    return 0;
}