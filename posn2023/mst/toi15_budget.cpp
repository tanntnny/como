#include <bits/stdc++.h>
using namespace std;

struct EDGE{
    int u, v, w, s;
    bool operator < (const EDGE & OTHER) const{
        return w < OTHER.w;
    }
} G[555555];

vector<pair<int, int>> VT;
int P[3333], W[1111111], V[1111111];

int root(int u){
    if(P[u] == u) return u;
    return P[u] = root(P[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++) P[i] = i;
    for(int i=0; i<m; i++){
        cin >> G[i].u >> G[i].v >> G[i].w >> G[i].s;
    }
    int p; cin >> p;
    for(int i=0; i<p; i++){
        int w, v; cin >> w >> v;
        VT.push_back({w, v});
    }
    sort(VT.begin(), VT.end());
    for(int i=p-2; i>=0; i--){
        if(VT[i].second >= VT[i + 1].second) VT[i] = VT[i + 1];
        else if(VT[i].first == VT[i + 1].first) VT[i + 1] = VT[i];
    }
    for(int i=0; i<p; i++) W[i] = VT[i].first, V[i] = VT[i].second;

    for(int i=0; i<m; i++){
        if(G[i].s == 0){
            int idx = lower_bound(W, W + p, G[i].w) - W;
            G[i].w = V[idx];
        }
        else G[i].w = 0;
    }
    sort(G, G + m);
    long long ans = 0;
    for(int i=0; i<m; i++){
        int ru = root(G[i].u);
        int rv = root(G[i].v);
        if(ru == rv) continue;
        P[rv] = ru;
        ans += G[i].w;
    }
    cout << ans << "\n";

    return 0;
}