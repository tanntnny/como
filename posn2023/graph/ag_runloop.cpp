#include <bits/stdc++.h>
using namespace std;
// D L R U
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, -1, 1, 0};
const char dc[] = "DLRU";

struct NODE{
    int x, y, w;
};

queue<NODE> QU;
int A[66][1111][1111];
char C[1111][1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int r, c, k; cin >> r >> c >> k;
        int si, sj, cnt = 0;
        string s = "";
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                cin >> C[i][j];
                if(C[i][j] == 'P') si = i, sj = j;
            }
        }
        if(k % 2){ cout << "Can't do\n"; continue; }
        QU.push({si, sj, 0});
        while(!QU.empty()){
            int x = QU.front().x, y = QU.front().y, w = QU.front().w;
            QU.pop();
            for(int dr=0; dr<4; dr++){
                int xx = x + di[dr], yy = y + dj[dr];
                if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
                if(C[xx][yy] != '.' || A[q][xx][yy]) continue;
                A[q][xx][yy] = w + 1;
                QU.push({xx, yy, w + 1});
            }
        }
        while(cnt < k){
            for(int dr=0; dr<4; dr++){
                int xx = si + di[dr], yy = sj + dj[dr];
                if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
                if(A[q][xx][yy] > k - cnt - 1 || C[xx][yy] == '#') continue;
                cnt++;
                s += dc[dr];
                si = xx, sj = yy;
                break;
            }
            if(!cnt) break;
        }
        if(cnt) cout << s << "\n";
        else cout << "Can't do\n";
    }

    return 0;
}