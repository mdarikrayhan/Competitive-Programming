// LUOGU_RID: 160587924
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ull unsigned long long 
#define i128 __int128
#define pb emplace_back
using namespace std; 
const int N = 1e6 + 7;
int p[N];
int to[N];
vector < pair < int, int > > cm[N], ans;
int ord[N];
int dem[N];
int col[N];
int tot;
int n;
mt19937_64 orz;
int times(int x, int y) {
	int u = -(dem[n - x + 1] + dem[n - y + 1]) / 2;
	while(u < 0) u += n;
	while(u >= n) u -= n;
	return u;
}
void mkp(int u, int v) {
	cm[times(u, v)].pb(u, v);
}
int nxt[N], lst[N];
void getcol(int x) {
	++tot;
	vi st;
	for(int p = x; ; p = to[p]){
		if(col[p])break;
		col[p] = tot;
		st.pb(p);
	}
	sort(st.begin(), st.end());
	L(i, 1, sz(st) - 1) 
		nxt[st[i - 1]] = st[i], lst[st[i]] = st[i - 1];
	L(i, 1, sz(st) - 1) 
		mkp(st[i - 1], st[i]);
}
int P[N];
void solve() {
	if(n == 1)
		return;
	if(n == 2) {
		if(p[1] != 1) {
			ans.pb(1, 2);
		}
		return;
	}
	L(i, 1, n) {
		if(i % 2 == 1) {
			dem[i] = i;
		} else {
			dem[i] = 1 - i;
		}
	}
	L(i, 1, n) 
		to[n - i + 1] = p[i];
	L(i, 1, n) 
		ord[i] = i;
	L(i, 1, n) {
		col[i] = 0;
	} 
	tot = 0;
	L(i, 1, n) if(!col[i]) getcol(i);
	L(i, 1, n) {
		shuffle(cm[i].begin(), cm[i].end(), orz);
		R(g, sz(cm[i - 1]) - 1, 0) {
			auto u = cm[i - 1][g];
			int x = u.first;
			int y = u.second;
			auto getid = [&] (int p) -> int  {
				if((n - p + 1) % 2 == 1) p += n - i + 1;
				else p -= n - i + 1;
				if(p <= 0) p = 1 - p;
				if(p > n) p = n * 2 + 1 - p;
				return p;
			};
//			cout << x << ' ' << y << endl;
			if(col[x] == col[y] && x != to[x]) {
				int u = getid(x);
				int v = getid(y);
				if((u - i) ^ (v - i) ^ 1) {
					cout << "wa\n";
					exit(0);
				}
//				cout << "pb " << min(u, v) << ' ' << max(u, v) << ' ' << x << ' ' << y << "at " << i << endl;
				ans.pb(min(u, v), max(u, v));
//				cout<<"tot="<<tot<<' '<<x<<' '<<y<<endl;
//				cout << "to = ";
//				L(i, 1, n) 
//					cout << to[i] << ' ';
//				cout << endl;
				
				swap(to[x], to[y]);
				int du = x, dv = y;
				vi L, R;
				while(true) {
					L.pb(du), du = to[du];
					if(du == x) {
						break;
					} 
					R.pb(dv), dv = to[dv]; 
					if(dv == y) {
						swap(L, R);
						break;
					}
				}
				++tot;
				for(auto&u : L) 
					col[u] = tot;
				sort(L.begin(), L.end());
				for(auto &u : L) {
					int a = lst[u], b = nxt[u];
					if(!a || !b)continue;
					nxt[a] = b, lst[b] = a;
					if(col[a] == col[b])
						mkp(a, b); 
				}
				lst[L[0]] = 0, nxt[L.back()] = 0;
				L(i, 1, sz(L) - 1) {
					nxt[L[i - 1]] = L[i];
					lst[L[i]] = L[i - 1];
					mkp(L[i - 1], L[i]);
				}
			}
		}
		if(n % 2 == 0) {
			if(i % 2 == 1) ans.pb(1, n);
			else ans.pb(2, n - 1);
		} else {
			if(i % 2 == 1) ans.pb(1, n - 1);
			else ans.pb(2, n);
		} 
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> p[i];
	}
	solve();
	cout << sz(ans) << '\n';
	for(auto&u : ans){
		cout << u.first << ' ' << u.second << '\n'; 
	}
	return 0;
}