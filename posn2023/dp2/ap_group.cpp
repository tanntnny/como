#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int a, b;
    bool operator < (const NODE & OTHER) const{
        if(a != OTHER.a) return a > OTHER.a;
        return b < OTHER.b;
    }
} A[111111];

int LIS[111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        for(int i=0; i<n; i++) cin >> A[i].a >> A[i].b;
        sort(A, A + n);
        int mx = 0;
        for(int i=0; i<n; i++){
            int idx = upper_bound(LIS, LIS + mx, A[i].b) - LIS;
            if(idx == mx) mx++;
            LIS[idx] = A[i].b;
        }
        cout << mx << "\n";
        memset(LIS, 0, sizeof(LIS));
    }

    return 0;
}