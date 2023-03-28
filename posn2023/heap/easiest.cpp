#include <bits/stdc++.h>
using namespace std;

priority_queue<int> H;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	while(q--){
		char opr;
		cin >> opr;
		if(opr == 'A'){
			int x;
			cin >> x;
			H.push(-x);
		}
		else{
			if(H.empty()) cout << "-1\n";
			else{
				cout << -H.top() << "\n";
				H.pop();
			}
		} 
	}

	return 0;
}
