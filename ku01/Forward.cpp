#include <bits/stdc++.h>
using namespace std;

int A[1111];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  for(int i=1; i<=n; i++) cin >> A[i];
  int ans = 1;
  while(true){
    if(A[s] == -1 ||   A[s] == 0) break;
    int l = s;
    s = A[s];
    A[l] = -1;
    if(A[s] != -1) ans++;
  }
  cout << ans;

  return 0;
}
