#include<bits/stdc++.h>
using namespace std;

struct MATRIX{
    long long A[5][5];
} M[111], ANS;

long long n, a, m;

MATRIX F(MATRIX C, MATRIX B){
    MATRIX T;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            T.A[i][j] = 0;
            for(int k=0; k<n; k++){
                T.A[i][j] += C.A[i][k] * B.A[k][j];
                T.A[i][j] %= m;
            }
        }
    }
    return T;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> M[0].A[i][j];
    }
    ANS = M[0];
    cin >> a >> m;
    if(a == 0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) cout << 1 % m << " ";
                else cout << "0 ";
            }
            cout << "\n";
        }
        return 0;
    }
    a--;
    for(int i=1; i<=63; i++) M[i] = F(M[i - 1], M[i - 1]);
    for(int i=0; i<=63; i++){
        if((1ll << i) & a) ANS = F(ANS, M[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << ANS.A[i][j] << " ";
        cout << "\n";
    }

    return 0;
}