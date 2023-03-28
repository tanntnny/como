#include<bits/stdc++.h>
using namespace std;

struct EDGE{
    int v, ip, jp;
};

queue<EDGE> QU;
vector<EDGE> G[44444];
int A[2222][2222], M[44444];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c; cin >> r >> c;
    for(int i=1; i<=r*c-1; i++){
        char opr;
        int u, v;
        cin >> u >> opr >> v;
        if(opr == 'U'){
            G[u].push_back({v, 1, 0});
            G[v].push_back({u, -1, 0});
        }
        else{
            G[u].push_back({v, 0, 1});
            G[v].push_back({u, 0, -1});
        }
    }
    int si = 1111, sj = 1111;
    M[0] = 1;
    QU.push({0, 1111, 1111});
    while(!QU.empty()){
        int u = QU.front().v, x = QU.front().ip, y = QU.front().jp;
        QU.pop();
        for(auto v : G[u]){
            int xx = x + v.ip, yy = y + v.jp;
            if(M[v.v]) continue;
            M[v.v] = 1;
            A[xx][yy] = v.v;
            si = min(si, xx), sj = min(sj, yy);
            QU.push({v.v, xx, yy});
        }
    }
    for(int i=si; i<si+r; i++){
        for(int j=sj; j<sj+c; j++) cout << A[i][j] << " ";
        cout << "\n";
    }

    return 0;
}