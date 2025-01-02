#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pp pair <int, int>
#define fi first
#define se second
#define mp make_pair

const int N = 5e5 + 9;
const int sz = 800;

int n, q, a[N], lazy[sz + 9];
vector <pp> v[sz];

int getbl (int val){
	return val / sz + (val % sz != 0);
}

signed main (){
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v[getbl (i)].push_back (mp (a[i], i));
	}
	for (int i = 1; i <= getbl (n); i++) sort (v[i].begin (), v[i].end ());
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int l, r, x; cin >> l >> r >> x;
			if (getbl (r) - getbl (l) <= 1){
				v[getbl (l)].clear ();
				v[getbl (r)].clear ();
				for (int i = l; i <= r; i++) a[i] += x;
				int st = (getbl (l) - 1) * sz + 1;
				int en = getbl (r) * sz;
				en = min (en, n);
				for (int i = st; i <= en; i++) v[getbl (i)].push_back (mp (a[i], i));
				sort (v[getbl (l)].begin (), v[getbl (l)].end ());
				sort (v[getbl (r)].begin (), v[getbl (r)].end ());
			} else {
				int i = l;
				for (; i <= r; i++){
					if (getbl (i) > getbl (l)) break;
					a[i] += x;
				}
				int st = (getbl (l) - 1) * sz + 1;
				int en = getbl (l) * sz;
				v[getbl (l)].clear ();
				for (int i = st; i <= en; i++) v[getbl (i)].push_back (mp (a[i], i));
				sort (v[getbl (l)].begin (), v[getbl (l)].end ());
				
				for (; i <= r; i += sz){
					if (getbl (i) == getbl (r)) break;
					lazy[getbl (i)] += x;
				}
				
				for (; i <= r; i++) a[i] += x;
				v[getbl (r)].clear ();
				st = (getbl (r) - 1) * sz + 1;
				en = getbl (r) * sz;
				en = min (en, n);
				for (int i = st; i <= en; i++) v[getbl (i)].push_back (mp (a[i], i));
				sort (v[getbl (r)].begin (), v[getbl (r)].end ());
			}
		} else {
			int y; cin >> y;
			int mx = -N, mn = N;
			for (int bl = 1; bl <= getbl (n); bl++){
				int l = 0, r = v[bl].size () - 1, ans = -1;
				while (l <= r){
					int mid = l + r >> 1;
					if (v[bl][mid].fi + lazy[bl] >= y){
						ans = mid; r = mid - 1;
					} else l = mid + 1;
				}
				if (ans == -1 || v[bl][ans].fi + lazy[bl] != y) continue;
				mx = max (mx, v[bl][ans].se);
				mn = min (mn, v[bl][ans].se);
				l = 0; r = v[bl].size () - 1; ans = -1;
				while (l <= r){
					int mid = l + r >> 1;
					if (v[bl][mid].fi + lazy[bl] <= y){
						ans = mid; l = mid + 1;
					} else r = mid - 1;
				}
				if (ans == -1 || v[bl][ans].fi + lazy[bl] != y) continue;
				mx = max (mx, v[bl][ans].se);
				mn = min (mn, v[bl][ans].se);
			}
			if (mn == N) cout << -1 << '\n';
			else cout << mx - mn << '\n';
		}
	}
}
// i love noodles0428 <3
   	    						 	 					 			   		