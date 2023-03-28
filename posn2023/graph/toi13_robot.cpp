#include<bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct NODE{
    int x, y, u;
};

queue<NODE> QU;
char C[2222][2222];
int A[2222][2222];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c; cin >> r >> c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> C[i][j];
            if(C[i][j] == 'X'){
                A[i][j] = 1;
                QU.push({i, j, 1});
            }
        }
    }
    while(!QU.empty()){
        int x = QU.front().x, y = QU.front().y, u = QU.front().u;
        QU.pop();
        for(int dr=0; dr<4; dr++){
            int xx = x + di[dr], yy = y + dj[dr];
            if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
            if(C[xx][yy] == 'W' || A[xx][yy]) continue;
            A[xx][yy] = u + 1;
            QU.push({xx, yy, u + 1});
        }
    }
    int cnt = 0, sum = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(C[i][j] == 'A'){
                if(!A[i][j]) continue;
                cnt++;
                sum += (2 * (A[i][j] - 1));
            }
        }
    }
    cout << cnt << "\n" << sum << "\n";

    return 0;
}