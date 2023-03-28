#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	while(q--){
		long long sum, pro;
		bool check = false;
		cin >> sum >> pro;
		long long left = 1, right = sum;
		while(left < right){
			long long mx = (left + right) / 2;
			long long mn = sum - mx;
			// cout << mn << " " << mx * mn << " " << (mx * mn) / mn << " " << mx << "\n";
			if(mx * mn > pro || ((mx * mn) / mn) != mx) right = mx;
			else if(mx * mn < pro) left = mx + 1;
			else{
				check = true;
				cout << min(mx, mn) << " " << max(mx, mn) << "\n";
				break;
			}
		}
		if(!check) cout << "No answer\n";
	}

	return 0;
}
