#include <bits/stdc++.h>
using namespace std;

int DP[2222][2222], P[2222][2222];
vector<char> ANS;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B; cin >> A >> B;
    int n = A.length(), m = B.length();
    A = " " + A;
    B = " " + B;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i] == B[j]){
                DP[i][j] = DP[i - 1][j - 1] + 1;
                P[i][j] = 1;
            }
            else if(DP[i - 1][j] >= DP[i][j - 1]){
                DP[i][j] = DP[i - 1][j];
                P[i][j] = 2;
            }
            else{
                DP[i][j] = DP[i][j - 1];
                P[i][j] = 3;
            }
        }
    }
    int i = n, j = m, mx = DP[n][m], cnt = 0;
    if(mx == 0){
        cout << "0\nNo Roma word\n";
        return 0;
    }
    while(cnt < mx){
        if(P[i][j] == 1){
            ANS.push_back(A[i]);
            cnt++;
            i--, j--;
        }
        else if(P[i][j] == 2) i--;
        else j--;
    }
    reverse(ANS.begin(), ANS.end());
    cout << mx << "\n";
    for(auto v : ANS) cout << v;
    cout << "\n";

    return 0;
}