#include<bits/stdc++.h>
using namespace std;

bool DP[1111][1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, r; cin >> s >> r;
    int n = s.length(), m = r.length(), q; cin >> q;
    s = " " + s, r = " " + r;
    while(q--){
        string a; cin >> a;
        a = " " + a;
        DP[0][0] = true;
        for(int i=1; i<=m; i++){
            if(DP[i - 1][0] && r[i] == a[i]) DP[i][0] = true;
            else DP[i][0] = false;
        }
        for(int i=1; i<=n; i++){
            if(DP[0][i - 1] && s[i] == a[i]) DP[0][i] = true;
            else DP[0][i] = false;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(DP[i - 1][j] && a[i + j] == r[i]) DP[i][j] = true;
                else if(DP[i][j - 1] && a[i + j] == s[j]) DP[i][j] = true;
                else DP[i][j] = false;
            }
        }
        // for(int i=0; i<=m; i++){ for(int j=0; j<=n; j++) cout << DP[i][j] << " "; cout << "\n"; }
        cout << (DP[m][n] ? "Yes\n" : "No\n");
        memset(DP, 0, sizeof(DP));
    }

    return 0;
}