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

void solve(void)
{
	int n;
	cin >> n;
	vi a(n + 2), b(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	int l = -1, r = b[1] + 1;
	
	int ans;
	auto check = [&](int pre)
	{
		pre = min(pre, a[2]);
		for (int i = 2; i <= n; i++)
		{
			if (pre + b[i] < a[i]) return 0;
			int j = (i == n) ? 1 : i + 1;
			pre = min(pre + b[i] - a[i], a[j]); 
		}
		ans = pre;
		return 1;
	};
	
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (r == b[1] + 1) cout << "NO\n";
	else
	{
		check(r);
		// cerr << r << " " << ans << "\n";
		if (b[1] - r + ans >= a[1]) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// cout << fixed << setprecision(10);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	solve();

	return 0;
}