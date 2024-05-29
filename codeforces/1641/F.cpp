#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef std::pair<int, int> pii;
#define fi first
#define se second
#define MP std::make_pair
#define clr(f, n) memset(f, 0, (n) << 2)
#define cpy(f, g, n) memcpy(f, g, (n) << 2)
#define rev(f, n) std::reverse(f, (f) + (n))
#define double long double
int read()
{
	int s = 0, f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9'))
		f ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9')
		s = s * 10 + (c - '0'), c = getchar();
	return f ? s : -s; 
}
template<typename T> 
auto Fmax(T &x, T y){ return x = x < y ? y : x; };
const int MAXN = 50005, inf = 1e8;
const int M = 20000000;
struct Hash_Table
{
	int head[M + 5], nxt[MAXN], val[MAXN], tot;
	Hash_Table(){ tot = 0; }
	LL key[MAXN];
	int hash(LL x){ return x % M + 1; }
	void insert(LL x, int v)
	{
		int h = hash(x);
		nxt[++tot] = head[h], val[tot] = v, key[tot] = x, head[h] = tot;
	}
	int query(LL x)
	{
		int h = hash(x);
		for (int i = head[h]; i; i = nxt[i])
			if (key[i] == x) return val[i];
		return -1;
	}
	void clear()
	{
		for (; tot; tot--)
			key[tot] = nxt[tot] = val[tot] = head[hash(key[tot])] = 0;
	}
} ht;
const double PI = acosl(-1), eps = 1e-10;
struct Point
{
	int x, y, r;
	Point(int _x = 0, int _y = 0): x(_x), y(_y){}
	friend Point operator-(Point p, Point q)
	{ return Point(p.x - q.x, p.y - q.y); }
} a[MAXN];
struct Node
{
	double ang;
	int v, id;
	Node(){}
	Node(double _a, int _b, int _c)
	: ang(_a), v(_b), id(_c){}
} ;
double arg(Point p){ return atan2l((double)p.x, (double)p.y); }
double R;
int n, B, m = 0, cur = 0, K, lim;
std::vector<int> id[MAXN], tmp;
#define bid(x) (((x) + inf) / B + 1)
LL Hash(int i){ return (LL)bid(a[i].x) << 32 | bid(a[i].y); }
void insert(int i)
{
	int v = ht.query(Hash(i));
	if (v == -1) ht.insert(Hash(i), v = ++m);
	id[v].push_back(i);
}
void rebuild(int l, int r)
{
	// l = 1, r = n;
	for (B = 1; B <= R; B <<= 1) ;
	ht.clear();
	for (int i = 1; i <= m; i++) id[i].clear();
	m = 0;
	for (int i = l; i <= r; i++) insert(i);
}
auto sq = [](int x){ return (LL)x * x; };
bool chk(int i, int j){ return 4 * R * R >= sq(a[i].x - a[j].x) + sq(a[i].y - a[j].y); }
double dis(Point p, Point q){ return sqrtl((double)sq(p.x - q.x) + (double)sq(p.y - q.y)); }
Node b[MAXN * 4];
namespace SGT
{
	#define ls (x << 1)
	#define rs (x << 1 | 1)
	int sgt[MAXN << 2], lzy[MAXN << 2];
	void hard(int x, int v){ sgt[x] += v, lzy[x] += v; }
	void spread(int x)
	{ if (lzy[x]) hard(ls, lzy[x]), hard(rs, lzy[x]), lzy[x] = 0; }
	void modify(int x, int l, int r, int ql, int qr, int v)
	{
		if (ql <= l && r <= qr) return hard(x, v);
		int mid = (l + r) >> 1;
		spread(x);
		if (ql <= mid) modify(ls, l, mid, ql, qr, v);
		if (qr > mid) modify(rs, mid + 1, r, ql, qr, v);
		sgt[x] = std::max(sgt[ls], sgt[rs]);
	}
	int query(int x, int l, int r, int ql, int qr)
	{
		if (ql <= l && r <= qr) return sgt[x];
		int mid =  (l + r) >> 1, res = 0;
		spread(x);
		if (ql <= mid) Fmax(res, query(ls, l, mid, ql, qr));
		if (qr > mid) Fmax(res, query(rs, mid + 1, r, ql, qr));
		return res;
	}
}
bool chk(int x)
{
	cur = 0;
	int cnt = 0;
	// printf("----------------%d %.10LF-----------------\n", x, R);
	for (int i = std::max(1, bid(a[x].x) - 2); i <= bid(a[x].x) + 2; i++)
		for (int j = std::max(1, bid(a[x].y) - 2); j <= bid(a[x].y) + 2; j++)
		{
			int k = ht.query((LL)i << 32 | j);
			if (k == -1) continue;
			tmp.clear();
			for (int y : id[k])
			{
				if (y <= x - lim || y >= x + lim) continue;
				tmp.push_back(y);
				if (chk(y, x) && y != x)
				{
					++cnt;
					double dlt = acos(dis(a[x], a[y]) / 2 / R), ang = arg(a[y] - a[x]);
					double l = ang - dlt, r = ang + dlt;
					// printf("%d %d %.10LF %.10LF %.10LF %.10LF\n", x, y, l, r, ang, dlt);
					if (l + eps > 0 && r + eps > 0) b[++cur] = Node(l, 1, y), b[++cur] = Node(r, -1, y);
					else if (l < eps && r < eps)
					{
						l += 2 * PI, r += 2 * PI;
						b[++cur] = Node(l, 1, y), b[++cur] = Node(r, -1, y);
					}
					else
					{
						l += 2 * PI;
						b[++cur] = Node(0, 1, y), b[++cur] = Node(r, -1, y);
						b[++cur] = Node(l, 1, y), b[++cur] = Node(PI * 2 + eps, -1, y);
					}
				}
			}
			std::swap(tmp, id[k]);
		}
	// return 0;
	// if (cnt > 10 * K)
	// {
	// 	printf("!%d %d\n", cnt, K);
	// 	exit(-1);
	// }
	std::sort(b + 1, b + cur + 1, [](Node a, Node b){ return std::abs(a.ang - b.ang) < eps ? a.v < b.v : a.ang < b.ang; });
	int mx = 0;
	for (int i = 1; i <= cur; i++)
	{
		SGT::modify(1, 1, n, std::max(1, b[i].id - lim + 1), b[i].id, b[i].v);
		if (b[i].v == 1) Fmax(mx, SGT::sgt[1]);
	}
	// printf("%d\n", mx);
	return mx >= K - 1;
}
void calc(int x)
{
	// rebuild(std::max(1, x - lim + 1), std::min(n, x + lim - 1));
	if (x + lim - 1 <= n) insert(x + lim - 1);
	if (!chk(x)) return ;
	double l = 0, r = R;
	while (std::abs(r - l) / std::abs(r) > eps)
	{
		double mid = (l + r) / 2;
		std::swap(R, mid);
		if (chk(x)){
			r = R;
			if (B / 2 >= R) rebuild(std::max(1, x - lim + 1), std::min(n, x + lim - 1));
		}
		else std::swap(R, mid), l = mid;
	}
}
int main()
{
	for (int T = read(); T--; )
	{
		n = read(), lim = read(), K = read();
		for (int i = 1; i <= n; i++)
			a[i].x = read(), a[i].y = read();
		R = 4 / sqrt(PI) * 1e8 * sqrt(K - 1) / sqrt(lim);
		rebuild(1, lim - 1);
		for (int i = 1; i <= n; i++) calc(i);
		printf("%.15LF\n", R);
	}
	return 0;
}