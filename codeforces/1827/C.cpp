// LUOGU_RID: 160065872
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n , d[N] , f[N] , g[N];
int top , r[N] , mid[N]; string s;
int Solve(int cs)
{
	cin >> n >> s;
	s = " " + s + "#";
	memset(d , 0 , sizeof(int) * (n + 1));
	for(int i = 1 , l = 0 , r = 0 ; i <= n ; i++)
	{
		int j = l + r - i - 1;
		// cerr << i << " " << j << " " << l << ',' << r << "\n";
		if(r <= i || j - d[j] + 1 <= l)
		{
			d[i] = max(0 , j - l + 1);
			while(s[i - d[i]] == s[i + d[i] + 1])d[i]++;
		}
		else d[i] = d[j];
		if(r < i + d[i])l = i - d[i] + 1 , r = i + d[i];
	}
	// for(int i = 1 ; i <= n ; i++)
	// 	cerr << d[i] << " \n"[i == n];
	top = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		while(top && r[top] < i)top--;
		g[i] = top ? (i - mid[top]) * 2 : 0;
		if(d[i])
		{
			int rr = i + d[i];
			while(top && r[top] <= rr)top--;
			r[++top] = rr , mid[top] = i;
		}
	}
	ll ans = 0; 
	for(int i = 1 ; i <= n ; i++)
	{
		f[i] = (g[i] ? 1 + f[i - g[i]] : 0);
		ans += f[i];
	}
	// for(int i = 1 ; i <= n ; i++)
	// 	cerr << g[i] << " \n"[i == n];
	// for(int i = 1 ; i <= n ; i++)
	// 	cerr << f[i] << " \n"[i == n];
	// if(cs == 178 && ans == 7)cout << s.substr(1 , n) << "\n";
	// else 
	cout << ans << "\n";
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int T; cin >> T;
	for(int cs = 1 ; cs <= T ; cs++)
		Solve(cs);
	return 0;
}