#include<bits/stdc++.h>
using namespace std;

int C[111], R[111], DP[111][111], P[111][111];

void F(int l, int r){
    if(l == r){ cout << "A" << l + 1; return; }
    cout << "(";
    F(l, P[l][r]);
    cout << " x ";
    F(P[l][r] + 1, r);
    cout << ")";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> C[i] >> R[i];
    for(int sz=1; sz<n; sz++){
        for(int i=0; i<n-sz; i++){
            int j = i + sz;
            int mn = 1<<30;
            for(int l=i; l<j; l++){
                int m = DP[i][l] + DP[l + 1][j] + C[i] * R[l] * R[j];
                if(m < mn) mn = m, P[i][j] = l;
            }
            DP[i][j] = mn;
        }
    }
    cout << DP[0][n - 1] << "\n";
    F(0, n - 1);
    cout << "\n";

    return 0;
}