#include <bits/stdc++.h>
using namespace std;

struct NODE{int x, y;} A[111111];

bool minx(NODE a, NODE b){ return a.x < b.x; }
bool miny(NODE a, NODE b){ return a.y < b.y; }

double DIST(NODE a, NODE b){ return sqrt(1.0*(a.x - b.x)*(a.x - b.x) + 1.0*(a.y - b.y)*(a.y - b.y)); }
double BF(NODE a[], int n){
	double mn = 2e9;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++) mn = min(mn, DIST(a[i], a[j]));
	}
	return mn;
}

double SC(NODE s[], int n, double d){
	double mn = d;
	sort(s, s + n, miny);
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n && (s[j].y - s[i].y) < mn; j++){
			mn = min(mn, DIST(s[i], s[j]));
		}
	}
	return mn;
}

double CLOSEST(NODE p[], int n){
	if(n <= 3) return BF(p, n);
	int mid = n / 2;
	NODE midp = p[mid];
	double dl = CLOSEST(p, mid);
	double dr = CLOSEST(p + mid, n - mid);
	double d = min(dl, dr);
	NODE s[n + 2];
	int j = 0;
	for(int i=0; i<n; i++){
		if(abs(p[i].x - midp.x) < d) s[j] = p[i], j++;
	}
	return min(d, SC(s, j, d));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int w; cin >> w;
	for(int i=0; i<w; i++){
		int n, r, d; cin >> n >> r >> d;
		for(int j=0; j<n; j++) cin >> A[j].x >> A[j].y;
		sort(A, A + n, minx);
		double dist = CLOSEST(A, n);
		cout << (d <= dist - 2 * r ? "Y" : "N") << "\n";
	}

	return 0;
}
