#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct NODE{
    int x, y, w;
};

queue<NODE> QU;
vector<NODE> VT;
int A[1111][1111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        int r, c; cin >> r >> c;
        int si, sj, ei, ej;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                char inp; cin >> inp;
                if(inp == 'S') si = i, sj = j;
                else if(inp == 'E') ei = i, ej = j, A[i][j] = 1;
                else if(inp == '#') A[i][j] = -1;
                else if(inp == '0') continue;
                else{
                    VT.push_back({i, j, (int)inp - '0'});
                }
            }
        }
        QU.push({ei, ej, 0});
        while(!QU.empty()){
            int x = QU.front().x, y = QU.front().y, w = QU.front().w;
            QU.pop();
            for(int dr=0; dr<4; dr++){
                int xx = x + di[dr], yy = y + dj[dr];
                if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
                if(A[xx][yy]) continue;
                A[xx][yy] = w + 1;
                QU.push({xx, yy, w + 1});
            }
        }
        int st = A[si][sj], sum = 0;
        for(auto x : VT){
            if(A[x.x][x.y] && A[x.x][x.y] <= st) sum += x.w;
        }
        if(st == 0) cout << "-1\n";
        else cout << sum << "\n";
        VT.clear();
        memset(A, 0, sizeof(A));
    }

    return 0;
}