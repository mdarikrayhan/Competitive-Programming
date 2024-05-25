#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define f first
#define s second
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e5 + 3, mod = 1e9 + 9;
double dp[N][2][2]{};
double ax, ay, bx, by, tx, ty;
double dist(double x1, double y1,double x2, double y2) {
	return  sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));;
}
int n;

void solve() {
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	cin >> n;
	double fa = 1e12, fb = 1e12, fab = 1e12;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x>>y;
		sum += 2 * dist(x, y, tx, ty);
		double f = dist(x, y, ax, ay)-dist(x,y,tx,ty);
		double g= dist(x, y, bx, by)- dist(x, y, tx, ty);
		fab = min(fab, min(fa + g, fb + f));
		fa = min(fa, f);
		fb = min(fb, g);
	}
	cout << fixed << setprecision(7) << sum + min({ fab,fa,fb });
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
}