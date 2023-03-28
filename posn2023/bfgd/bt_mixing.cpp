#include <bits/stdc++.h>
using namespace std;

long long A[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        long long sum = 0;
        for(int i=0; i<n; i++) cin >> A[i];
        for(int i=0; i<n-1; i++){
            int j = i + 1;
            sum += max(A[i], A[j]);
        }
        cout << sum << "\n";
    }

    return 0;
}