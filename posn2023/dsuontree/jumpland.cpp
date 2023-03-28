#include <bits/stdc++.h>
using namespace std;

struct EDGE{
    int u, v;
    double t;
    bool operator < (const EDGE & OTHER) const{
        return t < OTHER.t;
    }
};

vector<EDGE> VT;
stack<pair<int, int>> OPR;
int A[1111111], B[1111111], SZ[1111111], P[1111111], ans = 0;

int root(int u){
    while(u != P[u]) u = P[u];
    return u;
}

void rollback(){
    while(!OPR.empty()){
        SZ[OPR.top().first] -= SZ[OPR.top().second];
        P[OPR.top().second] = OPR.top().second;
        OPR.pop();
    }
}

void merge(int u, int v){
    if(B[u] != B[v]){
        double t = (1.0 * A[u] - A[v]) / (1.0 * B[v] - B[u]);
        if(t < 0) return;
        VT.push_back({u, v, t});
    }
    else if(A[u] == A[v]){
        int ru = root(u), rv = root(v);
        if(ru == rv) return;
        ans = max(ans, SZ[ru] + SZ[rv]);
        if(SZ[ru] <= SZ[rv]) SZ[rv] += SZ[ru], P[ru] = rv;
        else SZ[ru] += SZ[rv], P[rv] = ru;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=0; i<n*n; i++) cin >> A[i];
    for(int i=0; i<n*n; i++) cin >> B[i];
    for(int i=0; i<n*n; i++) SZ[i] = 1, P[i] = i;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i + 1 < n) merge(i*n+j, (i+1)*n+j);
            if(j + 1 < n) merge(i*n+j, i*n+j+1);
        }
    }
    VT.push_back({0, 0, -1});
    sort(VT.begin(), VT.end());
    // for(auto x : VT) cout << x.t << " ";
    for(int i=1; i<(int)VT.size(); i++){
        if(VT[i - 1].t != VT[i].t) rollback();
        int ru = root(VT[i].u), rv = root(VT[i].v);
        if(ru == rv) continue;
        ans = max(ans, SZ[ru] + SZ[rv]);
        if(SZ[ru] <= SZ[rv]){
            SZ[rv] += SZ[ru];
            P[ru] = rv;
            OPR.push({rv, ru});
        }
        else{
            SZ[ru] += SZ[rv];
            P[rv] = ru;
            OPR.push({ru, rv});
        }
    }
    cout << ans << "\n";

    return 0;
}