#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

struct segt
{
	int tag[1048576];
	PII val[1048576];
	segt()
	{
		rep(i, 524288) val[i | 524288] = MP(INF, i);
		for(int i = 524287; i >= 1; i --) val[i] = min(val[i << 1], val[i << 1 | 1]);
	}
	void add(int l, int r, int x, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(l > cr || r < cl) return;
		if(l <= cl && r >= cr) {
			val[cv].first += x; tag[cv] += x; return;
		}
		int mid = (cl + cr) >> 1;
		add(l, r, x, cv << 1, cl, mid);
		add(l, r, x, cv << 1 | 1, mid + 1, cr);
		val[cv] = min(val[cv << 1], val[cv << 1 | 1]);
		val[cv].first += tag[cv];
	}
	PII query(int l, int r, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(l > cr || r < cl) return MP(INF, -1);
		if(l <= cl && r >= cr) return val[cv];
		int mid = (cl + cr) >> 1;
		PII ret = min(query(l, r, cv << 1, cl, mid), query(l, r, cv << 1 | 1, mid + 1, cr));
		ret.first += tag[cv];
		return ret;
	}
};
struct fwt
{
	int dat[500005];
	void add(int id, int val)
	{
		for(; id <= 500000; id += id & -id) dat[id] += val;
	}
	int query(int id)
	{
		int val = 0;
		for(; id > 0; id -= id & -id) val += dat[id];
		return val;
	}
};
int n, a[500005];
struct ds
{
	segt t0, t1;
	fwt s0, s1;
	int x[500005];
	set<int> S;
	map<int, int> G;
	void gen()
	{
		x[0] = 0; x[n + 1] = n + 1;
		S.insert(0); S.insert(n + 1);
		int mn = INF;
		for(int i = n; i >= 1; i --) if(x[i]) {
			mn = min(mn, x[i]);
			if(mn == x[i]) {
				S.insert(i); G[x[i]] = i; t0.add(i, i, x[i] - i - INF);
			} else t1.add(i, i, x[i] - INF);
		}
	}
	void tadd(int x, int y)
	{
		s0.add(x, 1);
		s1.add(y, 1);
	}
	void madd(int r, int l)
	{
		map<int, int>::iterator it = G.lower_bound(l);
		if(it != G.end()) t0.add(it->second, r, -1);
		tadd(r, l);
	}
	int cquery(int id)
	{
		return s1.query(x[id]) - s0.query(id);
	}
	void del(int id)
	{
		set<int>::iterator it = S.find(id);
		int pr = *prev(it), nx = *next(it);
		G.erase(x[id]); S.erase(it);
		t0.add(id, id, INF);
		while(true) {
			PII cur = t1.query(pr, nx);
			if(cur.first > x[nx]) break;
			S.insert(cur.second); G[cur.first] = cur.second;
			t0.add(cur.second, cur.second, cur.first - cur.second - cquery(cur.second) - t0.query(cur.second, cur.second).first);
			t1.add(cur.second, cur.second, INF);
			pr = cur.second;
		}
	}
	PII calc()
	{
		return t0.val[1];
	}
}dl, dr;

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) if(a[i] >= i) dl.x[i] = a[i];
	else dr.x[n + 1 - i] = n + 1 - a[i];
	dl.gen();
	dr.gen();
	int ans = 0;
	rep1(i, n) {
		PII cl = dl.calc(), cr = dr.calc(), cur = min(cl, cr);
		ans = max(ans, cur.first);
		if(cur == cl) {
			dr.madd(n + 1 - cur.second, n + 1 - a[cur.second]); dl.tadd(cur.second, a[cur.second]);
			dl.del(cur.second);
		} else {
			dl.madd(n + 1 - cur.second, a[n + 1 - cur.second]); dr.tadd(cur.second, n + 1 - a[n + 1 - cur.second]);
			dr.del(cur.second);
		}
	}
	printf("%d\n", ans);
	return 0;
}