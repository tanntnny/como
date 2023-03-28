#include <bits/stdc++.h>
using namespace std;

struct NODE{
	int i, t;
	bool operator < (const NODE & OTHER) const{
		if(t != OTHER.t) return t > OTHER.t;
		return i > OTHER.i;
	}
};

priority_queue<NODE> H;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for(int i=0; i<k; i++) H.push({i + 1, 0});
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		cout << H.top().i << "\n";
		H.push({H.top().i, H.top().t + x});
		H.pop();
	}

	return 0;
}
