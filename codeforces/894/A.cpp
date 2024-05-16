// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int pre[105], suf[105];

void solve()
{
	string s; cin >> s;
	for (int i = 1; i <= (int)s.size(); ++i)
		pre[i] = pre[i-1] + (s[i-1] == 'Q');
	for (int i = (int)s.size(); i >= 1; --i)
		suf[i] = suf[i+1] + (s[i-1] == 'Q');
	int ans = 0;
	for (int i = 2; i < (int)s.size(); ++i)
	{
		if (s[i-1] == 'A')
			ans += pre[i-1]*suf[i+1];
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	solve();
	return 0;
}
