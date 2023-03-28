#include <bits/stdc++.h>
using namespace std;

map<int, int> A;
int B[111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long ans = 0;
    for(int i=1; i<n; i++){
        int u, v, w; cin >> u >> v >> w;
        ans += A[w];
        A[w]++;
        B[i] = w;
    }
    cout << ans << "\n";
    for(int i=1; i<n; i++){
        int u; cin >> u;
        ans -= A[B[u]];
        ans += 1;
        A[B[u]]--;
        cout << ans << "\n";
    }

    return 0;
}