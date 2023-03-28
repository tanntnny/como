#include<bits/stdc++.h>
using namespace std;

struct EDGE{
    int v, w;
};

queue<EDGE> QU;
vector<EDGE> G[111];
int M[111][2222];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    for(int q=1; q<=Q; q++){
        int n, m, st, en; cin >> n >> m >> st >> en;
        for(int i=0; i<m; i++){
            int u, v, w; cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        int mn = 1<<30;
        M[st][0] = q;
        QU.push({st, 0});
        while(!QU.empty()){
            int u = QU.front().v, w = QU.front().w;
            QU.pop();
            for(auto v : G[u]){
                int nw = w ^ v.w;
                if(M[v.v][nw] == q) continue;
                M[v.v][nw] = q;
                if(v.v == en) mn = min(mn, nw);
                QU.push({v.v, nw});
            }
        }
        cout << mn << "\n";
        memset(M, 0, sizeof(M));
        for(int i=1; i<=n; i++) G[i].clear();
    }

    return 0;
}