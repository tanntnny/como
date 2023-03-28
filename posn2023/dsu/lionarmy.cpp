#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int NN = 333333;

int B[333333], P[777777];

int root(int u){
    if(P[u] == u) return u;
    return P[u] = root(P[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    bool check = false;
    B[0] = 1;
    for(int i=1; i<=3e5; i++){ B[i] = B[i - 1] << 1; B[i] %= MOD; }
    for(int i=1; i<=700000; i++) P[i] = i;
    while(q--){
        int t, u, v; cin >> t >> u >> v;
        if(check){ cout << "0\n"; continue; }
        if(t == 1){
            if(root(u) != root(v)){
                P[root(u)] = root(v);
                P[root(u + NN)] = root(v + NN);
                n--;
            }
        }
        else{
            if(root(u) != root(v + NN)){
                P[root(u)] = root(v + NN);
                P[root(u + NN)] = root(v);
                n--;
            }
        }
        if(root(u) == root(u + NN)){ check = true; cout << "0\n"; }
        else cout << B[n] << "\n";
    }

    return 0;
}