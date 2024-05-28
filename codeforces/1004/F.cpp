// LUOGU_RID: 160038596
//私は猫です
#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){
    int xx = 0, f = 1; char ch = getchar();
    for (;!isdigit(ch); ch = getchar())
        f = (ch == '-' ? -1 : 1);
    for (; isdigit(ch); ch = getchar())
        xx = (xx << 3) + (xx << 1) + ch - '0';
    return xx * f;
}
const int N = 100100;
struct arr{
    int a[32];
    void clear(){a[0] = 0;}
    void pb(int val){a[++a[0]] = val;}
    void add(int val){for (int i = 1; i <= a[0]; ++i)a[i] += val;}
};
int n, m, V, a[N];
struct node{
    int ans, len;
    arr pre, suf, preid, sufid;
}tr[N << 2];
node operator + (node x, node y){
    node ret; ret.ans = x.ans + y.ans, ret.len = x.len + y.len;
    ret.pre = x.pre, ret.preid = x.preid,
    ret.suf = y.suf, ret.sufid = y.sufid;
    ret.sufid.add(x.len);
    int lenl = x.suf.a[0], lenr = y.pre.a[0];
    for (int i = lenl, j = 1; i >= 1; --i){
        if (x.suf.a[i] >= V){
            ret.ans += (x.sufid.a[i] - (i == lenl ? 0 : x.sufid.a[i + 1])) * y.len;
            continue;
        }
        while(j <= lenr && (x.suf.a[i] | y.pre.a[j]) < V)++j;
        if (j > lenr)break;
        ret.ans += (x.sufid.a[i] - (i == lenl ? 0 : x.sufid.a[i + 1])) * 
                   (y.len - y.preid.a[j] + 1);
    }
    int tmp = y.suf.a[y.suf.a[0]];
    for (int i = 1; i <= lenl; ++i)if ((tmp | x.suf.a[i]) > tmp)
        tmp = tmp | x.suf.a[i],
        ret.suf.pb(tmp), ret.sufid.pb(x.sufid.a[i]);
    tmp = x.pre.a[x.pre.a[0]];
    for (int i = 1; i <= lenr; ++i)if ((tmp | y.pre.a[i]) > tmp)
        tmp = tmp | y.pre.a[i],
        ret.pre.pb(tmp), ret.preid.pb(x.len + y.preid.a[i]);
    return ret;
}
node addp(int val){
    node ret; ret.ans = (val >= V), ret.len = 1;
    ret.pre.clear(), ret.pre.pb(val),
    ret.preid.clear(), ret.preid.pb(1),
    ret.suf.clear(), ret.suf.pb(val),
    ret.sufid.clear(), ret.sufid.pb(1);
    return ret;
}
void build(int x, int l, int r){
    if (l == r){tr[x] = addp(a[l]); return ;}
    int mid = (l + r) >> 1;
    build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
    tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
void upd(int x, int l, int r, int nl){
    if (l == r){tr[x] = addp(a[l]); return ;}
    int mid = (l + r) >> 1;
    if (nl <= mid)upd(x << 1, l, mid, nl);
    else upd(x << 1 | 1, mid + 1, r, nl);
    tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
node query(int x, int l, int r, int nl, int nr){
    if (nl <= l && r <= nr)return tr[x];
    int mid = (l + r) >> 1; node ret;
    if (nl <= mid){
        ret = query(x << 1, l, mid, nl, nr);
        if (nr > mid)ret = ret + query(x << 1 | 1, mid + 1, r, nl, nr);
    }
    else ret = query(x << 1 | 1, mid + 1, r, nl, nr);
    return ret;
}
signed main(){
    n = read(), m = read(), V = read();
    for (int i = 1; i <= n; ++i)a[i] = read();
    build(1, 1, n);
    for (int i = 1, op, l, r; i <= m; ++i){
        op = read(), l = read(), r = read();
        if (op == 1)a[l] = r, upd(1, 1, n, l);
        else printf("%lld\n", query(1, 1, n, l, r).ans);
    }
    return 0;
}

