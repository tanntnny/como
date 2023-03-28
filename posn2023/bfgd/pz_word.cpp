#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q; cin >> q;
	while(q--){
		string s; cin >> s;
		int l = s.length();
		unordered_map<char, int> M;
		queue<char> QU;
		for(int i=0; i<l; i++) M[s[i]]++;
		for(int i=0; i<l; i++){
			if(M[s[i]] == 1){ QU.push(s[i]); M[s[i]] = -1; }
			else if(M[s[i]] > 1){
				int j = i, idx = i;
				char mn = s[i];
				while((j < l && M[s[j]] > 1) || M[s[j]] < 0){
					if(s[j] < mn && M[s[j]] > 0) mn = s[j], idx = j;
					M[s[j]]--;
					j++;
				}
				if(j < l && s[j] < mn) mn = s[j], idx = j;
				for(int k=idx+1; k<j; k++) M[s[k]]++;
				i = idx;
				M[mn] = -1;
				QU.push(mn);
			}
		}
		char last = 'a';
		while(!QU.empty()){
			char now = QU.front();
			QU.pop();
			for(char c='a'; c<now; c++){
				if(!M[c]){ cout << c; M[c] = -1; last = max(last, c); }
			}
			cout << now;
			M[now] = -1;
			last = max(last, now);
		}
		for(char c=last+1; c<='z'; c++){
			if(!M[c]){ cout << c; M[c] = -1; }
		}
		cout << "\n";
	}

	return 0;
}
