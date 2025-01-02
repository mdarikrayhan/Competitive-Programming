#include <bits/stdc++.h>
using namespace std;
struct Init {
Init() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0);
#endif
}
} init__;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef double ld;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define rep(x,l,r) for(int x=(l);x<(r);++x)
#define rep0(x,n) for(int x=0;x<(n);++x)
#define rep1(x,n) for(int x=1;x<=(n);++x)
#define sz(s) (int((s).size()))
#define SZ 666666
int T,n,fa[SZ],a[SZ],D;
vector<int> ch[SZ];
int dep[SZ];
vector<int> dd[SZ];
map<int,ll> F[SZ];
void dfs(int x) {
    // cerr<<x<<":"<<dep[x]<<" "<<D<<"\n";
    for(auto b:ch[x]) {
        dep[b]=dep[x]+1,dfs(b);
    }
}
vector<ll> da[SZ];
void sol() {
    cin>>n; D=0;
    for(int i=0;i<=n;++i) dd[i].clear(),F[i].clear(),
        ch[i].clear(),da[i].clear();
    for(int i=2;i<=n;++i) cin>>fa[i],ch[fa[i]].pb(i);
    for(int i=2;i<=n;++i) cin>>a[i];
    dfs(1);
    for(int i=1;i<=n;++i)
        D=max(D,dep[i]),dd[dep[i]].pb(i),da[dep[i]].pb(a[i]);
    for(auto g:dd[D]) F[D][g]=0;
    for(int i=0;i<=D;++i) sort(all(da[i]));
    for(int i=D-1;i>=0;--i) {
        ll mx0=-8e18,mx1=-8e18;
        for(auto g:F[i+1])
            mx0=max(mx0,g.se-a[g.fi]),
            mx1=max(mx1,g.se+a[g.fi]);
        for(auto x:dd[i]) {
            ll mx=-8e18;
            for(auto t:ch[x]) mx=max(mx,F[i+1][t]+max(abs(a[t]-*da[i+1].begin()),
                                                      abs(a[t]-*da[i+1].rbegin())));
            for(auto t:ch[x]) {
                mx=max(mx,mx1-a[t]);
                mx=max(mx,mx0+a[t]);//F[i+1][any_dep]+abs(a[t]-that_thing));
            }
            F[i][x]=mx;
        }
    }
    printf("%lld\n",F[0][1]);
}
int main() {
    cin>>T;
    while(T--) sol();
}