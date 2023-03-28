#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct NODE{
    int x, y, u;
};

int C[1111][1111], A[1111][1111], B[1111][1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c; cin >> r >> c;
    int si, sj, ei, ej; cin >> si >> sj >> ei >> ej;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++) cin >> C[i][j];
    }
    queue<NODE> QU;
    A[si][sj] = 1;
    QU.push({si, sj, 1});
    while(!QU.empty()){
        int x = QU.front().x, y = QU.front().y, u = QU.front().u;
        QU.pop();
        for(int dr=0; dr<4; dr++){
            int xx = x + di[dr], yy = y + dj[dr];
            if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
            if(A[xx][yy]) continue;
            A[xx][yy] = u + 1;
            if(C[xx][yy]) QU.push({xx, yy, u + 1});
        }
    }
    B[ei][ej] = 1;
    QU.push({ei, ej, 1});
    while(!QU.empty()){
        int x = QU.front().x, y = QU.front().y, u = QU.front().u;
        QU.pop();
        for(int dr=0; dr<4; dr++){
            int xx = x + di[dr], yy = y + dj[dr];
            if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
            if(B[xx][yy]) continue;
            B[xx][yy] = u + 1;
            if(C[xx][yy]) QU.push({xx, yy, u + 1});
        }
    }
    int cnt = 0, mn = 1<<30;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(C[i][j]) continue;
            if(A[i][j] && B[i][j]){
                cnt++;
                mn = min(mn, A[i][j] + B[i][j] - 1);
            }
        }
    }
    cout << cnt << "\n" << mn << "\n";

    return 0;
}