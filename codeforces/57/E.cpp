// LUOGU_RID: 158372437
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int vis[2005][2005], ans[2005];
void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	vis[x][y] = 1;
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		ans[vis[x][y]]++;
		if(vis[x][y] > 500) break;
		for(int i = 0; i < 8; i++) {
			int dx = x + dir[i][0], dy = y + dir[i][1];
			if(vis[dx][dy]) continue;
			vis[dx][dy] = vis[x][y] + 1;
			q.push(make_pair(dx, dy)); 
		}
	}
}
int main() {
	ll k, n, cnt = 0;
	cin>>k>>n;
	for(int i = 1, x, y; i <= n; i++) {
		cin>>x>>y;
		vis[x + 1001][y + 1001] = -1; 
	}
	bfs(1001, 1001);
	if(k <= 500) {
		for(int i = 1; i <= k + 1; i++) (cnt += ans[i]) %= mod;
		printf("%lld\n", cnt);
	} else {
		ll p = ans[500] - ans[499];
		(k -= 498) %= mod;
		for(int i = 0; i <= 499; i++) (cnt += ans[i]) %= mod;
		cout<<(((k * ans[500] % mod + cnt) % mod + (k * (k - 1) / 2) % mod * p % mod) % mod + mod) % mod;
	}
	return 0;
}