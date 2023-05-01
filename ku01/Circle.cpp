#include <bits/stdc++.h>
using namespace std;

int A[1111111], B[1111111];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a = 1, b = 1, ans = 0;
  cin >> n;
  for(int i=1; i<=n; i++) cin >> A[i];
  for(int i=1; i<=n; i++) cin >> B[i];
  for(int i=1; i<=n; i++){
    int aa = A[i], bb = B[i];
    int u1 = min(a, aa), v1 = max(a, aa);
    int u2 = min(b, bb), v2 = max(b, bb);
    if(v1 > u2 && v1 < v2 && u1 < u2) ans++;
    else if(u1 > u2 && u1 < v2 && v1 > v2) ans++;
    else if(u1 == u2 && v1 == v2) ans++;
    a = aa, b = bb;
  }
  cout << ans;

  return 0;
}
