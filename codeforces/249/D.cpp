#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1e5 + 10;

int n, a, b, c, d;
PII pnt[N];
int f[N];
std::vector<int> dct;
struct fenwick {
	int tr[N];
	void add(int x, int d) { for (int i = x; i < N; i += (i & -i)) tr[i] = max(tr[i], d); }
	int sum(int x) {
		int res = 0;
		if (!x) return res;
		for (int i = x; i; i -= (i & -i)) res = max(res, tr[i]);
		return res;
	}
}cnt;

int find(int x) {
	return lower_bound(dct.begin(), dct.end(), x) - dct.begin() + 1;
}

signed main() {
	scanf("%lld\n%lld/%lld %lld/%lld", &n, &a, &b, &c, &d);
	for (int i = 1; i <= n; i ++)
		scanf("%lld%lld", &pnt[i].fi, &pnt[i].se), dct.push_back(d * pnt[i].se - c * pnt[i].fi);
	pnt[0] = {0, 0};
	sort(dct.begin(), dct.end());
	dct.erase(unique(dct.begin(), dct.end()), dct.end());

	sort(pnt, pnt + 1 + n, [&](PII tmp1, PII tmp2) {
		return tmp1.se * b - tmp1.fi * a < tmp2.se * b - tmp2.fi * a;
	});
	for (int i = n, j = n; i >= 0; i --) {
		while (j > i && pnt[j].se * b - pnt[j].fi * a != pnt[i].se * b - pnt[i].fi * a)
			cnt.add(find(pnt[j].se * d - pnt[j].fi * c), f[j]), j --;
		f[i] = cnt.sum(find(pnt[i].se * d - pnt[i].fi * c) - 1) + 1;
	}

	for (int i = 0; i <= n; i ++)
		if (pnt[i] == make_pair(0ll, 0ll)) {
			cout << f[i] - 1 << endl;
			return 0;
		}

	return 0;
 }
 		 	   	 	 		  		  		 	  	