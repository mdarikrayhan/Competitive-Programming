//#pragma GCC optimize("Ofast","unroll-loops","O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
//#include <atcoder/all>
//using namespace atcoder;
//using mint = modint998244353;
using namespace std;
using cd=complex<double>;
#define fi first
#define se second
#define eps 1e-15
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define HP(x) cout<<fixed<<setprecision(x);
#define popcnt(x) __builtin_popcountll(x)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define sumv(a) accumulate(all(a), 0LL)
#define lb(v,a) (lower_bound(begin(v),end(v),a)-begin(v))
#define ub(v,a) (upper_bound(begin(v),end(v),a)-begin(v))
#define inq(x,l,r) (l<=x&& x<=r)
#define uniq(t) (sort(all(t)),t.erase(unique(all(t)),t.end()))
typedef long long ll;
//typedef __int128 big;
typedef unsigned long long ull;
typedef string str;
typedef long double db;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
typedef pair<int,int> pii;
typedef pair<ll,pll> pp;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<vector<ll>> mal;
typedef vector<vector<int>> mai;
typedef vector<vector<str>> mas;
typedef vector<vector<db>> mad;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());//rnd()%n,shuffle(a+1,a+1+n,rnd);
const db PI = acos(-1.0L);
const ll N=1e5+5,G=-2e9,M=2e6+5,H1=1000159,H2=1000133,mod=999999893,mod1=998244353,ha=13331,gg=(mod+1)/2;
ll n,a[N],q;
struct ppp{ll l,r,sum[61];}tr[N*4];
ppp up(ppp ls,ppp rs){
    ppp v;v.l=ls.l;v.r=rs.r;
    for(ll j=0;j<60;j++){
        ll st=ls.sum[j];
        v.sum[j]=st+rs.sum[(st+j)%60];
    }
    return v;
}
void build(ll i,ll l,ll r){
    tr[i].l=l;tr[i].r=r;
    if(l==r){
        for(ll j=0;j<60;j++){
            if(j%a[l]==0) tr[i].sum[j]=2;
            else tr[i].sum[j]=1;
        }return;
    }
    ll m=(l+r)/2;build(i*2,l,m);build(i*2+1,m+1,r);
    tr[i]=up(tr[i*2],tr[i*2+1]);
}
void update(ll i,ll l,ll r,ll v){
    if(tr[i].l>=l&&tr[i].r<=r){
        for(ll j=0;j<60;j++){
            if(j%v==0) tr[i].sum[j]=2;
            else tr[i].sum[j]=1;
        }return;
    }
    ll m=(tr[i].l+tr[i].r)/2;
    if(l<=m) update(i*2,l,r,v);
    if(r>m) update(i*2+1,l,r,v);
    tr[i]=up(tr[i*2],tr[i*2+1]);
}
ppp query(ll i,ll l,ll r){
    if(tr[i].l>=l&&tr[i].r<=r){
        return tr[i];
    }
    ll m=(tr[i].l+tr[i].r)/2,ans=0;
    if(l>m) return query(i*2+1,l,r);
    else if(r<=m) return query(i*2,l,r);
    else return up(query(i*2,l,r),query(i*2+1,l,r));
}
int main(){
    IOS;cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);cin>>q;
    while(q--){
        char op;ll x,y;cin>>op>>x>>y;
        if(op=='C'){
            a[x]=y;update(1,x,x,y);
        }
        else{
            ppp v=query(1,x,y-1);
            cout<<v.sum[0]<<"\n";
        }
    }
}