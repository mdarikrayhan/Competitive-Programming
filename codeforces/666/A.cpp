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
const int N = 1e6 + 3, mod = 1e9 + 9;
int n;
bool dp[10002][2]{};
	string s;
set<string>res;
void f(int i, int amt,string c) {
	string b = s.substr(n - i, amt);//from end 2 or 3
	if (dp[i][amt] or i>n-5 or c==b) 
		return;
	dp[i][amt] = 1;
	res.insert(b);
	f(i + 2, 2, b);
	f(i + 3, 3, b);
}
void solve() {
	cin >> s;
	n = s.size();
	f(3, 3, "");
	f(2, 2, "");
	cout << res.size() << '\n';
	for (auto i : res)
		cout << i << " ";
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