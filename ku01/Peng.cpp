#include <bits/stdc++.h>
using namespace std;

const int MXN = 11111;
int A[MXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++) if(A[i] < A[j]) ans++;
    }
    cout << ans;

    return 0;
}