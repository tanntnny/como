#include <bits/stdc++.h>
using namespace std;

int nI[222222], mI[222222], nJ[222222], mJ[222222];
int nX[222222], mX[222222], nY[222222], mY[222222];
int f[222222];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c, q, mx = -1;
  cin >> r >> c >> q;
  for(int i=0; i<=200001; i++){nI[i] = 2000, nJ[i] = 2000, nX[i] = 2000, nY[i] = 2000;}
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      int n;
      cin >> n;
      nI[n] = min(nI[n], i), mI[n] = max(mI[n], i);
      nJ[n] = min(nJ[n], j), mJ[n] = max(mJ[n], j);
      f[n] = 1;
      mx = max(mx, n);
    }
  }
  for(int i=200000; i>=0; i--){
    nX[i] = min(nX[i + 1], nI[i]);
    mX[i] = max(mX[i + 1], mI[i]);
    nY[i] = min(nY[i + 1], nJ[i]);
    mY[i] = max(mY[i + 1], mJ[i]);
  }
  while(q--){
    int a, b;
    cin >> a >> b;
    if(a == 1){
      if(!f[b]){cout << "0\n"; continue;}
      cout << (mI[b] - nI[b] + mJ[b] - nJ[b] + 2) * 2 << "\n";
    }
    else{
      if(b > mx){cout << "0\n"; continue;}
      // cout << nX[b] << " " << mX[b] << " " << nY[b] << " " << mY[b] << "\n";
      cout << (mX[b] - nX[b] + mY[b] - nY[b] + 2) * 2 << "\n";
    }
  }

  return 0;
}

/*

5 6 6
0 0 0 2 0 1
0 5 0 0 1 1
0 0 7 5 2 0
0 5 0 0 0 0
0 0 3 0 6 0
1 5
2 2
2 7
1 1
1 4
2 10

*/
