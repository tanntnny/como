#include <bits/stdc++.h>
using namespace std;

long long A[111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n, k; cin >> n >> k;
        priority_queue<long long> H;
        long long sum = 0;
        for(int i=0; i<n; i++) cin >> A[i];
        for(int i=1; i<n; i++){
            sum += (A[i] - A[i - 1]);
            H.push(A[i] - A[i - 1]);
        }
        for(int i=1; i<k; i++){
            sum -= H.top();
            H.pop();
        }
        cout << sum << "\n";
        memset(A, 0, sizeof(A));
    }


    return 0;
}