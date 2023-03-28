#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> H;
vector<long long> V[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            long long num; cin >> num;
            V[i + j - 2].push_back(num);
        }
    }
    long long sum = 0;
    for(int i=2*n-2; i>=1; i--){
        for(auto u : V[i]) H.push(u);
        sum += H.top();
        H.pop();
    }
    cout << sum << "\n";

    return 0;
}