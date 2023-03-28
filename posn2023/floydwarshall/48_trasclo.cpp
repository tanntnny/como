#include <bits/stdc++.h>
using namespace std;

int ADJ[555][555];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cin >> ADJ[i][j];
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
				ADJ[i][j] = ADJ[i][j] | (ADJ[i][k] & ADJ[k][j]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cout << ADJ[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
