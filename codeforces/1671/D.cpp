#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int N = 2e5 + 10;

int n, x;
int a[N];

void solve()
{
	cin >> n >> x;
	int ans = 0, min_a = 1e9, max_a = 0;
	for(int i = 1; i <= n; i ++) cin >> a[i], min_a = min(min_a, a[i]), max_a = max(max_a, a[i]);	
	for(int i = 2; i <= n; i ++) ans += abs(a[i] - a[i - 1]);
	
	int mi_ = 0, ma_ = 0;
	int mi = min((int)1, min_a - 1);
	if(mi)
	{
		mi_ = min(a[1] - mi, a[n] - mi);
		for(int i = 1; i < n; i ++)
			mi_ = min(mi_, (min(a[i], a[i + 1]) - mi) * 2);
	}
	if(max_a < x)
	{
		ma_ = x - max(a[1], a[n]);
		for(int i = 1; i < n; i ++)
			ma_ = min(ma_, (x - max(a[i], a[i + 1])) * 2);
	}
		
	cout << ans + mi_ + ma_ << "\n";
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