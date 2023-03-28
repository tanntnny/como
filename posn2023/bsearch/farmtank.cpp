#include<bits/stdc++.h>
using namespace std;

int A[111111];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> A[i];
	long long left = 1, right = 1e18;
	while(left < right){
		long long mid = (left + right) / 2;
		long long sum = 0;
		for(int i=0; i<n; i++) sum += (mid / A[i]);
		if(sum < m) left = mid + 1;
		else right = mid;
	}
	cout << left << "\n";

	return 0;
}
