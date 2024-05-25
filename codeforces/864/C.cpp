#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 5e5 + 3, mod = 1e9 + 7;

void solve() {
	int a, b, f, k;
	cin >> a >> b >> f >> k;
	int dir = 1,curf=b,invalid=0,res=0;
	while (k) {
		//cout << dir << " " << curf << '\n';
		if (dir == 1) {
			if (f > b)
				invalid = 1;
			curf -= f;
			if ((k > 1 and (a - f) * 2 > b) or (k == 1 and (a - f) > b))
				invalid = 1;
			else if ((k > 1 and (a - f) * 2 > curf))
				curf = b - (a - f) , res++;
			else if ((k == 1 and (a - f) > curf))
				 res++;
			else curf -= a - f ;
			dir = 0;
		}
		else {
			if (k > 1 and  (f * 2) > b)
				invalid = 1;
			curf -= (a - f);
			 if (k > 1 and curf < f * 2)
				curf = b - f , res++;
			else if (k == 1 and curf < f)
				res++;
			else curf -= f ;
			dir = 1;
		}
		k--;
	}
	cout << (invalid?-1:res) << '\n';
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