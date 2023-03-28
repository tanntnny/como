#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> M;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	for(int i=0; i<n; i++){
		string s, r; cin >> s >> r;
		M[s] = r;
	}
	for(int i=0; i<m; i++){
		string s; cin >> s;
		cout << M[s] << " ";
	}

	return 0;
}
