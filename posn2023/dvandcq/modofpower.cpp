#include <bits/stdc++.h>
using namespace std;

int F(int n, int a, int m){
    if(a == 0) return 1;
    if(a % 2) return (n * F(n, a - 1, m)) % m;
    return (F(n, a / 2, m) * F(n, a / 2, m)) % m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q; cin >> q;
    while(q--){
        int n, a, m; cin >> n >> a >> m;
        cout << F(n, a, m) << "\n";
    }

    return 0;
}