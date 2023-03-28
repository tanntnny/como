#include <bits/stdc++.h>
using namespace std;

vector<int> G[11111];
int A[11111], P[11111];

int root(int u){
    if(P[u] == u) return u;
    return root(P[u]);
}

int dfs(int u, int p){
    for(auto v : G[u]){
        int 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    return 0;
}