// LUOGU_RID: 160265278
#include<bits/stdc++.h>
#define int long long
#define psbk push_back
#define fst first
#define scd second
#define umap unordered_map
#define pqueue priority_queue
#define vc vector
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
constexpr int inf = 0x3f3f3f3f;
int n, d, dis[1000005];
bool a[1000005];
void solve()
{
	cin >> n >> d;
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(!a[i])
		{
			q.push(i);
			dis[i] = 0;
		}
		else
		{
			dis[i] = -1;
		}
	}
	while(q.size())
	{
		int fr = q.front();
		q.pop();
		if(dis[(fr + d) % n] == -1)
		{
			dis[(fr + d) % n] = dis[fr] + 1;
			q.push((fr + d) % n);
		}
	}
	int mxd = 0;
	for(int i=0;i<n;i++)
	{
		if(dis[i] == -1)
		{
			cout << -1 << endl;
			return;
		}
		mxd = max(mxd, dis[i]);
	}
	cout << mxd << endl;
}
signed main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		solve();
	}
	return 0;
}