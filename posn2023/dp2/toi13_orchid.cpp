#include <bits/stdc++.h>
using namespace std;

int LIS[1111111], A[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    int mx = 0;
    for(int i=0; i<n; i++){
        int idx = upper_bound(LIS, LIS + mx, A[i]) - LIS;
        if(idx == mx) mx++;
        LIS[idx] = A[i];
    }
    cout << n - mx << "\n";

    return 0;
}