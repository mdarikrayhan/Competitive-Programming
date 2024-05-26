// LUOGU_RID: 159966853
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e5 + 10;
int n, b;
ll t[MAXN], d[MAXN];
ll now;
deque<ll> q;
int main() {
	cin >> n >> b;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> d[i];
	}
	cout << t[1] + d[1] << " ";
	now = t[1] + d[1];
	q.push_back(now);
	for (int i = 2; i <= n; ++i) {
		while (q.size() && q.front() <= t[i]) {
			q.pop_front();
		}//d
		if (q.size() <= b) {
			now = max(now, t[i]) + d[i];
			q.push_back(now);
			cout << now << " ";
		} else {
			cout << "-1 ";
		}
	}
	return 0;
} 