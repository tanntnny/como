#include<bits/stdc++.h>
using namespace std;

vector<int> G[111111];
int A[111111];

bool DFS(int u, int p){
    if(A[u]) return A[u] == p;
    A[u] = p;
    for(auto v :G[u]) if(!DFS(v, 3 - p)) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n, m; cin >> n >> m;
        while(m--){
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool check = true;
        for(int i=1; i<=n; i++){
            if(!A[i]){
                if(!DFS(i, 1)){
                    check = false;
                    break;
                }
            }
        }
        if(check) cout << "yes\n";
        else cout << "no\n";
        memset(A, 0, sizeof(A));
        for(int i=1; i<=n; i++) G[i].clear();
    }

    return 0;
}