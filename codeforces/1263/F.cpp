/*****************************************
备注：
******************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define int ll
const int MAXN = 1e6 + 10;
const int MR = 2e3 + 5;
const int INF = 0x7f7f7f7f;
const int MOD = 1e9 + 7;
const int _ = 0;
const bool debug = false;
struct ios {
    inline char read() {
        static const int inlen = 1 << 18 | 1;
        static char buf[inlen], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, inlen, stdin)), s == t ? -1 : *s++;
    }
    template<typename T> inline ios& operator>> (T &x) {
        static char c11, boo;
        for (c11 = read(), boo = 0; !isdigit(c11); c11 = read()) {
            if (c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for (x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} fin;
struct exios {
    template<typename _CharT, typename _Traits = char_traits<_CharT>>
    struct typ {
        typedef basic_ostream<_CharT, _Traits>& (* end) (basic_ostream<_CharT, _Traits>&);
    };

    template<typename T> friend exios &operator<<(exios &out, T num) {
        if (num < 0) putchar('-'), num = -num;
        if (num >= 10) out << num / 10;
        putchar(num % 10 + '0');
        return out;
    }

    friend exios &operator<<(exios &out, const char * s) { printf("%s", s); return out; }
    friend exios &operator<<(exios &out, string s) { cout << s; return out; }
    friend exios &operator<<(exios &out, typ<char>::end e) { puts(""); return out; }
} fout;

int n, a, b;
int x[MAXN], y[MAXN], p[MAXN], qq[MAXN];
int st, et;

int head[MAXN], ne[MAXN], to[MAXN], w[MAXN], id = 1;
void add(int x, int y, int z) 
{
    to[++id] = y;
    w[id] = z;
    ne[id] = head[x];
    head[x] = id;

    to[++id] = x;
    w[id] = 0;
    ne[id] = head[y];
    head[y] = id;
}
int dis[MAXN];
bool bfs()
{
    memset(dis, -1, sizeof(dis));
    dis[st] = 1;
    queue<int> que;
    que.push(st);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i = head[u]; i; i = ne[i])
        {
            int v = to[i];
            if(dis[v] == -1 && w[i])
            {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
    return dis[et] != -1;
}
int dfs(int u,int low)
{
    if (u == et || low == 0)return low;
    int used = 0;
    for(int i = head[u]; i; i = ne[i])
    {
        if (dis[to[i]] == dis[u] + 1)
        {
            int v = to[i];
            int ww = dfs(v, min(w[i], low - used));
            used += ww;
            w[i] -= ww;
            w[i ^ 1] += ww;
            if(used == low)return low;
        }
    }
    if(used == 0)dis[u] = -1;
    return used;
}
int dinic()
{
    int ans = 0;
    while(bfs())ans += dfs(st, INF);
    return ans;
}

signed main()
{
	// int start = clock();
	cin >> n >> a;
	for(int i = 2; i <= a; i++)cin >> p[i];
	for(int i = 1; i <= n; i++)cin >> x[i];
	cin >> b;
	for(int i = 2; i <= b; i++)cin >> qq[i];
	for(int i = 1; i <= n; i++)cin >> y[i];
	st = a + b + 2;
	et = a + b + 3;
	for(int i = 2; i <= a; i++)
	{
		add(st, i, 1);
		add(p[i], i, INF);
	}
	for(int i = 2; i <= b; i++)
	{
		add(a + i, et, 1);
		add(a + i, a + qq[i], INF);
	}
	for(int i = 1; i <= n; i++)add(x[i], a + y[i], INF);
	cout << a + b - 2 - dinic();
    // printf("%.3lf", clock() - start);
    return ~~(0^_^0);
}	