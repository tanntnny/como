#include <bits/stdc++.h>
using namespace std;

long long A[555555], B[555555];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=n; i++){ cin >> B[i]; B[i] = -B[i]; }
    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + n);
    long long mx = 0, mn = 1e18;
    for(int i=1; i<=n; i++){
        long long m = A[i] - B[i];
        mx = max(mx, m), mn = min(mn, m);
    }
    cout << mx - mn << "\n";

    return 0;
}