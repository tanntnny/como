#include<bits/stdc++.h>
using namespace std;

long long F(long long u){
  long long l = 1, r = 1e15;
  while(l < r){
    long long m = (l + r) / 2;
    long long n = m * m;
    if(n > u || n / m != m) r = m;
    else l = m + 1;
  }
  return l - 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, q; cin >> n >> q;
  while(q--){
    long long st, en; cin >> st >> en;
    st--;
    long long ist = F(st) + (F(st / 2));
    long long ien = F(en) + (F(en / 2));
    cout << ien - ist << "\n";
  }

  return 0;
}