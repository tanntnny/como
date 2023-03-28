#include <bits/stdc++.h>
using namespace std;

int A[1111111], B[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        int u, v; cin >> u >> v;
        A[u]++;
        B[v + 1]++;
    }
    for(int i=1; i<=1e6; i++) A[i] += A[i - 1], B[i] += B[i - 1];
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << A[v] - B[u] << "\n";
    }

    return 0;
}