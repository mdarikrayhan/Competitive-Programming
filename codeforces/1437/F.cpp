/* 来源: Educational Codeforces Round 90 */
/* 题目: F. Network Coverage */
/* 类型: 决策 */
/* 解法: 贪心 二分 */


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define Sz(x) (int)(x).size()
#define bit(x) (1ll << (x))
using ll = long long;
using db = double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vd = vector<db>;
using vs = vector<string>;
mt19937 mrand(time(0));
const int mod = 998244353;

void add(ll &a, ll b)
{
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

void solve(void)
{
	int n;
	cin >> n;
	vi a(n + 2);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a.begin() + 1, a.begin() + 1 + n);

	vll f(n + 2, vl(n + 2));
	vl g(n + 2);
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j < i; j++)
			if (a[j] * 2 <= a[i]) cnt++;

		while (!q.empty() && a[q.front()] * 2 <= a[i])
		{
			int u = q.front();
			for (int j = 1; j <= u; j++)
				add(g[j], f[u][j]); 
			q.pop();
		}

		vl ng(n + 2);
		for (int j = 1; j < i; j++)
			ng[j + 1] = g[j];
		add(ng[1], 1);

		for (int j = 1; j <= cnt + 1; j++)
			add(ng[j + 1], ng[j] * (cnt + 1 - j) % mod);
		for (int j = 1; j <= i; j++)
			f[i][j] = ng[j];
		q.push(i);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		add(ans, f[i][n]);
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// cout << fixed << setprecision(10);

	solve();

	return 0;
}