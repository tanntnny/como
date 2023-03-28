#include <bits/stdc++.h>
using namespace std;

int A[111111], LIS[111111];
vector<int> VT[111111], ANS;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    int mx = 0;
    for(int i=0; i<n; i++){
        int idx = lower_bound(LIS, LIS + mx, -A[i]) - LIS;
        if(idx == mx) mx++;
        LIS[idx] = -A[i];
        VT[idx].push_back(-A[i]);
    }
    int last = VT[mx - 1][0];
    ANS.push_back(last);
    for(int i=mx-2; i>=0; i--){
        for(int j=0; j<VT[i].size(); j++){
            if(VT[i][j] < last){
                ANS.push_back(VT[i][j]);
                last = VT[i][j];
                break;
            }
        }
    }
    cout << mx << "\n";
    for(int i=ANS.size()-1; i>=0; i--) cout << -ANS[i] << " ";

    return 0;
}