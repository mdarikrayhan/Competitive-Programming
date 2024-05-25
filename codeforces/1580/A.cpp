#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
//	freopen("date.in.txt","r",stdin);
//    freopen("date.out.txt","w",stdout);
//clock_t start, stop;
//	start = clock();
//	stop = clock();
//	double time = (double(stop - start) / CLK_TCK);
//	cout << fixed << setprecision(6) << time << "\n";
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
constexpr ll LNF = 0x3f3f3f3f3f3f3f3f;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int maxn = 1e5 + 10, P = 13331;
#define int ll

//vector<int> b1[maxn], b2[maxn];
int a[500][500], s[500][500];
int pre[500];

void solve()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			char c;
			cin >> c;
			a[i][j] = c - '0';
			s[i][j] = s[i - 1][j] + a[i][j];
		}
	}
	
	int ans = INF;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i + 4; j <= n; j ++)
		{
			int sum = 0;
			pre[0] = INF;
			for(int k = 1; k <= m; k ++)
			{
				int p1 = s[j - 1][k] - s[i][k];
				int p0 = 2 - a[j][k] - a[i][k];
				int cnt = j - i - 1 - p1;
				if(k > 3) ans = min(ans, pre[k - 3] + sum + cnt);
				
				sum += p1 + p0;
				pre[k] = min(pre[k - 1], cnt - sum);
			}
		}
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	freopen("date.in.txt","r",stdin);
//	freopen("date.out.txt","w",stdout);

//	init();
	int T = 1;
	cin >> T;
	while(T --)
	{
		solve();
	}
	
	return 0;
}
