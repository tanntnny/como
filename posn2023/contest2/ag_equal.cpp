#include <bits/stdc++.h>
using namespace std;

int A[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, p; cin >> n >> k >> p;
    int mx = 0, mn = 1<<30;
    for(int i=1; i<=n; i++){
        cin >> A[i];
        mx = max(mx, A[i]);
        mn = min(mn, A[i]);
    }
    int l = mn+1, r = mx;
    while(l < r){
        int mid = (l + r) / 2;
        int ki = k, pi = p, last = -1e9;
        for(int i=1; i<=n; i++){
            if(A[i] >= mid){
                if(i - last > pi - 1) ki--, pi = p, last = i;
                else pi -= (i - last), last = i;
                if(ki < 0) break;
            }
        }
        if(ki < 0) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << "\n";

    return 0;
}