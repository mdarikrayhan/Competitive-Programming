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
const int N = 1e7 + 3, mod = 1e9 + 9;

void solve() {
	ll x, y, m;
	cin >> x >> y >> m;
	if (x >= m or y >= m)
		return void(cout << 0);
	if ((x <= 0 and y <= 0 and m > x and m > y))//we can not maximize
		return void(cout << -1);
	else if ((x >= 0 and y >= 0 and x > m and y > m))//we can not minimize
		return void(cout << -1);
	if (x > y)
		swap(x, y);
	if (m < 0)
		x *= -1, y *= -1, m *= -1, swap(x, y);
	ll res = 0;
	if (abs(x) > y)
		res += (abs(x) + y - 1) / y, x = (x % y + y) % y;
	while (x < m and y < m) {
		x += y;
		if (x > y)
			swap(x, y);
		res++;
	}
	cout << res << '\n';
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