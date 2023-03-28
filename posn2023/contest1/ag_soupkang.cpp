#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

struct EDGE{
    int x, y, ;
    bool operator < (const EDGE & OTHER) const{
        return ()
    }
};

priority_queue<EDGE> DIJS;
int DIS[555][555];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char p; cin >> p;
            DIS[i][j] = 1<<30;
            if(p != '.') DIJS.push({i, j, 0}), DIS[i][j] = 0;
        }
    }

    while(!DIJS.empty()){
        int x = DIJS.top().x, y = DIJS.top().y, w = DIJS.top().w;
        DIJS.pop();
        for(int dr=0; dr<4; dr++){
            int xx = x + di[dr], yy = y + dj[dr];
            if(xx < 1 || xx > r || yy < 1 || yy > c) continue;
            int d = (xx - x) * (xx - x) + (yy - y) * (yy - y);
            if(DIS[xx][yy] <= d) continue;
            DIS[xx][yy] = d;
            DIJS.push({xx, yy});
        }
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        
    }

    return 0;
}