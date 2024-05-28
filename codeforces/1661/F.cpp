#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k;
vector<int> a;
int f(int a,int c) {
    if(c==0) return inf;
    int c2=a%c,s=a/c;
    return (c-c2)*s*s+c2*(s+1)*(s+1);
}
int bs_f(int x,int m) {//know limit m , find number of tele
    int l=1,r=x+1,mid;
    while(l<r) {//last i : f(x,i-1)-f(x,i)>=m 
        mid=l+r+1>>1;
        if(f(x,mid-1)-f(x,mid)>=m) l=mid;
        else r=mid-1;
    }
    return l;
}
pii cal(int m) {
    int r=0,an=0;
    REP(i,n) {
        int ret=bs_f(a[i],m);
        r+=ret-1;
        an+=f(a[i],ret);
    }
    // op(m)op(r)ope(an)
    return {r,an};
}
signed main() {
    IOS();
    cin>>n;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    int l=0,r=a[n-1]*a[n-1],m;
    for(int i=n-1;i>0;i--) a[i]-=a[i-1];
    cin>>k;
    while(l<r) {// first m : cost(m)>k
        m=l+r>>1;
        if(cal(m).s>k) r=m;
        else l=m+1;
    }
    auto [cnt,cost]=cal(l);
    // op(l)op(cnt)ope(cost)
    int ans=cnt+(cost-k+l-2)/(l-1);
    cout<<ans<<'\n';
    return 0;
}
