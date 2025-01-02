// LUOGU_RID: 159897345
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int c, d, n, m, k;
int T;
int w[3];
int v[3];
int f[N];
int cf[N];

void dp() {

	for (int i = 1; i <= 2; i++) {
		for (int j = w[i]; j <= N; j++) {
			if (f[j] < f[j - w[i]] + w[i]) {
				f[j] = f[j - w[i]] + w[i];
				cf[j] = cf[j - w[i]] + v[i];
			} else if (f[j] == f[j - w[i]] + w[i]) {
				cf[j] = min(cf[j], cf[j - w[i]] + v[i]);
			}
		}
	}
	int ans = 1e9;
	for (int i = T; i <= N; i++) //注意这里是取最小值，因为我们是至少要n+m-k个人，
//									所以我们直接输出f[n*m-k]是错的
		ans = min(ans, cf[i]);
	cout << ans;
}

signed main() {
	cin >> c >> d >> n >> m >> k;
	T = m * n - k;//T是总人数
	v[1] = c, v[2] = d;//v是每场比赛要多少题目
	w[1] = n, w[2] = 1;//w是每场比赛选的人
	if (T <= 0)
		cout << 0;
	else
		dp();
	return 0;
}