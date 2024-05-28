#include <bits/stdc++.h>
#define pb push_back
#define s second
#define f first
#define left (h<<1),l,((l+r)>>1)
#define right ((h<<1)|1),((l + r)>>1) + 1,r
#define pii pair <int,int>
#define int long long
using namespace std;
 
const int N = 1e5+5,inf=1e18;
 
int heavy[N],sz[N],timer,tin[N],tout[N],head[N],n;
int par[N],lz[4*N];
vector <int> v[N];
pii t[4*N];

void dfs(int x,int pr){
    sz[x] = 1;
    for (int to: v[x]){
        if (to == pr) continue;
        dfs(to,x);
        par[to] = x;
        sz[x] += sz[to];
        if(sz[to] > sz[heavy[x]]){
            heavy[x] = to;
        }
    }
}

void dfs2(int x,int pr,int h){
    head[x] = h;
    tin[x] = ++timer;
    if (heavy[x]) dfs2(heavy[x],x,h);

    for (int to: v[x]){
        if (to == pr || to == heavy[x]) continue;
        dfs2(to,x,to);
    }
    tout[x] = timer;
}

void push(int h,int l,int r){
    if (lz[h] == 0) return;
    lz[h*2] = lz[h*2+1] = 1;
    t[h*2] = {-1,-((l + r)/2 - l + 1)};
    t[h*2+1] = {-1,-(r - (l + r)/2)};
    lz[h] = 0;
}

pii merge(pii x,pii y){
    if (x.f == -inf) return y;
    if (y.f == -inf) return x;
    return {max(y.f,x.f + y.s),x.s + y.s};
}

void upd(int h,int l,int r,int idx,int vl){
    if (l == r){
        t[h].f += vl;
        t[h].s += vl;
        return;
    }

    push(h,l,r);
    if (idx > (l + r)/2) upd(right,idx,vl);
    else upd(left,idx,vl);
    t[h] = merge(t[h*2],t[h*2+1]);
}

void build(int h,int l,int r){
    if (l == r){
        t[h] = {-1,-1};
        return;
    }
    build(left);
    build(right);
    t[h] = merge(t[h*2],t[h*2+1]);
}

void updr(int h,int l,int r,int L,int R){
    if (r < L || R < l) return;
    if (L <= l && r <= R){
        t[h].f = -1;
        t[h].s = -(r - l + 1);
        lz[h] = 1;
        return;
    }

    push(h,l,r);
    updr(left,L,R);
    updr(right,L,R);
    t[h] = merge(t[h*2],t[h*2+1]);
}

pii get(int h,int l,int r,int L,int R){
    if (r < L || R < l) return {-inf,-inf};
    if (L <= l && r <= R) return t[h];
    push(h,l,r);
    return merge(get(left,L,R),get(right,L,R));
}

int getans(int x){
    pii ans = {-inf,-inf};
    while(x){
        ans=merge(get(1,1,n,tin[head[x]],tin[x]),ans);
        x=par[head[x]];
    }
    return ans.f;
}

signed main (){
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    int q;
    cin>>n>>q;
    for (int i=2;i<=n;i++){
        int a;
        cin>>a;
        v[a].pb(i);
        v[i].pb(a);
    }

    dfs(1,1);
    dfs2(1,1,1);
    build(1,1,n);

    while (q--){
        int tp,x;
        cin>>tp>>x;

        if (tp == 1){
            upd(1,1,n,tin[x],+1);
        }else if (tp == 2){
            updr(1,1,n,tin[x],tout[x]);
            int k = getans(x);
            if (k >= 0) upd(1,1,n,tin[x],-k-1);
        }else if (tp==3){
            if (getans(x) >= 0) cout<<"black\n";
            else cout<<"white\n";
        }
    }
} 