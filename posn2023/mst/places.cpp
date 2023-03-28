#include <bits/stdc++.h>
using namespace std;

struct EDGE{
    int u, v, w;
    bool operator < (const EDGE & OTHER) const{
        return w > OTHER.w;
    }
};

vector<EDGE> G;
int P[222222];

int root(int u){
    if(P[u] == u) return u;
    return P[u] = root(P[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) P[i] = i;
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        G.push_back({u, v, w});
    }
    sort(G.begin(), G.end());
    long long sum = 0;
    for(int i=0; i<m; i++){
        int ru = root(G[i].u);
        int rv = root(G[i].v);
        if(ru == rv) continue;
        P[ru] = rv;
        sum += G[i].w - 1;
    }
    cout << sum << "\n";

    return 0;
}