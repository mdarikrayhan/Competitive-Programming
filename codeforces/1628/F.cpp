#include<bits/stdc++.h>
#define fi first
#define se second
#define MP std::make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef std::pair<int, int> pii;
typedef std::pair<LL, LL> pll;
#define clr(f, n) memset(f, 0, (n) << 2)
#define cpy(f, g, n) memcpy(f, g, (n) << 2)
LL read()
{
	LL s = 0; int f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9'))
		f ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9')
		s = s * 10 + (c ^ 48), c = getchar();
	return f ? s : -s;
}
const int MAXN = 5005, MOD = 1e9 + 7;
template<typename T>
T& Fmin(T& x, T y){ return x = x < y ? x : y; }
template<typename T>
T& Fmax(T& x, T y){ return x = x < y ? y : x; }
int fplus(int x, int y){ return x + y >= MOD ? x + y - MOD : x + y; }
int fminus(int x, int y){ return x >= y ? x - y : x + MOD - y; }
int& Fplus(int& x, int y){ return x = fplus(x, y); }
int& Fminus(int& x, int y){ return x = fminus(x, y); }
int fpow(int x, int y = MOD - 2)
{
    int res = 1;
    for (; y; y >>= 1, x = (LL)x * x % MOD)
        if (y & 1) res = (LL)res * x % MOD;
    return res;
}
struct Point 
{
    int x, y;
    Point(int _x = 0, int _y = 0)
    : x(_x), y(_y){}
    friend Point operator+(Point p, Point q)
    { return Point(p.x + q.x, p.y + q.y); }
    friend Point operator-(Point p, Point q)
    { return Point(p.x - q.x, p.y - q.y); }
    friend Point operator-(Point p)
    { return Point(-p.x, -p.y); }
    friend int operator*(Point p, Point q)//dot
    { return p.x * q.x + p.y * q.y; }
    friend int operator/(Point p, Point q)//cross
    { return p.x * q.y - p.y * q.x; }
    friend int operator!(Point p)
    { return p.x * p.x + p.y * p.y; }
    bool side() { return y < 0 || (y == 0 && x < 0); }
    friend bool operator<(Point p, Point q)
    {
        if (p.side() != q.side()) return p.side() < q.side();
        return p / q > 0;
    }
    friend bool operator<=(Point p, Point q)
    { return p < q || (p / q == 0 && p * q > 0); }
} dir[MAXN], tmp[MAXN], P[MAXN];
bool TC = false;
LL sq(int x){ return (LL)x * x; }
int n, Q, m = 0, N = 0, a[MAXN], b[MAXN], q[MAXN];
int A[MAXN], B[MAXN], C[MAXN];
int nxt[MAXN][MAXN], vis[MAXN];
bool reach[MAXN][MAXN];
std::vector<pii> line[MAXN];
double func(int i, Point d)
{ return (double)(sq(C[i]) * !d) / sq(Point(A[i], B[i]) * d); }
namespace LiChao
{
    #define ls (x << 1)
    #define rs (x << 1 | 1)
    int sgt[MAXN << 2];
    void insert(int x, int l, int r, int v)
    {
        if (!sgt[x]) return sgt[x] = v, void();
        int mid = (l + r) >> 1;
        if (func(sgt[x], dir[mid]) > func(v, dir[mid]))
            std::swap(sgt[x], v);
        if (l == r) return ;
        if (func(sgt[x], dir[l]) > func(v, dir[l]))
            insert(ls, l, mid, v);
        else insert(rs, mid + 1, r, v);
    }
    void insert(int x, int l, int r, int ql, int qr, int v)
    {
        if (ql <= l && r <= qr) return insert(x, l, r, v);
        int mid = (l + r) >> 1;
        if (ql <= mid) insert(ls, l, mid, ql, qr, v);
        if (qr > mid) insert(rs, mid + 1, r, ql, qr, v);
    }
    void insert(int l, int r, int v) { insert(1, 1, m, l, r, v); }
    int query(int x, int l, int r, int pos)
    {
        if (l == r) return sgt[x];
        int mid = (l + r) >> 1;
        int res = pos <= mid ? query(ls, l, mid, pos) : query(rs, mid + 1, r, pos);
        if (!res || !sgt[x]) return res | sgt[x];
        return func(res, dir[pos]) < func(sgt[x], dir[pos]) ? res : sgt[x];
    }
    void clear(int x, int l, int r)
    {
        sgt[x] = 0;
        if (l == r) return ;
        int mid = (l + r) >> 1;
        clear(ls, l, mid), clear(rs, mid + 1, r);
    }
}
bool NOW = false;
void calc(int id)
{
    LiChao::clear(1, 1, m);
    for (int i = 1; i <= n; i++)
    {
        if (id == a[i] || id == b[i]) continue;
        Point pa = P[a[i]] - P[id], pb = P[b[i]] - P[id];
        int ida, idb;
        if (pa / pb < 0) std::swap(pa, pb);
        ida = std::lower_bound(dir + 1, dir + m + 1, pa) - dir;
        idb = std::upper_bound(dir + 1, dir + m + 1, pb) - dir - 1;
        if (pa / pb == 0 && ida == idb)
            line[ida].emplace_back(i, std::min(!pa, !pb));
        else if (pa / pb > 0)
        {
            A[i] = pa.y - pb.y, B[i] = pb.x - pa.x, C[i] = pa / pb;
            if (pa < pb && ida <= idb) LiChao::insert(ida, idb, i);
            else if (pb < pa)
            {
                if (ida <= m) LiChao::insert(ida, m, i);
                if (idb) LiChao::insert(1, idb, i);
            }
        }
    }
    // if (TC) return ;
    for (int i = 1; i <= m; i++)
    {
        int res = LiChao::query(1, 1, m, i);
        double dis = 0;
        if (res) dis = func(res, dir[i]);
        for (pii p : line[i]) 
            if (!res || dis > p.se) res = p.fi, dis = p.se;
        line[i].clear();
        if (!res)
        {
            if (dir[i] / P[id] == 0 && dir[i] * P[id] < 0) 
                nxt[id][i] = 0;
            else nxt[id][i] = -1;
        }
        else if (dir[i] / P[id] == 0 && dir[i] * P[id] < 0 && (!P[id]) < dis)
            nxt[id][i] = 0;
        else
        {
            Point seg = P[a[res]] - P[b[res]];
            int ID = a[res];
            if (dir[i] * seg < 0) seg = -seg, ID = b[res];
            if (sq(dir[i] * seg) <= (LL)!seg * !dir[i] / 2)
                nxt[id][i] = -1;
            else nxt[id][i] = ID;
        }
    }
}
void dfs(int x, int d)
{
    if (x == -1 || vis[x]) return ;
    if (nxt[x][d] == -1) reach[x][d] = false;
    else dfs(nxt[x][d], d), reach[x][d] = reach[nxt[x][d]][d];
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        P[a[i] = ++N].x = read(), P[N].y = read();
        P[b[i] = ++N].x = read(), P[N].y = read();
    }
    TC = n == 1500 && P[a[1]].x == -493;
    for (int i = 1; i <= n * 2; i++) tmp[i] = -P[i];
    std::sort(tmp + 1, tmp + N + 1);
    for (int i = 1; i <= N; i++)
        if (i == 1 || tmp[i] / tmp[i - 1] != 0) 
            dir[++m] = tmp[i];
    for (int i = 1; i <= N; i++) calc(i);
    // if (TC) return 0;
    for (int d = 1; d <= m; d++)
    {
        memset(vis + 1, false, N);
        vis[0] = reach[0][d] = true;
        for (int x = 1; x <= N; x++)
            dfs(x, d);
    }
    Q = read();
    for (int i = 1; i <= Q; i++)
    {
        int cur = ++N;
        P[cur].x = read(), P[cur].y = read();
        bool f = true, ans = false;
        for (int j = 1; j <= n; j++)
        {
            Point pa = P[a[j]] - P[cur], pb = P[b[j]] - P[cur];
            if (pa / pb == 0)
            {
                if (pa / -P[cur] == 0 && pa * -P[cur] > 0 && std::min(!pa, !pb) < !P[cur])
                { f = false; break; }
                continue;
            }
            if (pa / pb < 0) std::swap(pa, pb);
            A[j] = pa.y - pb.y, B[j] = pb.x - pa.x, C[j] = pa / pb;
            if (func(j, -P[cur]) > !P[cur]) continue;
            if (pa < pb && pa <= -P[cur] && -P[cur] <= pb){ f = false; break; }
            if (pb < pa && (pa <= -P[cur] || -P[cur] <= pb)){ f = false; break; }
        }
        if (f){ printf("YES\n"); continue; }
        calc(cur);
        for (int d = 1; d <= m; d++)
            if (nxt[cur][d] != -1 && (nxt[cur][d] == 0 || reach[nxt[cur][d]][d]))
            { ans = true; break; }
        printf(ans ? "YES\n" : "NO\n");
    }
	return 0;
}
  		 		 	   	      	 		      		