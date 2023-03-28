#include <bits/stdc++.h>
using namespace std;

map<long long, int> S;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        for(int i=1; i<=n; i++){
            long long num; cin >> num;
            S[num + 1]++;
        }
        long long ans = 0, last = 0;
        for(auto x : S){
            // cout << x.first << " ";
            ans += x.first - last - 1;
            if(x.second > 1) S[x.first + 1] += x.second / 2;
            if(x.second % 2 == 0) ans++;
            last = x.first;
        }
        cout << ans << "\n";
        S.clear();
    }

    return 0;
}