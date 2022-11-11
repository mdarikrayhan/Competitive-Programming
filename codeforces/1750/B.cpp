#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		string s;
		cin >> n >> s;
		s = '$' + s;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 1; i <= n; ++i)
		{
			cnt0 += s[i] == '0';
			cnt1 += s[i] == '1';
		}
		int ans = cnt0 * cnt1;
		int lg = 1;
		for (int i = 2; i <= n; ++i)
		{
			if (s[i] == s[i - 1])
			{
				lg++;
			}
			else
			{
				ans = max(ans, lg * lg);
				lg = 1;
			}
		}
		ans = max(ans, lg * lg);
		cout << ans << '\n';
	}
}