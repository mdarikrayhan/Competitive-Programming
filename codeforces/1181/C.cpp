#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

char g[N][N];
ll dp[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = g[i][j] == g[i + 1][j] ? dp[i + 1][j] + 1 : 1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll cnt = 0;
        int pa = -1, pb = -1, pc = -1, pd = -1;
        for (int j = 1; j <= m; j++)
        {
            int a = i, b = a + dp[a][j], c = b + dp[b][j], d = c + dp[c][j];
            if (c <= n && b - a == c - b && b - a <= d - c)
            {
                if (pc <= n && pa == a && pb == b && pc == c && pb - pa <= pd - pc && g[a][j] == g[a][j - 1] && g[b][j] == g[b][j - 1] && g[c][j] == g[c][j - 1])
                {
                    cnt++;
                }
                else
                {
                    ans += (cnt * (cnt + 1)) >> 1;
                    cnt = 1;
                }
            }
            pa = a;
            pb = b;
            pc = c;
            pd = d;
        }
        ans += (cnt * (cnt + 1)) >> 1;
    }
    cout << ans << endl;
}
   			  	    	      	 	 			 		