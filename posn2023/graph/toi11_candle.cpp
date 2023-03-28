#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct NODE{
    int x, y;
};

int A[2222][2222];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c; cin >> r >> c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char inp; cin >> inp;
            A[i][j] = inp - '0';
        }
    }
    int cnt = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(A[i][j]){
                cnt++;
                queue<NODE> QU;
                A[i][j] = 0;
                QU.push({i, j});
                while(!QU.empty()){
                    int x = QU.front().x, y = QU.front().y;
                    QU.pop();
                    for(int dr=0; dr<8; dr++){
                        int xx = x + di[dr], yy = y + dj[dr];
                        if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
                        if(!A[xx][yy]) continue;
                        A[xx][yy] = 0;
                        QU.push({xx, yy});
                    }
                }
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}