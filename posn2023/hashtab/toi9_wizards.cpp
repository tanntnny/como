#include <bits/stdc++.h>
using namespace std;

const int SZ = 5000011;

int SUM[2][SZ], X[4][5555], Y[4][5555], HASH[SZ];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x, y, n; cin >> x >> y >> n;
	for(int i=0; i<4; i++){
		for(int j=0; j<n; j++) cin >> X[i][j] >> Y[i][j];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int xnow = X[0][i] + X[1][j];
			int ynow = Y[0][i] + Y[1][j];
			long long idx = (((xnow + 3 * ynow) % SZ) + SZ) % SZ;
			while(HASH[idx]){
				idx++;
				idx %= SZ;
			}
			HASH[idx] = (1500 * i) + j + 1;
			SUM[0][idx] = xnow;
			SUM[1][idx] = ynow;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=n; j++){
			int xnow = x - (X[2][i] + X[3][j]);
			int ynow = y - (Y[2][i] + Y[3][j]);
			long long idx = (((xnow + 3 * ynow) % SZ) + SZ) % SZ;
			while(HASH[idx]){
				if(SUM[0][idx] == xnow && SUM[1][idx] == ynow){
					int k = HASH[idx] - 1;
					cout << X[0][k / 1500] << " " << Y[0][k / 1500] << "\n";
					cout << X[1][k % 1500] << " " << Y[1][k % 1500] << "\n";
					cout << X[2][i] << " " << Y[2][i] << "\n";
					cout << X[3][j] << " " << Y[3][j] << "\n";
					return 0;
				}
				idx++;
				idx %= SZ;
			}
		}
	}

	return 0;
}
