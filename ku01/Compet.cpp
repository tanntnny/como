#include <bits/stdc++.h>
using namespace std;

const int MXN = 111;
int A[MXN][MXN];

queue<int> QU;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> A[i][j];
    for(int i=1; i<=n; i++) QU.push(i);

    while(QU.size() > 1){
        int a = QU.front(); QU.pop();
        int b = QU.front(); QU.pop();
        if(A[a][b] == a){
            if(c == b){ QU.push(b); c = 0; }
            else QU.push(a);
        }
        else{
            if(c == a){ QU.push(a); c = 0; }
            else QU.push(b);
        }
    }
    cout << QU.front();
;
    return 0;
}