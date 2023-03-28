#include <bits/stdc++.h>
using namespace std;

const int MUL[] = {0, 104, 108, 116};

stack<int> OPR, ANS;

void calculate(){
	int o1 = ANS.top();
	ANS.pop();
	int o2 = ANS.top();
	ANS.pop();
	ANS.push((o1 + o2) * MUL[OPR.top()] / 100);
	OPR.pop();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	char S[11111];
	cin >> S;
	int l = strlen(S);
	for(int i=0; i<l; i++){
		if(S[i] == '[') OPR.push(-1);
		else if(S[i] == ']'){
			while(OPR.top() != -1) calculate();
			OPR.pop();
		}
		else if(isdigit(S[i])){
			if(OPR.empty()) OPR.push(S[i] - '0');
			else if(OPR.top() < S[i] - '0') OPR.push(S[i] - '0');
			else{
				while(!OPR.empty() && S[i] - '0' <= OPR.top()) calculate();
				OPR.push(S[i] - '0');
			}
		}
		else ANS.push(20);
	}
	while(!OPR.empty()) calculate();
	cout << ANS.top() << "\n";

	return 0;
}
