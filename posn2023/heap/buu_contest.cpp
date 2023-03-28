#include <bits/stdc++.h>
using namespace std;

int k, d;

struct HEAP{
	int u, t;
	bool operator < (const HEAP & OTHER) const{
		int v1 = u + k * (d - t), v2 = OTHER.u + k * (d - OTHER.t);
		return v1 < v2;
	}
};

priority_queue<HEAP> H;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q >> k;
	long long sum = 0;
	for(d=1; d<=q; d++){
		int n, b; cin >> n >> b;
		for(int i=0; i<n; i++){
			int u; cin >> u;
			H.push({u, d});
		}
		for(int i=0; i<b; i++){
			sum += H.top().u + k * (d - H.top().t);
			H.pop();
		}
	}
	cout << sum << "\n";

	return 0;
}
