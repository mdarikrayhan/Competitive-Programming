// LUOGU_RID: 160475767
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int nn = 2000;
#define cle(a,val) memset(a,(val),sizeof(a))
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define red(i,a,b) for(register int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define x first
#define y second
#define mk make_pair



int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	bool f = false;
	rep(i, 1, k) {
		int x, y;
		cin >> x >> y;
		int st = min((n - x), (x - 1));
		st = min(st, (m - y));
		st = min(st, (y - 1));
		if (st <= 4)
			f = true;
	}
	if (f)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}