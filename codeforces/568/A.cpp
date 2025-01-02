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
const int N = 2e6 + 3, mod = 1e9 + 7;
bool ar[N]{};

int rev(int a) {
	int res = 0;
	for (; a; res = 10 * res + a % 10, a /= 10);
	return res;
}

void solve() {
	int p, q;
	cin >> p >> q;
	int pr = 0,pl=0,res=0;
	ar[1] = 1;
	for (int i = 1; i < N; i++) {
		if (!ar[i]) {
			for (int j = i ; j < N; j += i) 
				ar[j] = 1;
			pr++;
		}
		pl += rev(i)==i;
		if (q * pr <= p * pl)// pr <= p / q * pl
			res = i;		//  pr*q <= p*pl
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