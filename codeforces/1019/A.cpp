#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define lowbit(x) ((x)&(-x))
#define endl '\n'
#define sc scanf
#define pt printf
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define ls k+k
#define rs k+k+1
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const int N = 2e5 + 10;
struct node
{
	ll cnt, p;
	ll c[3010], pre[3010];
}nd[3010];
void UraykevoliQwQ()
{
	ll n, m; cin >> n >> m;
	ll cnt2 = 0;
	for (int i = 1; i <= n; i++)
	{
		nd[i].cnt = nd[i].p = 0;
		for (int j = 1; j <= 3000; j++)nd[i].c[j] = nd[i].pre[j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ll id, c; cin >> id >> c;
		nd[id].cnt++;
		if (id != 1)cnt2 = max(cnt2, nd[id].cnt);
		int now = nd[id].cnt;
		nd[id].c[now] = c;
	}
	if (nd[1].cnt > cnt2)
	{
		cout << 0;
		return;
	}
	for (int i = 2; i <= m; i++)
	{
		sort(nd[i].c + 1, nd[i].c + nd[i].cnt + 1);
		for (int j = 1; j <= nd[i].cnt; j++)
		{
			nd[i].pre[j] = nd[i].pre[j - 1] + nd[i].c[j];
		}
	}
	ll ans = 1e18;
	for (int k = max(nd[1].cnt,1ll); k <= n; k++)
	{
		for (int i = 2; i <= m; i++)nd[i].p = 0;
		ll cost = 0, cntnow = nd[1].cnt;
		for (int i = 2; i <= m; i++)
		{
			if (nd[i].cnt >= k)
			{
				cost += nd[i].pre[nd[i].cnt - k + 1];
				nd[i].p = nd[i].cnt - k + 2;
				cntnow += nd[i].cnt - k + 1;
			}
		}
		if (cntnow > k)continue;
		vector<ll>v;
		for (int i = 2; i <= m; i++)
		{
			for (int j = max(nd[i].p, 1ll); j <= nd[i].cnt; j++)v.push_back(nd[i].c[j]);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i <= k - cntnow - 1; i++)cost += v[i];
		ans = min(ans, cost);
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--)UraykevoliQwQ();
	return 0;
}