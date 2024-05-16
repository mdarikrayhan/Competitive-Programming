#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>

using namespace std;
#define Ma7moud_7amdy ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Open_Sesame Open()
#define watch(x) cout << #x << " = " << x << endl;
#define endl "\n"
typedef long long ll;

void Open() {
#ifndef ONLINE_JUDGE
	freopen("standard.in", "r", stdin);
	freopen("standard.out", "w", stdout);
#endif
}

const int mod = ll(1e8), N = 1e6 + 5 + 2, oo = 0x3f3f3f3f;


void solve() {
	int n,m;
	cin >> n>>m;
	priority_queue<int>pq_mx;
	priority_queue<int, vector<int>, greater<int>>pq_mn;
	for (int i = 0, tmp; i < m; ++i) {
		cin >> tmp;
		pq_mn.push(tmp);
		pq_mx.push(tmp);
	}
	ll sum_mx = 0, sum_mn = 0;
	for (int i = 0; i < n; ++i) {
		int cur_mx = pq_mx.top();
		int cur_mn = pq_mn.top();
		pq_mn.pop(), pq_mx.pop();
		sum_mx += cur_mx;
		sum_mn += cur_mn;
		if (--cur_mx > 0)pq_mx.push(cur_mx);
		if (--cur_mn > 0)pq_mn.push(cur_mn);
	}
	cout << sum_mx << " " << sum_mn << endl;
}


int main() {
	Ma7moud_7amdy;
	Open_Sesame;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}