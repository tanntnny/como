#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	while(q--){
		queue<char> QU;
		char S[111111];
		int k, mx = 0, n = 0;
		cin >> S >> k;
		int l = strlen(S);
		for(int i=0; i<l; i++){
			if(S[i] == 'A') QU.push('A');
			else{
				n++;
				QU.push('B');
				if(n > k){
					n--;
					while(QU.front() != 'B') QU.pop();
					QU.pop();
				}
			}
			if(QU.size() > mx) mx = QU.size();
		}
		cout << mx << "\n";
	}

	return 0;
}
