#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct NODE{
    int x, y;
};

queue<NODE> QU;
char C[1111][1111];
int A[1111][1111], B[1111111], r, c;

int sum(int x, int y){
    int a = 0;
    for(int dr=0; dr<4; dr++){
        int xx = x + di[dr], yy = y + dj[dr];
        if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
        if(A[xx][yy] == -1) a++;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> C[i][j];
            if(i == 1 || i == r || j == 1 || j == c){
                if(C[i][j] == '.') QU.push({i, j}), A[i][j] = -1;
            }
        }
    }
    while(!QU.empty()){
        int x = QU.front().x, y = QU.front().y;
        QU.pop();
        for(int dr=0; dr<4; dr++){
            int xx = x + di[dr], yy = y + dj[dr];
            if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
            if(A[xx][yy] || C[xx][yy] == 'X') continue;
            A[xx][yy] = -1;
            QU.push({xx, yy});
        }
    }
    int mx = 0, idx = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(!A[i][j]){
                idx++;
                A[i][j] = 1;
                QU.push({i, j});
                B[idx] += sum(i, j);
                while(!QU.empty()){
                    int x = QU.front().x, y = QU.front().y;
                    QU.pop();
                    for(int dr=0; dr<4; dr++){
                        int xx = x + di[dr], yy = y + dj[dr];
                        if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
                        if(C[xx][yy] == '.' || A[xx][yy]) continue;
                        A[xx][yy] = 1;
                        B[idx] += sum(xx, yy);
                        QU.push({xx, yy});
                    }
                }
                mx = max(mx, B[idx]);
            }
        }
    }
    cout << mx << "\n";

    return 0;
}