#include <bits/stdc++.h>
using namespace std;

struct EDGE{
    int u, v, w;
    bool operator < (const EDGE & OTHER) const{
        return w > OTHER.w;
    }
};

vector<EDGE> G;
int A[111111], P[111011];

int root(int u){
    if(P[u] == u) return u;
    return P[u] = root(P[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=m; i++){
        int u, v, w; cin >> u >> v >> w;
        G.push_back({u, v, w});
    }
    sort(G.begin(), G.end());
    int l = 0, r = 1e9 + 10;
    while(l < r){
        for(int i=1; i<=n; i++) P[i] = i;
        int mid = (l + r) / 2;
        for(int i=0; ; i++){
            if(G[i].w < mid) break;
            int u = G[i].u, v = G[i].v;
            int rootu = root(u), rootv = root(v);
            P[rootu] = rootv;
        }
        bool check = true;
        for(int i=1; i<=n; i++){
            if(root(A[i]) != root(i)){
                check = false;
                break;
            }
        }
        if(check) l = mid + 1;
        else r = mid;
    }
    if(l != 1e9 + 10) cout << l - 1 << "\n";
    else cout << "-1\n";

    return 0;
}