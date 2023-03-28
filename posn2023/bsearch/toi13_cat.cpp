#include <bits/stdc++.h>
using namespace std;

long long A[2222222];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> A[i];
	long long left = 0, right = 1e10;
	while(left < right){
		long long mid = (left + right) / 2;
		stack<int> ST;
		bool check = true;
		for(int i=0; i<n && check; i++){
			if(A[i] > mid){
				if(ST.empty()) ST.push(A[i]);
				else if(ST.top() != A[i]){
					check = false;
					break;
				}
				else ST.pop();
			}
		}
		if(check) right = mid;
		else left = mid + 1;
	}
	cout << left << "\n";

	return 0;
}
