#include<bits/stdc++.h>
using namespace std;

struct NODE{
    int x, y, u;
};

vector<NODE> G[111][111];
queue<NODE> QU;
int A[111][111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c; cin >> r >> c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char c; cin >> c;
            if(c == 'R'){
                G[i][j].push_back({i, j + 1});
                G[i][j + 1].push_back({i, j});
            }
            else if(c == 'D'){
                G[i][j].push_back({i + 1, j});
                G[i + 1][j].push_back({i, j});
            }
            else if(c == 'B'){
                G[i][j].push_back({i, j + 1});
                G[i][j + 1].push_back({i, j});
                G[i][j].push_back({i + 1, j});
                G[i + 1][j].push_back({i, j});
            }
        }
    }
    A[1][1] = 1;
    QU.push({1, 1, 1});
    while(!QU.empty()){
        int x = QU.front().x, y = QU.front().y, u = QU.front().u;
        QU.pop();
        for(auto v : G[x][y]){
            int xx = v.x, yy = v.y;
            if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
            if(A[xx][yy] == u + 1){
                cout << u + 1 << "\n" << xx << " " << yy << "\n";
                return 0;
            }
            if(A[xx][yy]) continue;
            A[xx][yy] = u + 1;
            QU.push({xx, yy, u + 1});
        }
    }   

    return 0;
}