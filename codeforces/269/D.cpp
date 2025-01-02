// LUOGU_RID: 159781597
#include <bits/stdc++.h>
using namespace std;
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
char buf[1000000], *p1 = buf, *p2 = buf;
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -f;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...y)
{
    read(x);
    read(y...);
}
template <class T>
void write(T x)
{
    static int stk[30];
    if (x < 0)
        putchar('-'), x = -x;
    int top = 0;
    do
    {
        stk[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(stk[--top] + '0');
}
template <class T>
void write(T x, char lastChar) { write(x), putchar(lastChar); }
template <typename T>
void chkmx(T &x, T y) { x = max(x, y); }
struct ODT
{
    struct node
    {
        int l, r;
        mutable int v;
        node(int l, int r = 0, int v = 0) : l(l), r(r), v(v) {}
        bool operator<(const node &b) const { return l < b.l; }
    };
    set<node> s;
    auto split(int pos)
    {
        auto it = s.lower_bound(node(pos));
        if (it != s.end() && it->l == pos)
            return it;
        it--;
        int l = it->l, r = it->r;
        int v = it->v;
        if (r < pos)
            return s.end();
        s.erase(it);
        s.insert(node(l, pos - 1, v));
        return s.insert(node(pos, r, v)).first;
    }
    void assign(int l, int r, int x)
    {
        auto itr = split(r + 1), itl = split(l);
        s.erase(itl, itr);
        s.insert(node(l, r, x));
    }
} T;
const int inf = 1000000000;
struct node
{
    int h, l, r;
} a[100020];
int n, t;
int f[100020];
int U(int l1, int r1, int l2, int r2) { return min(r1, r2) - max(l1, l2) + 1; }
bool ok(int x, int y) { return a[x].h < a[y].h && U(a[x].l, a[x].r, a[y].l, a[y].r) >= 1; }
int main()
{
    read(n, t);
    for (int i = 1; i <= n; i++)
        read(a[i].h, a[i].l, a[i].r), a[i].r--;
    sort(a + 1, a + n + 1, [&](node a, node b)
         { return a.h > b.h; });
    T.s.insert(ODT::node(-inf, inf, 0));
    a[0] = {t, -inf, inf};
    a[n + 1] = {0, -inf, inf};
    f[0] = inf << 1;
    for (int i = 1; i <= n + 1; i++)
    {
        auto [h, l, r] = a[i];
        vector<ODT::node> v;
        for (auto itr = T.split(r + 1), itl = T.split(l); itl != itr; itl++)
            v.push_back(*itl);
        for (int j = 0; j < v.size(); j++)
        {
            if (j - 1 >= 0 && ok(v[j - 1].v, v[j].v))
                continue;
            if (j + 1 < v.size() && ok(v[j + 1].v, v[j].v))
                continue;
            chkmx(f[i], min(f[v[j].v], U(l, r, v[j].l, v[j].r)));
        }
        T.assign(l, r, i);
    }
    write(f[n + 1]);
    return 0;
}
