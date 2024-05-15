#include <bits/stdc++.h>

using namespace std;

#define int long long 
typedef long long ll;

const int N = 3e5 + 10;

int n, m, sx, sy, d;

void solve()
{
	cin >> n >> m >> sx >> sy >> d;
	if((sy - d <= 1 && sx - d <= 1) || (sx + d >= n && sy + d >= m)) cout << "-1\n";
	else if((sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m)) cout << "-1\n";
	else cout << n - 1 + m - 1 << "\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t = 0;
	cin >> t;
	
	while(t --) solve();
	
	return 0;
}