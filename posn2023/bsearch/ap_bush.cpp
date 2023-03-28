#include <bits/stdc++.h>
using namespace std;

int A[1111];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while(q--){
    long long n, k, nn = 0;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> A[i];
    sort(A, A + n);
    for(int i=0; i<n; i++){
      int j = i;
      for(; A[j]==A[j+1] && j<n; j++);
      i = j;
      nn++;
    }
    long long l = 0, r = 3e9;
    while(l < r){
      long long m = (l + r) / 2;
      long long sum = nn * (m + 1) * (m + 1);
      for(int i=0; i<n-1; i++){
        int j = i + 1;
        long long d = A[j] - A[i];
        if(!d) continue;
        if(d % 2){
          long long s = m - d / 2;
          if(s > 0) sum -= s * (s + 1);
        }
        else{
          long long s = m - d / 2 + 1;
          if(s > 0) sum -= s * s;
        }
      }
      // cout << sum << " " << l << " " << r << "\n";
      if(sum < k) l = m + 1;
      else r = m;
    }
  cout << l << "\n";
  memset(A, 0, sizeof(A));
  }  

  return 0;
}
