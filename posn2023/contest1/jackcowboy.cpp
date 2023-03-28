#include <bits/stdc++.h>
using namespace std;

struct EDGE{
    int u, w;
};

queue<EDGE> QU;
vector<int> G[111111];
int A[111111], P[111111], M[111111];

int root(int u){
    if(P[u] == u) return u;
    return P[u] = root(P[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) P[i] = i;
    for(int i=1; i<=n-1; i++){
        int u, v; cin >> u  >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    A[1] = -1;
    QU.push({1, 0});
    while(!QU.empty()){
        int u = QU.front().u, w = QU.front().w;
        QU.pop();
        for(auto v : G[u]){
            if(A[v]) continue;
            A[v] = w + 1;
            QU.push({v, w + 1});
        }
    }
    while(q--){
        int opr, x; cin >> opr >> x;
        if(opr == 0){
            M[x] = 1;
            QU.push({x});
            while(!QU.empty()){
                int u = QU.front().u;
                QU.pop();
                for(auto v : G[u]){
                    if(A[v] <= A[u]) continue;
                    P[root(v)] = root(x);
                    QU.push({v});
                }
            }
        }
        else{
            if(M[root(x)]) cout << root(x) << "\n";
            else cout << "-1\n";
        }
    }

    return 0;
}