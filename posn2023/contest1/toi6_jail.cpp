#include <bits/stdc++.h>
using namespace std;

bool A[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int u = 0;
    for(int i=1; i<=n; i++){
        int l = m;
        while(l--){
            u++;
            while(A[u]){
                u++;
                if(u > n) u = 1;
            }
            if(u > n) u = 1;
            while(A[u]){
                u++;
                if(u > n) u = 1;
            }
        }
        cout << u << " ";
        A[u] = true;
    }

    return 0;
}