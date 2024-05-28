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
typedef __int128 big;
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
const ll N=1e5+6,G=-2e9,M=5005,H1=1000159,H2=1000133,mod1=999999893,mod=1e9+7,ha=13331,gg=(mod+1)/2;
ll n,m,a[N],p[105][N],c[N];
vector<pll> b[N];
int main(){
    IOS;cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=m;i++){
        ll l,r,k;cin>>l>>r>>k;
        b[k].push_back({l,r});
    }
    p[0][0]=1;
    for(ll i=0;i<=101;i++){
        for(ll j=1;j<=n;j++){
            if(i>0) p[i][j]=p[i-1][j]+p[i][j-1]%mod;
            else p[i][j]=p[i][j-1];
        }
    }

    vector<pp> pre;
    for(ll i=100;i>=0;i--){
        for(auto j:pre){
            ll k=j.fi-i,len=j.se.se-j.se.fi+1,r=j.se.se;
            c[r+1]-=p[k][len];c[r+1]%=mod;
        }
        for(auto j:b[i]){
            c[j.fi]++;c[j.se+1]--;
            pre.push_back({i,j});
        }
        for(ll j=1;j<=n;j++){
            c[j]+=c[j-1];c[j]%=mod;
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<(a[i]+c[i]%mod+mod)%mod<<" ";
    }cout<<endl;
}