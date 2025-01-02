#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int N = 3e5 + 10;
int son[N][26], cnt[N], is[N], idx;
int insert(const string &str)
{
	int p = 0, n = str.length(), st = -1, ed = -1, ans = n;
	for (int i = 0; i < n; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])
			son[p][u] = ++idx;
		p = son[p][u];
		if (st == -1 && cnt[p] == 1)
			st = i;
		if (~st && is[p])
			ed = i;
	}
	if (~st && ~ed)
		ans -= max(0ll, ed - st - 1);

	if (!is[p])
	{
		is[p] = true, p = 0;
		for (int i = 0; i < n; i++)
		{
			int u = str[i] - 'a';
			p = son[p][u], ++cnt[p];
		}
	}
	return ans;
}

void solve()
{
	string s;
	int ans = 0;
	while (getline(cin, s))
	{
		++ans;
		string word;
		for (char c : s)
		{
			if (c >= 'a' && c <= 'z')
				word += c;
			else
			{
				++ans;
				if (word != "")
					ans += insert(word), word = "";
			}
		}
		if (word != "")
			ans += insert(word), word = "";
	}
	cout << ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// int T;
	// cin >> T;
	// while (T--)
	// 	solve();
	solve();
	return 0;
}