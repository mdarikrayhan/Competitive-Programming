#include <bits/stdc++.h>
#define ll long long
#define forr(i, l, r) for (ll i = l; i <= r; i++)
#define fodd(i, l, r) for (ll i = l; i >= r; i--)
#define all(v) v.begin(), v.end()
#define biti(i, x) ((1 << (i)) & (x))
#define boolbit(i, x) (biti(i, x) != 0)
#define endl '\n'
#define fi first
#define se second
#define sz(x) (ll)(x.size())
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) {if (a > b) {a = b; return true;} return false;}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) {if (a < b) {a = b; return true;} return false;}
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int m, n;
// vector<pair<int,int>> adj[250011];
// vector<pair<int,int>> dp[250011];
// bool check[250011];
// vector<pair<int,int>> newvalue[250011];
short g[411][160011];
int a[411][411], f[411][411];
int main()
{
    #define TASK "distinct"
    //  freopen(TASK".inp", "r", stdin);
    //  freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    forr(i, 1, m)
    forr(j, 1, n)
        cin >> a[i][j];
    int ans = 0;
	forr(j, 1, n)
	{
		for (int l = m; l; -- l)
		for (int r = l; r <= m; ++ r)
		{
			if (l == r)	maximize(f[l][r], g[l][a[l][j]]);
			else
			{
				maximize(f[l][r], f[l + 1][r]);
				maximize(f[l][r], f[l][r - 1]);
				maximize(f[l][r], g[l][a[r][j]]);
				maximize(f[l][r], g[r][a[l][j]]);
				if(a[l][j] == a[r][j]) f[l][r] = j;
			}
			maximize(ans, (r - l + 1)*(j - f[l][r]));
		}
		
		forr(i, 1, m) g[i][a[i][j]] = j;
	}
	cout << ans << endl;
}