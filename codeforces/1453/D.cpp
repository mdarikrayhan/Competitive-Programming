#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2000+10;
int ans[N];

void solve() {
	ll k, i, j;
	cin>>k;
	if (k&1) {
		cout<<-1<<'\n';
		return;
	}
	memset(ans, 0, sizeof(ans));
	ans[1] = 1;
	int cur = 1;
	while (k) {
		int cnt = 1;
		while ((1ll<<(cnt+1))-2 <= k) {
			cnt++;
		}
		cur += cnt-1;
		ans[cur] = 1;
		k -= (1ll<<cnt)-2;
	}
	cout<<cur-1<<'\n';
	for (i = 1; i <= cur-1; i++) {
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}
