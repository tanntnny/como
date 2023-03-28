#include <bits/stdc++.h>
using namespace std;


priority_queue<pair<int, int>> H;
int DP[555555];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k >> DP[1];
	H.push({-DP[1], 1});
	for(int i=2; i<=n; i++){
		int num; cin >> num;
		while(!H.empty() && i - H.top().second > k) H.pop();
		DP[i] = num - H.top().first;
		H.push({-DP[i], i});
	}
	cout << DP[n] << "\n";

	return 0;
}
