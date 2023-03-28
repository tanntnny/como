#include <bits/stdc++.h>
using namespace std;

struct EDGE{
    int u, v, w;
    bool operator < (const EDGE & OTHER) const{
        return w > OTHER.w;
    }
} G[1111111];

int P[5555];

int root(int u){
    if(P[u] == u) return u;
    return P[u] = root(P[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, w; cin >> G[i].u >> G[i].v >> G[i].w;
    }
    int st, en, k; cin >> st >> en >> k;
    for(int i=1; i<=n; i++) P[i] = i;
    sort(G, G + m);
    for(int i=0; i<m; i++){
        int ru = root(G[i].u);
        int rv = root(G[i].v);
        if(ru == rv) continue;
        P[rv] = ru;
        if(root(st) == root(en)){
            double ans = k * 1.0 / (G[i].w - 1);
            cout << (int)ceil(ans) << "\n";
            return 0;
        }
    }

    return 0;
}