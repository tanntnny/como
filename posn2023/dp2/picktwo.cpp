#include <bits/stdc++.h>
using namespace std;

long long L[111111], R[111111], A[111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        for(int i=1; i<=n; i++) cin >> A[i];
        long long sum = 0;
        for(int i=1; i<=n; i++){
            sum += A[i];
            sum = max(sum, (long long)0);
            L[i] = max(L[i - 1], sum);
        }
        sum = 0;
        for(int i=n; i>=1; i--){
            sum += A[i];
            sum = max(sum, (long long)0);
            R[i] = max(R[i + 1], sum);
        }
        long long mx = 0;
        for(int i=1; i<=n; i++) mx = max(mx, L[i] + R[i + 1]);
        cout << mx << "\n";
    }

    return 0;
}