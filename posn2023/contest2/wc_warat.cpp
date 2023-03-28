#include <bits/stdc++.h>
using namespace std;

vector<int> G[11111];
int A[11111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        int m; cin >> m;
        for(int j=1; j<=m; j++){
            int v; cin >> v;
            G[v].push_back(i);
        }
    }

    return 0;
}