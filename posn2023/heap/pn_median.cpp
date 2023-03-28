#include <bits/stdc++.h>
using namespace std;

priority_queue<int> mn, mx;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int num; cin >> num;
    printf("%.1lf\n", (double)num);
    mn.push(-num);
    for(int i=2; i<=n; i++){
        cin >> num;
        if(num >= -mn.top()) mn.push(-num);
        else mx.push(num);
        if(mn.size() == mx.size() + 2){
            mx.push(-mn.top());
            mn.pop();
        }
        else if(mx.size() == mn.size() + 2){
            mn.push(-mx.top());
            mx.pop();
        }
        if(i % 2) printf("%.1lf\n", (mn.size() > mx.size() ? -((double)mn.top()) : (double)mx.top()));
        else printf("%.1lf\n", (double)(mx.top() - mn.top()) * 0.5);
    }

    return 0;
}