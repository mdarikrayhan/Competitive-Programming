// LUOGU_RID: 159120269
#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl '\n'
#define double long double
const int MAX = 2e5 + 7;
const int mod = 1e9 + 7;
double d[MAX];
double eps = 1e-8;
double r[MAX];
void run() {
	double a, b, c;
	cin >> a >> b >> c;
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double ans = fabs(x1 - x2) + fabs(y1 - y2);
	
	double xt, yt;
	double ty = -a / b * x2 - c / b;
//	if(fabs(ty - (int)ty) > eps) ty = 2e14;
	double tx = -b / a * y2 - c / a;
//	if(fabs(tx - (int)tx) > eps) tx = 2e14;
	
	yt = -a / b * x1 - c / b;
//	if(fabs(yt - (int)yt) <= eps) {
//		if(ty != 2e14) {
			double now = fabs(yt - y1) + sqrt((x1 - x2) * (x1 - x2) + (ty - yt) * (ty - yt)) + fabs(y2 - ty);
			ans = min(ans, now);
//		}
//		if(tx != 2e14) {
			now = fabs(yt - y1) + sqrt((x1 - tx) * (x1 - tx) + (y2 - yt) * (y2 - yt)) + fabs(tx - x2);
			ans = min(ans, now);
//		}
//	}
	xt = -b / a * y1 - c / a;
//	if(fabs(xt - (int)xt) <= eps) {
//		if(ty != 2e14) {
			now = fabs(xt - x1) + sqrt((xt - x2) * (xt - x2) + (y1 - ty) * (y1 - ty)) + fabs(y2 - ty);
			ans = min(ans, now);
//		}
//		if(tx != 2e14) {
			now = fabs(xt - x1) + sqrt((xt - tx) * (xt - tx) + (y1 - y2) * (y1 - y2)) + fabs(tx - x2);
			ans = min(ans, now);
//		}
//	}
	cout << fixed << setprecision(10) << ans << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while(t--) {
		run();
	}
	return 0;
} 