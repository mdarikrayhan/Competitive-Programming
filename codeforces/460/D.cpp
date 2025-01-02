#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l, r, k;
ll mn;
vector<ll> v, num;
void dfs(ll x, ll bor, ll val)
{
	if(x > bor) 
	{
		if(val < mn && num.size() <= k && num.size())
		{
			mn = val;
			v.clear();
			for(ll x : num) v.push_back(x);
		}
		return;
	}
	num.push_back(x);
	dfs(x + 1, bor, val ^ x);
	num.pop_back();
	dfs(x + 1, bor, val);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> l >> r >> k;
	if(k == 1 || l == r)
	{
		cout << l << '\n' << 1 << '\n' << l;
		return 0;
	}
	
	if(k >= 4)
	{
		if(r - l >= 4)
		{
			for(ll i = l; i <= l + 1; i++)
				for(ll j = l + 3; j <= l + 4; j++)
				{
					ll sum = 0;
					for(ll l = i; l <= j; l++)
						sum ^= l;
					if(!sum)
					{
						cout << 0 << '\n' << j - i + 1 << '\n';
						for(ll l = i; l <= j; l++) cout << l << ' ';
						return 0;
					}
				}
		}
		else
		{
			mn = LLONG_MAX;
			dfs(l, r, 0);
			cout << mn << '\n' << v.size() << '\n';
			for(ll x : v) cout << x << ' ';
		}
		return 0;
	}
	if(k >= 3)
	{
		int flag = 0;
		for(int i = 60; i >= 1; i--)
		{
			ll d1 = (1ll << i), d2 = (1ll << i - 1);
			ll a = d1 ^ d2, b = d1 ^ (d2 - 1), c = d1 - 1;
			if(l <= min({a, b, c}) && max({a, b, c}) <= r)
			{
				cout << 0 << '\n';
				cout << 3 << '\n';
				cout << a << ' ' << b << ' ' << c;
				return 0;
			}
		}
	}
	if(k >= 2)
	{
		if((l + 1) / 2 * 2 < r)
		{
			l = (l + 1) / 2 * 2;
			cout << 1 << '\n';
			cout << 2 << '\n';
			cout << l << ' ' << l + 1;
			return 0;
		}
		else
		{
			if((l ^ (l + 1)) < l) cout << (l ^ (l + 1)) << '\n' << 2 << '\n' << l << ' ' << l + 1;
			else cout << l << '\n' << 1 << '\n' << l;
		}
	}
	return 0;
}
/*
sb 分讨
*/