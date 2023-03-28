#include<bits/stdc++.h>
using namespace std;

int P[333333], M[333333];

int root(int u){
    if(P[u] == u) return u;
    return P[u] = root(P[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, l; cin >> q >> l;
    for(int i=1; i<=l ;i++) P[i] = i;
    while(q--){
        int a, b; cin >> a >> b;
        if(!M[a]){
            M[a] = 1;
            P[root(a)] = root(b);
            cout << "Yes\n";
        }
        else if(!M[b]){
            M[b] = 1;
            P[root(b)] = root(a);
            cout << "Yes\n";
        }
        else if(!M[root(a)]){
            M[root(a)] = 1;
            P[root(a)] = root(b);
            cout << "Yes\n";
        }
        else if(!M[root(b)]){
            M[root(b)] = 1;
            P[root(b)] = root(a);
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }

    return 0;
}