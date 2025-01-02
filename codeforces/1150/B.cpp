#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include <stack>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <deque>
#include <complex>
#include <numeric>

using namespace std;

template<typename typC, typename typD>
istream& operator>>(istream& cin, pair<typC, typD>& a)
{
	return cin >> a.first >> a.second;
}

template<typename typC>
istream& operator>>(istream& cin, vector<typC>& a)
{
	for (auto& x : a)
		cin >> x;
	return cin;
}

template<typename typC, typename typD>
ostream& operator<<(ostream& cout, const pair<typC, typD>& a)
{
	return cout << a.first << ' ' << a.second;
}

template<typename typC, typename typD>
ostream& operator<<(ostream& cout, const vector<pair<typC, typD>>& a)
{
	for (auto& x : a)
		cout << x << '\n';
	return cout;
}

template<typename typC>
ostream& operator<<(ostream& cout, const vector<typC>& a)
{
	int n = a.size();
	if (!n)
		return cout;
	cout << a[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << a[i];
	return cout;
}

template<typename typC>
long long sumv(const vector<typC>& a) {
	long long sum = 0;
	for (const auto& x : a) {
		sum += x;
	}
	return sum;
}

template<typename typC>
typC minv(const vector<typC>& a) {

	typC minVal = a[0];
	for (const auto& x : a) {
		if (x < minVal) {
			minVal = x;
		}
	}
	return minVal;
}

template<typename typC>
typC maxv(const vector<typC>& a) {

	typC maxVal = a[0];
	for (const auto& x : a) {
		if (x > maxVal) {
			maxVal = x;
		}
	}
	return maxVal;
}

namespace myTemplate
{
#define ll long long
#define db double
#define str string
#define el '\n'
#define range(a) a.begin(),a.end()
#define fi(n) for(int i=0;i<n;i++)
#define fii(n) for(int i=1;i<=n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define fjj(n) for(int j=1;j<=n;j++)
#define fk(n) for(int k=0;k<n;k++)
#define fkk(n) for(int k=1;k<=n;k++)
#define F(i,s,t) for(int i=s;i<t;i++)
#define ffi(a) for(auto i: a)
#define ffj(a) for(auto j: a)
#define ffk(a) for(auto k: a)
#define w(q) while(q--)
#define len(a) (int)(a).size()
#define srt(a) sort(range(a))
#define srto(a) sort(range(a),option)
#define rev(a) reverse(range(a))
#define vi vector<int> 
#define vl vector<ll>
#define vs vector<string> 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int> 
#define mll map<ll,ll> 
#define vpi vector<pll>
#define vpl vector<pll>
#define vvi vector<vector<int> > 
#define vvl vector<vector<ll> > 
#define pnt complex<double> 
#define pb(a) push_back(a)
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define x real
#define y imag
#define maxn 200000
#define inf 1000000000000000000
#define mod 1000000007
#define yes "YES\n"
#define no "NO\n"
}

namespace myFunc
{
	ll mul(ll a, ll b)
	{
		if (a == 0 || b == 0)
			return 0;
		if (b == 1)
			return a;
		ll res = mul(a, b / 2) * 2;
		res %= mod, res += a * (b % 2);
		return res % mod;
	}

	ll fpow(ll a, ll b)
	{
		if (b == 0)
			return 1;
		ll res = fpow(a, b / 2);
		res *= res %= mod;
		if (b % 2)
			res *= a %= mod;
		return res;
	}

	str sls(str& s, int l, int r, int t = 1)
	{
		str res = "";
		for (int i = l; i < r; i += t)
			res += s[i];
		return res;
	}

	vi sli(vi& a, int l, int r, int t=1)
	{
		vi res;
		for (int i = l; i < r; i += t)
			res.pb(a[i]);
		return res;
	}

	vl sll(vl& a, int l, int r, int t)
	{
		vl res;
		for (int i = l; i < r; i += t)
			res.pb(a[i]);
		return res;
	}

	ll gcd(ll a, ll b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	bool isvowel(char c)
	{
		c = tolower(c);
		return isalpha(c) && (c == 'e' || c == 'a' || c == 'o' || c == 'u' || c == 'i');
	}

	ll fact(ll n)
	{
		ll r = 1;
		fi(n)
			r = mul(r, i + 1);
		return r;
	}

	ll cb(ll n)
	{
		return n * (n + 1) / 2;
	}

	bool ok_matrix(int i, int j, int r, int c)
	{
		return i > -1 && i<r && j>-1 && j < c;
	}

	struct trp
	{
		int a, b, c;

		trp()
		{
			a = b = c = 0;
		}
		trp(int u, int v, int t)
		{
			a = u, b = v, c = t;
		}
	};

	bool is_prime(ll n)
	{
		if (n < 2)
			return false;
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
				return false;
		return true;
	}
	void ask(bool b)
	{
		cout << (b ? yes : no);
	}
}

using namespace myFunc;

void f2()
{
	int n, s = 0;
	cin >> n;
	vs a(n);
	cin >> a;
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			if (a[i][j] == '.' && a[i - 1][j] == '.' && a[i + 1][j] == '.' && a[i][j - 1] == '.' && a[i][j + 1] == '.')
				a[i][j] = a[i - 1][j] = a[i + 1][j] = a[i][j - 1] = a[i][j + 1] = '#';
	ffi(a)
		ffj(i)
		s += j;
	cout << (s == n * n * '#' ? yes : no);
}

void f1()
{
	
}

void f()
{
	int t;
	cin >> t;
	w(t)
	{
		f1();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed << setprecision(7);

	f2();
}