#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define mems(x, v) memset(x, v, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 8505;
int n, temp[N], ans[N]; bool vis[N];
void solve() {
	scanf("%d", &n); vector <int> a;
	for (int i = 1; i <= n; i++) scanf("%d", &temp[i]), ans[i] = 0;
	for (int i = n; i; i--) a.push_back(temp[i]);

	for (int idx = 1; idx <= 24; idx++) {
		mems(vis, false); set <int> st;
		st.insert(0), st.insert(n + 1); for (int x : a) st.insert(x);

		for (int x : a) {
			if (!ans[x] && !vis[x]) {
				set <int>::iterator it = st.lower_bound(x), pre = it, suf = it; pre--, suf++;
				ans[x] = idx, vis[*pre] = vis[*suf] = true;
			}
			st.erase(x);
		}
		vector <int> b;
		for (int x : a) if (vis[x]) b.push_back(x);
		a = b;
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]); puts("");
}
int main() {
	int T; scanf("%d", &T); while (T--) solve();
	return 0;
}//

				 					  			  		   			 	  	