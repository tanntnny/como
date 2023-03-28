#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        int l = s.length();
        if(s == "0" && l == 1){ cout << "0\n"; continue; }
        bool fnd = false;
        for(int i=l-1; i>=1; i--){
            if(s[i] != '0') break;
            cout << 1;
            fnd = true;
        }
        if(!fnd) cout << 0;
        cout << "\n";
    }

    return 0;
}