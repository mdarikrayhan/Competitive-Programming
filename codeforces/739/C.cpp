// LUOGU_RID: 160406863
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[300005];
struct point{
    int pre[3], suf[3], ans;
    int tag;
    int st, en;
    int len;
}f[1200005];
point operator+(point x, point y){
    point ans;
    ans.pre[0] = x.pre[0];
    if(x.pre[0] == x.len && x.en < y.st)ans.pre[0] += y.pre[0];
    ans.pre[1] = x.pre[1];
    if(x.pre[1] == x.len && x.en > y.st)ans.pre[1] += y.pre[1];
    ans.pre[2] = x.pre[2];
    if(x.pre[0] == x.len){
        if(x.en < y.st)ans.pre[2] += y.pre[2];
        if(x.en > y.st)ans.pre[2] += y.pre[1];
    }else if(x.pre[2] == x.len && x.en > y.st){
        ans.pre[2] += y.pre[1];
    }
    ans.suf[0] = y.suf[0];
    if(y.suf[0] == y.len && x.en < y.st)ans.suf[0] += x.suf[0];
    ans.suf[1] = y.suf[1];
    if(y.suf[1] == y.len && x.en > y.st)ans.suf[1] += x.suf[1];
    ans.suf[2] = y.suf[2];
    if(y.suf[1] == y.len){
        if(x.en < y.st)ans.suf[2] += x.suf[0];
        if(x.en > y.st)ans.suf[2] += x.suf[2];
    }else if(y.suf[2] == y.len && x.en < y.st){
        ans.suf[2] += x.suf[0];
    }
    ans.ans = max(x.ans, y.ans);
    if(x.en < y.st)ans.ans = max(ans.ans, x.suf[0] + y.pre[2]);
    if(x.en > y.st)ans.ans = max(ans.ans, x.suf[2] + y.pre[1]);
    ans.tag = 0;
    ans.st = x.st;
    ans.en = y.en;
    ans.len = x.len + y.len;
    return ans;
}
void down(int now){
    f[now * 2].tag += f[now].tag;
    f[now * 2].st += f[now].tag;
    f[now * 2].en += f[now].tag;
    f[now * 2 + 1].tag += f[now].tag;
    f[now * 2 + 1].st += f[now].tag;
    f[now * 2 + 1].en += f[now].tag;
    f[now].tag = 0;
}
void up(int now){
    f[now] = f[now * 2] + f[now * 2 + 1];
}
void init(int now, int l, int r){
    if(l == r){
        f[now].pre[0] = f[now].pre[1] = f[now].suf[0] = f[now].suf[1] = f[now].ans = f[now].pre[2] = f[now].suf[2] = 1;
        f[now].tag = 0;
        f[now].st = f[now].en = a[l];
        f[now].len = 1;
        return;
    }
    int mid = l+r>>1;
    init(now * 2, l, mid);
    init(now * 2 + 1, mid + 1, r);
    up(now);
}
void change(int now, int l, int r, int x, int y, int k){
    if(x <= l && r <= y){
        f[now].st += k;
        f[now].en += k;
        f[now].tag += k;
        return;
    }
    down(now);
    int mid = l+r>>1;
    if(x <= mid)change(now * 2, l, mid, x, y, k);
    if(y > mid)change(now * 2 + 1, mid + 1, r, x, y, k);
    up(now);
}
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
    init(1, 1, n);
    int m;
    cin >> m;
    while(m--){
        int l, r, d;
        scanf("%lld%lld%lld", &l, &r, &d);
        change(1, 1, n, l, r, d);
        printf("%lld\n", f[1].ans);
    }
    return 0;
}