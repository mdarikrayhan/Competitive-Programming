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
const ll N=1005,G=-2e9,M=2e6+5,H1=1000159,H2=1000133,mod=999999893,mod1=998244353,ha=13331,gg=(mod+1)/2;
ll n,a[N][N],m,q,R[N*N],X[N*N],c[N*N],b[N][N];
ll get(ll x,ll y){
    return x*(m+2)+y;
}
void solve(){
    for(ll j=0;j<=m;j++){
        b[0][j]=get(0,j);
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            b[i+1][j]=X[b[i][j]];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<c[b[i][j]]<<" ";
        }cout<<endl;
    }
}

int main(){
    IOS;cin>>n>>m>>q;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
            c[get(i,j)]=a[i][j];
        }
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            X[get(i,j)]=get(i+1,j);
            R[get(i,j)]=get(i,j+1);
        }
    }

    while(q--){
        ll sx,sy,tx,ty,h,w;
        cin>>sx>>sy>>tx>>ty>>h>>w;
        ll ss=get(sx-1,0),st=get(tx-1,0);
        for(ll j=0;j<sy;j++) ss=R[ss];
        for(ll j=0;j<ty;j++) st=R[st];
        for(ll j=1;j<=w;j++) swap(X[ss],X[st]),ss=R[ss],st=R[st];

        ss=get(sx-1+h,0);st=get(tx-1+h,0);
        for(ll j=0;j<sy;j++) ss=R[ss];
        for(ll j=0;j<ty;j++) st=R[st];
        for(ll j=1;j<=w;j++) swap(X[ss],X[st]),ss=R[ss],st=R[st];

        ss=get(0,sy-1);st=get(0,ty-1);
        for(ll j=0;j<sx;j++) ss=X[ss];
        for(ll j=0;j<tx;j++) st=X[st];
        for(ll j=1;j<=h;j++) swap(R[ss],R[st]),ss=X[ss],st=X[st];

        ss=get(0,sy+w-1);st=get(0,ty+w-1);
        for(ll j=0;j<sx;j++) ss=X[ss];
        for(ll j=0;j<tx;j++) st=X[st];
        for(ll j=1;j<=h;j++) swap(R[ss],R[st]),ss=X[ss],st=X[st];
    }
    solve();
}