#include<bits/stdc++.h>
using namespace std;

int A[111111], LIS[111111];
vector<int> V[111111], ANS;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int mx = 0, idx;
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=n; i++){
        idx = lower_bound(LIS, LIS + mx, A[i]) - LIS;
        if(idx == mx) mx++;
        LIS[idx] = A[i];
        V[idx].push_back(A[i]);
    }
    int last = V[mx - 1][0];
    ANS.push_back(last);
    for(int i=mx-2; i>=0; i--){
        for(int j=0; j<V[i].size(); j++){
            if(V[i][j] < last){
                ANS.push_back(V[i][j]);
                last = V[i][j];
                break;
            }
        }
    }
    cout << mx << "\n";
    for(int i=ANS.size()-1; i>=0; i--) cout << ANS[i] << " ";

    return 0;
}