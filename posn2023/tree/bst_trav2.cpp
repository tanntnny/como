#include <bits/stdc++.h>
using namespace std;

int A[11111], L[11111], R[11111];

void preorder(int u){
	if(u == 0) return;
	cout << A[u] << " ";
	preorder(L[u]);
	preorder(R[u]);
}

void postorder(int u){
	if(u == 0) return;
	postorder(L[u]);
	postorder(R[u]);
	cout << A[u] << " ";
}

void inorder(int u){
	if(u == 0) return;
	inorder(L[u]);
	cout << A[u] << " ";
	inorder(R[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n >> A[1];
	for(int i=2; i<=n; i++){
		cin >> A[i];
		int run = 1;
		while(true){
			if(A[i] < A[run]){
				if(L[run] == 0){
					L[run] = i;
					break;
				}
				else run = L[run];
			}
			if(A[i] > A[run]){
				if(R[run] == 0){
					R[run] = i;
					break;
				}
				else run = R[run];
			}
		}
	}

	preorder(1);
	cout << "\n";
	postorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";

	return 0;
}
