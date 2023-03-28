#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> H;
long long A[111111];
int n, m, k;

bool F(long long u){
    int p = 1, cnt = 0;
    for(int i=1; i<=m; i++){
        while(!H.empty()) H.pop();
        long long sum = 0;
        while(p <= n){
            sum += A[p];
            H.push(-A[p]);
            p++;
            if(H.size() > k){
                sum += H.top();
                H.pop();
            }
            if(sum >= u && H.size() == k){
                // cout << sum << " ";
                cnt++;
                break;
            }
        }
    }
    if(cnt == m) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> A[i];
    long long l = 1, r = 1e18;
    while(l < r){
        long long mid = (l + r) / 2;
        // cout << "\n" << mid << " ";
        if(F(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1<< "\n";

    return 0;
}