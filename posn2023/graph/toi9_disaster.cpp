#include <bits/stdc++.h>
using namespace std;

vector<int> ANS, G[333];
int D[333], M[333][333], n, fnd = 0;

void DFS(int u, int k){
    if(fnd) return;
    if(k == n){
        for(auto x : ANS) cout << (char)(x + 'A') << " ";
        cout << "\n";
        fnd = 1;
        return;
    }
    for(auto i : G[u]){
        if(M[u][i] == 1){
            M[u][i] = -1;
            M[i][u] = -1;
            ANS.push_back(i);
            DFS(i, k + 1);
            M[u][i] = 1;
            M[i][u] = 1;
            ANS.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        char u, v; cin >> u >> v;
        int iu = u - 'A', iv = v - 'A';
        M[iu][iv] = 1;
        M[iv][iu] = 1;
        G[iu].push_back(iv);
        G[iv].push_back(iu);
        D[iu]++;
        D[iv]++;
    }
    for(int i=0; i<25; i++) sort(G[i].begin(), G[i].end());
    for(int i=0; i<25; i++){
        if(D[i] % 2){
            ANS.push_back(i);
            DFS(i, 0);
            return 0;
        }
    }
    for(int i=0; i<25; i++){
        if(D[i]){
            ANS.push_back(i);
            DFS(i, 0);
            if(fnd) return 0;
            ANS.pop_back();
        }
    }
    
    return 0;
}