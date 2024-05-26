#include<bits/stdc++.h>
typedef long long ll;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
int n, m, k, a;
void solve() {
	std::cin >> n >> k >> m >> a;
	std::vector<int>g(a + 1, 0);
	std::vector<std::array<int, 3>>cnt(n + 1);
	for (int i = 1; i <= n; i++)
		cnt[i][2] = i;
	for (int i = 1; i <= n; i++)
		cnt[i][0] = 0;
	for (int i = 1; i <= a; i++) {
		std::cin >> g[i];
		cnt[g[i]][0]++;
		cnt[g[i]][1] = i;
	}
	auto check1 = [&](int u)->bool{
		std::vector<std::array<int, 3>>num = cnt;
		num[u][0] += m - a;
		if(m - a != 0)num[u][1] = m;
		std::sort(num.begin() + 1, num.end(), [&](std::array<int, 3>&x, std::array<int, 3>&y) {
			return x[0] == y[0] ? x[1]<y[1]: x[0]>y[0];
		});
		for (int i = 1; i <= k; i++)
			if (num[i][2] == u and num[i][0] != 0)
				return true;
		return false;
	};
	auto check2 = [&](int u)->bool{
		if (cnt[u][0] == 0)
			return true;
		if (k == n)
			return false;
		std::priority_queue<int>q;
		for (int i = 1; i <= n; i++) {
			if (i == u)
				continue;
			if (cnt[i][0] > cnt[u][0]) {
				q.push(0);
			}
			else if (cnt[i][0] == cnt[u][0] and cnt[i][1] < cnt[u][1]) {
				q.push(0);
			}
			else {
				q.push((cnt[u][0] + 1 - cnt[i][0]) * -1);
			}
		}
		int kkk = 0, ans = 0;
		while (kkk < k) {
			auto p = q.top();
			q.pop();
			kkk++;
			ans += (-1 * p);
		}
		return ans <= (m - a);
	};
	for (int i = 1; i <= n; i++) {
		if (!check1(i)) {
			std::cout << "3 ";
		}
		else if (!check2(i)) {
			std::cout << "1 ";
		}
		else {
			std::cout << "2 ";
		}
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	while (t--)solve();
	return 0;
}