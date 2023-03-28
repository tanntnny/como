#include <bits/stdc++.h>
using namespace std;

int DP[11111][11111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char A[11111], B[11111]; cin >> (A + 1) >> (B + 1);
    int l1 = strlen(A + 1), l2 = strlen(B + 1), mx = -1, ei;
    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(A[i] == B[j]) DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = 0;
            if(DP[i][j] > mx){
                mx = DP[i][j];
                ei = i;
            }
        }
    }
    for(int i=0; i<mx; i++) cout << A[ei - mx + 1 + i];
    cout << "\n";

    return 0;
}