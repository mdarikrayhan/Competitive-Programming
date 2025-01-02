#include <bits/stdc++.h>
	
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;
ll QPow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int n;
string p[100001];
void Solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	ll pfl = 0, sul = 0, len = 0, ans = 0;
	int pfc = p[n][0], suc = p[n][p[n].length() - 1];
	bool alls = true;
	for (auto it : p[n]) 
	{
		if (it != pfc) 
		{
			alls = false;
			break;
		}
		pfl++;
	}
	for (int i = p[n].length() - 1; i >= 0; i--)
	{
		if (p[n][i] != suc) break;
		sul++;
	}
	int las = 0, cnt = 0;
	for (auto it : p[n])
	{
		if (it != las)
		{
			ans = max(ans, (ll)cnt);
			cnt = 1;
			las = it;
		}
		else cnt++;
	}
	ans = max(ans, (ll)cnt);
//	cerr << pfl << ' ' << pfc << ' ' << sul << ' ' << suc << ' ' << ans << endl;
	len = p[n].length();
	for (int i = n - 1; i >= 1; i--)
	{
		for (auto it : p[i])
		{
			ll tmp = 1;
			if (it == pfc) tmp += pfl;
			if (it == suc) tmp += sul;
			ans = max(ans, tmp);
		}
		if (alls)
		{
			for (auto it : p[i])
			{
				if (it != pfc)
				{
					alls = false;
					break;
				}
				pfl += len + 1;
			}
			for (int j = p[i].length() - 1; j >= 0; j--)
			{
				if (p[i][j] != suc) break;
				sul += len + 1;
			}
			ans = max(ans, max(pfl, sul));
			las = 0, cnt = 0;
			for (auto it : p[i])
			{
				if (it != pfc)
				{
					ans = max(ans, len * cnt + len + cnt);
					cnt = 0;
				}
				else cnt++;
			}
			ans = max(ans, len * cnt + len + cnt);
		}
		len = min((ll)1e9, (ll)p[i].length() + len * ((ll)p[i].length() + 1ll));
	}
	cout << ans << endl;
	return;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
//	cin >> _;
	while (_--) Solve();
	return 0;
}