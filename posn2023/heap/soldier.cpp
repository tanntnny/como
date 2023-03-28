#include <bits/stdc++.h>
using namespace std;

struct HEAP{
	int id, rank, t;
	bool operator < (const HEAP & OTHER) const{
		if(rank != OTHER.rank) return rank < OTHER.rank;
		return t > OTHER.t;
	}
};

priority_queue<HEAP> H;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q, r, t = 0;
	cin >> q >> r;
	while(q--){
		int opr;
		cin >> opr;
		if(opr == 1){
			int id, rank;
			cin >> id >> rank;
			H.push({id, rank, t});
		}
		else{
			if(H.empty()) cout << "-1\n";
			else{
				cout << H.top().id << "\n";
				H.pop();
			}
		}
		t++;
	}

	return 0;
}
