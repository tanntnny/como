#include <bits/stdc++.h>
using namespace std;

struct HEAP{
	int u, d, t, v;
	bool operator < (const HEAP & OTHER) const{
		if(u != OTHER.u) return u > OTHER.u;
		return t > OTHER.t;
	}
};

priority_queue<HEAP> H;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int opr; cin >> opr;
		if(opr == 1){
			int u, d; cin >> u >> d;
			H.push({u, d, 2, 0});
		}
		else if(opr == 2){
			int u; cin >> u;
			H.push({u, 9999999, 3, 0});
		}
		else if(opr == 3){
			int u, d, v; cin >> u >> d >> v;
			H.push({u, d, 1, v});
		}
		else if(opr == 4){
			while(!H.empty() && H.top().d <= i){
				if(H.top().t == 1){
					H.push({H.top().v, 9999999, 2, 0});
				}
				H.pop();
			}
			if(H.empty()) cout << "GREAN\n";
			else{
				cout << H.top().u << "\n";
				H.pop();
			}
		}
	}

	return 0;
}
