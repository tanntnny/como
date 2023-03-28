#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct NODE{
    int x, y, u;
};

int B[1111][1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int r, c; cin >> r >> c;
        pair<int, int> st, en;
        char A[1111][1111];
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                cin >> A[i][j];
                if(A[i][j] == 'A') st = {i, j};
                else if(A[i][j] == 'B') en = {i, j};
            }
        }
        queue<NODE> QU;
        QU.push({st.first, st.second, 0});
        while(!QU.empty()){
            int x = QU.front().x, y = QU.front().y, u = QU.front().u;
            QU.pop();
            for(int dr=0; dr<4; dr++){
                int xx = x + di[dr], yy = y + dj[dr];
                if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
                if(B[xx][yy] || A[xx][yy] == 'A' || A[xx][yy] == '#') continue;
                B[xx][yy] = u + 1;
                QU.push({xx, yy, u + 1});
            }           
        }
        cout << (B[en.first][en.second]?B[en.first][en.second]:-1) << "\n";
        memset(B, 0, sizeof(B));
    }

    return 0;
}