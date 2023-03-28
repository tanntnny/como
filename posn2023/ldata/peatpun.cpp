#include <bits/stdc++.h>
using namespace std;

int CNT[1111111];
stack<pair<int, int>> ST;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int l, q;
	cin >> l >> q;
	for(int i=0; i<l; i++){
		int h;
		cin >> h;
		while(!ST.empty() && ST.top().first >= h) ST.pop();
		if(ST.empty()) ST.push({h, 0});
		else ST.push({h, max(ST.top().second, h - ST.top().first)});
		CNT[i] = ST.top().second;
	}
	sort(CNT, CNT + l);
	while(q--){
		int x;
		cin >> x;
		cout << l - (upper_bound(CNT, CNT + l, x) - CNT) << "\n";
	}

	return 0;
}
