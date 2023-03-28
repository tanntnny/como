#include<bits/stdc++.h>
using namespace std;

int DP[1111][1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int l = s.length(), st = 0, mx = 1;
    for(int i=0; i<l; i++) DP[i][i] = 1;
    for(int i=l-1; i>0; i--){
        if(s[i] == s[i - 1]){
            DP[i - 1][i] = 1;
            st = i - 1;
            mx = 2;
        }
    }
    for(int k=3; k<=l; k++){
        for(int i=0; i<l-k+1; i++){
            int j = i + k - 1;
            if(s[i] == s[j] && DP[i + 1][j - 1]){
                DP[i][j] = 1;
                if(k > mx){
                    mx = k;
                    st = i;
                }
            }
        }
    }
    for(int i=st; i<st+mx; i++) cout << s[i];
    cout << "\n";

    return 0;
}