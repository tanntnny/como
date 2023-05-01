#include <bits/stdc++.h>
using namespace std;

const int MXN = 111111;
int A[11][MXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, l;
    cin >> n >> w >> l;
    for(int i=1; i<=n ;i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int a;
            cin >> a;
            if(a - l < 0) A[i][0]++;
            else A[i][a - l]++;
            A[i][a + l + 1]--;
        }
        for(int j=1; j<=w; j++) A[i][j] += A[i][j - 1];
    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++) cout << A[i][j] << " ";
        cout << "\n";
    }
    */
    for(int i=1; i<=w; i++){
        bool fnd = false;
        for(int j=1; j<=n; j++) if(A[j][i] < 1) fnd = true;
        if(!fnd){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}