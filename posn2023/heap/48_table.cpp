#include <bits/stdc++.h>
using namespace std;

struct HEAP{
	int u, r, c, t;
	bool operator < (const HEAP & OTHER) const{
		return u > OTHER.u;
	}
};

priority_queue<HEAP> H;
pair<int, int> A[333][5555];
int M[333];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, c, q; cin >> r >> c >> q;
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++) H.push({0, i, j, 0});
	}
	for(int i=1; i<=q; i++){
		int opr; cin >> opr;
		if(opr == 1){
			int r, c, x; cin >> r >> c >> x;
			if(A[r][5050].second >= A[r][c].second){
				M[r]++;
			}
			A[r][c] = {x, i};
			H.push({x, r, c, i});
		}
		else if(opr == 2){
			int r, x; cin >> r >> x;
			M[r] = 0;
			A[r][5050] = {x, i};
			H.push({x, r, 5050, i});
		}
		else if(opr == 3){
			int r, c; cin >> r >> c;
			if(A[r][5050].second >= A[r][c].second) cout << A[r][5050].first << "\n";
			else cout << A[r][c].first << "\n";
		}
		else if(opr == 4){
			bool check = true;
			while(!H.empty()){
				HEAP top = H.top();
				if(A[top.r][top.c].second > top.t) H.pop();
				else if(top.c != 5050 && (A[top.r][5050].second > top.t)) H.pop();
				else if(top.c == 5050 && M[top.r] >= c) H.pop();
				else{
					check = false;
					cout << top.u << "\n";
					break;
				}
			}
			if(check) cout << "0\n";
		}
	}

	return 0;
}
