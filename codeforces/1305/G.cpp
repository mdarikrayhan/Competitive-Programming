#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <random>
#include <chrono>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
const int MAXBIT = 17;

int n;
int a[MAXN];

int cnt[1 << (MAXBIT + 1)];
int col[1 << (MAXBIT + 1)];

int mx[1 << (MAXBIT + 1)][2];
void upd(int mask, int val) { if (val > mx[mask][0]) { if (mx[mask][0] != -1 && col[mx[mask][0]] != col[val]) mx[mask][1] = mx[mask][0]; else assert(mx[mask][1] == -1 || col[mx[mask][1]] != col[val]); mx[mask][0] = val; } else if (val != -1 && col[val] != col[mx[mask][0]] && val > mx[mask][1]) mx[mask][1] = val; }

int state[1 << (MAXBIT + 1)]; // nonnegative = that much copies of a single node, -1 = root of a component of at least two nodes, -2 = nonroot
int best[1 << (MAXBIT + 1)];
pair<int, int> edge[1 << (MAXBIT + 1)];

int sz[1 << (MAXBIT + 1)];
int uffind(int x) { if (col[x] == x) return x; return col[x] = uffind(col[x]); }
bool ufunite(int x, int y) { x = uffind(x); y = uffind(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); col[y] = x, sz[x] += sz[y]; return true; }

ll solve() {
	REP(mask, 2 << MAXBIT) cnt[mask] = 0, col[mask] = mask, sz[mask] = 1;
	++cnt[0]; REP(i, n) ++cnt[a[i]];
	ll ret = 0; REP(i, n) ret -= a[i];
	while (true) {
		REP(mask, 2 << MAXBIT) { uffind(mask); state[mask] = col[mask] != mask ? -2 : sz[mask] >= 2 ? -1 : cnt[mask]; }
		//REP(mask, 2 << MAXBIT) if (state[mask] != 0) printf("state[%d]=%d\n", mask, state[mask]);
		REP(mask, 2 << MAXBIT) REP(j, 2) mx[mask][j] = -1;
		REP(mask, 2 << MAXBIT) if (cnt[mask] >= 1) upd(mask, mask);
		REPE(bit, MAXBIT) REP(mask, 2 << MAXBIT) if (mask & (1 << bit)) REP(j, 2) upd(mask, mx[mask ^ (1 << bit)][j]);
		REP(mask, 2 << MAXBIT) best[mask] = -1;
		REP(mask, 2 << MAXBIT) if (cnt[mask] >= 1) {
			int othermask = (2 << MAXBIT) - 1 - mask;
			int idx = 0; while (idx < 2 && mx[othermask][idx] != -1 && col[mask] == col[mx[othermask][idx]]) ++idx; assert(idx < 2);
			int val = mx[othermask][idx]; if (val == -1) continue; else assert(col[val] != col[mask] && (val & mask) == 0);
			//printf("for %d (col=%d), best edge is to %d\n", mask, col[mask], val);
			if (mask + val > best[col[mask]]) best[col[mask]] = mask + val, edge[col[mask]] = MP(mask, val);
		}
		vector<pair<int, pair<int, int>>> cur;
		REP(mask, 2 << MAXBIT) if (state[mask] == -1 || state[mask] >= 1) {
			if (best[mask] == -1) continue;
			//printf("option: color %d and %d with val %d\n", col[edge[mask].first], col[edge[mask].second], best[mask]);
			cur.PB(MP(-best[mask], MP(col[edge[mask].first], col[edge[mask].second])));
		}
		bool change = false;
		sort(cur.begin(), cur.end());
		REPSZ(i, cur) {
			int val = -cur[i].first, a = cur[i].second.first, b = cur[i].second.second;
			a = uffind(a), b = uffind(b); if (a == b) continue;
			int times = 1;
			if (sz[a] == 1) times += cnt[a] - 1;
			if (sz[b] == 1) times += cnt[b] - 1;
			//printf("performing %d times col %d-%d with value %d\n", times, a, b, val);
			ret += (ll)times * val;
			assert(ufunite(a, b));
			change = true;
		}
		if (!change) break;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

ll solvestupid() {
	ll ret = 0;
	a[n] = 0;
	REPE(i, n) ret -= a[i];
	vector<pair<int, pair<int, int>>> opt;
	REPE(i, n) FORE(j, i + 1, n) if ((a[i] & a[j]) == 0) opt.PB(MP(-(a[i] + a[j]), MP(i, j)));
	sort(opt.begin(), opt.end());
	REPE(i, n) col[i] = i, sz[i] = 1;
	REPSZ(i, opt) {
		int val = -opt[i].first, a = opt[i].second.first, b = opt[i].second.second;
		if (ufunite(a, b)) ret += val;
	}
	return ret;
}

std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
void stress() {
	REP(rep, 1000) {
		n = rnd() % 1000 + 1;
		REP(i, n) a[i] = rnd() % 1000;
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("have=%lld want=%lld\n", have, want);
		printf("%d\n", n);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}
