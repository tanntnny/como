#include <bits/stdc++.h>
using namespace std;

vector<int> G[111111];
long long A[111111], mn, sum;

void DFS(int u, int p){
    for(auto v : G[u]){
        if(v == p) continue;
        DFS(v, u);
        A[u] += A[v];
    }
    mn = min(mn, abs(2 * A[u] - sum));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        sum = 0;
        mn = 1e18;
        for(int i=1; i<n; i++){
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            cin >> A[i];
            sum += A[i];
        }
        DFS(2, 0);
        cout << mn << "\n";
        memset(A, 0, sizeof(A));
        for(int i=1; i<=n; i++) G[i].clear();
    }

    return 0;
}