#include <bits/stdc++.h>
using namespace std;

long long A[111111], B[1111111], ans = 0;

void F(int l, int r){
    if(l >= r) return;
    int m = (l + r) / 2;
    F(l, m);
    F(m + 1, r);
    int i = l, j = m + 1, k = l;
    while(i <= m && j <= r){
        if(A[i] <= A[j]) B[k++] = A[i++];
        else B[k++] = A[j++], ans += m - i + 1;
    }
    while(i <= m) B[k++] = A[i++];
    while(j <= r) B[k++] = A[j++];
    for(int i=l; i<=r; i++) A[i] = B[i];
    // cout << l << " " << r << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> A[i];
    F(1, n);
    cout << ans << "\n";

    return 0;
}