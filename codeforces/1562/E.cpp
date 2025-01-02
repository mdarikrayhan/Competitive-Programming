// Hydro submission #6654b027545c77c7ad426762@1716826151716
// Problem: E. Rescue Niwen!
// Contest: Codeforces - Codeforces Round 741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms

# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
//# define int long long
# define rd(t) read <t> ()
# define mem(a, b) memset (a, b, sizeof a)
# define fi first
# define se second
# define lc u << 1 
# define rc u << 1 | 1 
# define debug printf ("debug\n")
const int N = 5005; 
template <typename T> inline T read ()
{
	T s = 0, w = 1; int c = getchar ();
	for (; !isdigit (c); c = getchar ()) if (c == '-') w = -1;
	for (; isdigit (c); c = getchar ()) s = (s << 1) + (s << 3) + c - '0';
	return s * w;
}

int n; 
char s[N]; 
int f[N], g[N][N]; 
signed main ()
{
	int T = rd (int);
	while (T -- )
	{
		n = rd (int); 
		scanf ("%s", s + 1); 
		for (int i = n - 1; i >= 1; i -- )
		{
			if (s[i] == s[n]) g[n][i] = 1; 
			else g[n][i] = 0; 
		}
		for(int i = n - 1; i >= 1; i -- )
		{
			for (int j = i - 1; j >= 1; j -- )
			{
				g[i][j] = 0; 
				if (s[i] == s[j])
					g[i][j] = g[i + 1][j + 1] + 1;
			}
		}
		f[1] = n;
		int ans = n; 
		for (int i = 2; i <= n; i ++ )
		{
			f[i] = n - i + 1;
			for (int j = 1; j < i; j ++ )
			{
				if (s[i + g[i][j]] > s[j + g[i][j]])
					f[i] = max (f[i], f[j] + n - i + 1 - g[i][j]); 
			}
			ans = max (ans, f[i]); 
		}
		printf ("%d\n", ans); 
	}
	return 0;
}