#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<string>
#include<cstring>
#include<stack>
#include<sstream>
#include<set>
#include<bitset>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e5 + 10;
const ll maxm = 1e2 + 10;
const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ld eps = 1e-8;
ll t;
ll n, k;
ll AND[maxn];
ll OR[maxn];
ll one[65];
vector<pair<ll, ll>>vec;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	t = 1;
	while (t--)
	{
		cin >> n >> k;
		vec.clear();
		for (ll i = 2; i <= n; i++)
		{
			cout << "and " << 1 << " " << i << endl;
			cin >> AND[i];
		}
		for (ll i = 2; i <= n; i++)
		{
			cout << "or " << 1 << " " << i << endl;
			cin >> OR[i];
		}
		for (ll i = 0; i <= 32; i++)
			one[i] = -1;
		ll land = 0, ror = 0;
		cout << "and " << 2 << " " << 3 << endl;
		cin >> land;
		cout << "or " << 2 << " " << 3 << endl;
		cin >> ror;
		for (ll i = 2; i <= n; i++)
		{
			for (ll j = 0; j <= 32; j++)
			{
				if (((AND[i] >> j) & (ll)1) == 1)
					one[j] = 1;
				else if (((OR[i] >> j) & (ll)1) == 0)
					one[j] = 0;
			}
		}
		ll now = 0;
		for (ll i = 0; i <= 32; i++)
		{
			if (one[i] == 1)
				now += (ll)1 << i;
			if (one[i] != -1)
				continue;
			if (((OR[2] >> i) & (ll)1) == 1 && ((OR[3] >> i) & (ll)1) == 1 && ((ror >> i) & (ll)1) == 0)
				one[i] = 1;
			else
				one[i] = 0;
			if (one[i] == 1)
				now += (ll)1 << i;
		}
		vec.push_back({ now,1 });
		for (ll i = 2; i <= n; i++)
		{
			ll res = 0;
			for (ll j = 0; j <= 32; j++)
			{
				if (((now >> j) & (ll)1) == (ll)1)
				{
					if (((AND[i] >> j) & (ll)1) == (ll)1)
						res += (ll)1 << j;
				}
				else
				{
					if (((OR[i] >> j) & (ll)1) == (ll)1)
						res += (ll)1 << j;
				}
			}
			vec.push_back({ res,i });
		}
		sort(vec.begin(), vec.end());
		/*for (ll i = 0; i < 35; i++)
			cout << one[i] << " ";
		cout << endl;*/
		//for (ll i = 0; i < vec.size(); i++)
		//	cout << vec[i].first << " "<< vec[i].second<< endl;
		cout << "finish " << vec[k - 1].first << endl;
	}
	return 0;
}
