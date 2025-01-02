// LUOGU_RID: 158265014
#include <iostream>
#include <algorithm>

typedef long long ll;
typedef double lf;

// #define DEBUG 1
struct IO
{
    #define MAXSIZE (1 << 20)
    #define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
    #if DEBUG
    #else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() {fwrite(pbuf, 1, pp - pbuf, stdout);}
    #endif
    #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? ' ' : *p1++)
    #define blank(x) (x == ' ' || x == '\n' || x == '\r' || x == '\t')

    template <typename T>
    void Read(T &x)
    {
        #if DEBUG
        std::cin >> x;
        #else
        bool sign = 0; char ch = gc(); x = 0;
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch ^ 48);
        if (sign) x = -x;
        #endif
    }
    void Read(char *s)
    {
        #if DEBUG
        std::cin >> s;
        #else
        char ch = gc();
        for (; blank(ch); ch = gc());
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
        #endif
    }
    void Read(char &c) {for (c = gc(); blank(c); c = gc());}

    void Push(const char &c)
    {
        #if DEBUG
        putchar(c);
        #else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
        #endif
    }
    template <typename T>
    void Write(T x)
    {
        if (x < 0) x = -x, Push('-');
        static T sta[35];
        int top = 0;
        do sta[top++] = x % 10, x /= 10; while (x);
        while (top) Push(sta[--top] ^ 48);
    }
    template <typename T>
    void Write(T x, char lst) {Write(x), Push(lst);}
} IO;
#define Read(x) IO.Read(x)
#define Write(x, y) IO.Write(x, y)
#define Put(x) IO.Push(x)

using namespace std;

const int MAXN = 2e5 + 10;

int n, q;

struct FenwickTree
{
    ll bit[MAXN];
    inline void Add(int x, ll k) {for (; x <= n; x += (x & -x)) bit[x] += k;}
    inline ll Ask(int x) {ll res = 0; for (; x; x -= (x & -x)) res += bit[x]; return res;}
}TK, TB;
inline void RangeAdd(int l, int r, ll k)
{
    TK.Add(l, k), TK.Add(r + 1, -k);
    TB.Add(l, k * (1 - l)), TB.Add(r + 1, k * r);
}
inline ll RangeSum(int l, int r)
{
    return TK.Ask(r) * r + TB.Ask(r) - TK.Ask(l - 1) * (l - 1) - TB.Ask(l - 1);
}

struct Node
{
    int mx1, mx2, cnt;
    int lz;
}tr[MAXN << 2];
inline void Pushup(int cur)
{
    tr[cur].mx1 = max(tr[cur << 1].mx1, tr[cur << 1 | 1].mx1);
    tr[cur].mx2 = tr[cur].cnt = 0;
    if (tr[cur << 1].mx1 == tr[cur].mx1) tr[cur].mx2 = max(tr[cur].mx2, tr[cur << 1].mx2), tr[cur].cnt += tr[cur << 1].cnt;
    else tr[cur].mx2 = max(tr[cur].mx2, tr[cur << 1].mx1);
    if (tr[cur << 1 | 1].mx1 == tr[cur].mx1) tr[cur].mx2 = max(tr[cur].mx2, tr[cur << 1 | 1].mx2), tr[cur].cnt += tr[cur << 1 | 1].cnt;
    else tr[cur].mx2 = max(tr[cur].mx2, tr[cur << 1 | 1].mx1);
}
void Build(int cur, int l, int r)
{
    tr[cur].lz = 2e9;
    if (l == r) tr[cur].mx1 = l, tr[cur].mx2 = -2e9, tr[cur].cnt = 1;
    else
    {
        int mid = l + r >> 1;
        Build(cur << 1, l, mid), Build(cur << 1 | 1, mid + 1, r);
        Pushup(cur);
    }
}
inline void Pushdown(int cur)
{
    if (tr[cur].lz == 2e9) return;
    tr[cur << 1].mx1 = min(tr[cur << 1].mx1, tr[cur].lz), tr[cur << 1].lz = min(tr[cur << 1].lz, tr[cur].lz);
    tr[cur << 1 | 1].mx1 = min(tr[cur << 1 | 1].mx1, tr[cur].lz), tr[cur << 1 | 1].lz = min(tr[cur << 1 | 1].lz, tr[cur].lz);
    tr[cur].lz = 2e9;
}
void Modify(int cur, int l, int r, int x, int k)
{
    if (l == r)
    {
        if (tr[cur].mx1 < k) RangeAdd(tr[cur].mx1 + 1, k, 1);
        else if (tr[cur].mx1 > k) RangeAdd(k + 1, tr[cur].mx1, -1);
        tr[cur].mx1 = k;
    }
    else
    {
        Pushdown(cur);
        int mid = l + r >> 1;
        if (x <= mid) Modify(cur << 1, l, mid, x, k);
        else Modify(cur << 1 | 1, mid + 1, r, x, k);
        Pushup(cur);
    }
}
void Update(int cur, int l, int r, int x, int y, int k)
{
    if (k >= tr[cur].mx1) return;
    if (x <= l && r <= y && k > tr[cur].mx2)
    {
        RangeAdd(k + 1, tr[cur].mx1, -tr[cur].cnt);
        tr[cur].mx1 = tr[cur].lz = k;
    }
    else
    {
        Pushdown(cur);
        int mid = l + r >> 1;
        if (x <= mid) Update(cur << 1, l, mid, x, y, k);
        if (y > mid) Update(cur << 1 | 1, mid + 1, r, x, y, k);
        Pushup(cur);
    }
}

int main()
{
    #if DEBUG
    #else
    ios::sync_with_stdio(0), cin.tie(0);
    #endif
    Read(n), Read(q);

    RangeAdd(1, n, 1), Build(1, 1, n);

    int op, x, y;
    while (q--)
    {
        Read(op), Read(x), Read(y);
        if (op == 1)
        {
            if (x > 1) Update(1, 1, n, 1, x - 1, x - 1);
            Modify(1, 1, n, x, y);
        }
        else cout << RangeSum(x, y) << '\n';
    }
    return 0;
}