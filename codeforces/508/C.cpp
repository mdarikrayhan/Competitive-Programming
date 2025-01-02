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
	int n, t, r;
	cin >> n >> t >> r;
	int ar[10002]{};
	vector<int>v(n);
	for (auto& i : v)
		cin >> i;
	if (t < r)
		return void(cout << -1);
	int curr = r,res=r;
	for (int i = v[0] - r; i < v[0]; i++) 
		ar[i + t] = -1;

	//if (curt != r)
		//return void(cout << -1);
	curr -= ar[v[0]] == -1;
	for (int j=1,i = v[0]+1; i <= v.back() and n>1; i++) {
		//cout << curr << '\n';
		if (i == v[j]) {
			int need = max(r-curr ,0);
			res += need;
			curr = r;
			for (int k = v[j] - need; k < v[j]; k++)
				 ar[k + t] = -1;
			j++;
		}
		curr -= ar[i] == -1;
	}
	cout << res;
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