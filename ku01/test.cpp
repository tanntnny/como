#include <iosteam>
using namespace std;

const int MXN = 111;
int X[MXN], Y[MXN], Z[MXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, t;
  cin >> n >> t;
  
  if(t == 2){
      cin >> Z[1];
      for(int i=2; i<=n; i++){
        cin >> Z[i];
        if(Z[i] == 3 * Z[i - 1] + 1) Z[i] = Z[i - 1] + 1;
        else Z[i] = Z[i - 1] - 1;
      }
    }
  Y[0] = n;
  for(int i=1; i<=n; i++){
    if(Y[i] > Y[i - 1]) cout << "1\n";
    else cout << "0\n";
  }
  
  return 0;
}
