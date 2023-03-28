#include <bits/stdc++.h>
using namespace std;

struct NODE{int x, y;};

stack<NODE> ST;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int x, y; cin >> x >> y;
		if(x == y) continue;
		if(ST.empty()) ST.push({x, y});
		else{
			if(ST.top().y == x){
				int ix = ST.top().x;
				ST.pop();
				if(ix != y) ST.push({ix, y});
			}
			else ST.push({x, y});
		}
	}
	cout << ST.size() << "\n";

	return 0;
}
