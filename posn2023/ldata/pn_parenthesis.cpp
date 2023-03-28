#include <bits/stdc++.h>
using namespace std;

stack<int> ST;
int A[55555];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	char S[55555];
	cin >> n >> S;
	int l = strlen(S), mx = 0, cnt = 0;
	for(int i=0; i<l; i++){
		if(S[i] == '(') ST.push(1);
		else{
			int top = ST.top();
			A[top]++;
			mx = max(mx, top);
			cnt++;
			ST.pop();
			if(!ST.empty()){
				int mxx = max(ST.top(), top + 1);
				ST.pop();
				ST.push(mxx);
			} 
		}
	}
	cout << cnt << "\n" << mx << "\n";
	for(int i=1; i<=mx; i++) cout << A[i] << " ";
	cout << "\n";

	return 0;
}
