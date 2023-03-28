#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct NODE{
    int x, y;
};

queue<NODE> QU;
int A[1111][1111], NI[1111111], XI[1111111], NJ[1111111], XJ[1111111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, q; cin >> r >> c >> q;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char inp; cin >> inp;
            if(inp == '#') A[i][j] = -1;
            else A[i][j] = 0;
        }
    }
    for(int i=1; i<=1e6+1e5; i++) NI[i] = NJ[i] = 1<<30;
    int idx = 1;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(A[i][j] == 0){
                A[i][j] = idx;
                NI[idx] = min(NI[idx], i);
                NJ[idx] = min(NJ[idx], j);
                XI[idx] = max(XI[idx], i);
                XJ[idx] = max(XJ[idx], j);
                QU.push({i, j});
                while(!QU.empty()){
                    int x = QU.front().x, y = QU.front().y;
                    QU.pop();
                    for(int dr=0; dr<4; dr++){
                        int xx = x + di[dr], yy = y + dj[dr];
                        if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
                        if(A[xx][yy]) continue;
                        A[xx][yy] = idx;
                        NI[idx] = min(NI[idx], xx);
                        NJ[idx] = min(NJ[idx], yy);
                        XI[idx] = max(XI[idx], xx);
                        XJ[idx] = max(XJ[idx], yy);
                        QU.push({xx, yy});
                    }
                }
                idx++;
            }
        }
    }
    while(q--){
        int r1, c1, r2, c2, x, y; cin >> r1 >> c1 >> r2 >> c2 >> x >> y;
        idx = A[x][y];
        bool check = false;
        if(NI[idx] <= r1 || XI[idx] >= r2) check = true;
        if(NJ[idx] <= c1 || XJ[idx] >= c2) check = true;
        cout << (check ? "YES\n" : "NO\n");
    }

    return 0;
}