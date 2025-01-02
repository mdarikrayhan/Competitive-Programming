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
typedef __int128 bg;
typedef unsigned long long ull;
typedef string str;
typedef long double db;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
typedef pair<int,int> pii;
typedef pair<pll,pll> pp;
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
const ll N=3e5+6,G=-2e9,M=5005,H1=1000159,H2=1000133,mod1=999999893,mod=1e9+7,ha=13331,gg=(mod+1)/2;
ll n,m;
int main(){
    IOS;cin>>n>>m;
    if(__gcd(n,m)!=1){cout<<"Impossible"<<endl;return 0;}
    bg a=0,b=1,c=1,d=0,p1,p2,g,dn=m,X=n,Y=m,e,f;
    vector<pll> op;
    while(1){
        ll tag=0;
        for(ll i=0;i<2;i++){
            for(ll j=60;j>=0;j--){
                p1=p2=1;
                if(i) p1<<=j;else p2<<=j;
                e=p1*a+p2*c;f=p1*b+p2*d;
                g=__gcd(e,f);e/=g;f/=g;
                if(f>dn) continue;
                if(i){
                    if(e*Y>X*f) c=e,d=f,tag=1,op.push_back({p1,1});
                }
                else{
                    if(e*Y<X*f) a=e,b=f,tag=1,op.push_back({p2,0});
                }
            }
        }
        if(tag==0) break;
    }
    vector<pll> ans;
    ll len=op[0].fi;
    for(ll i=1;i<op.size();i++){
        if(op[i].se==op[i-1].se) len+=op[i].fi;
        else{
            ans.push_back({len,op[i-1].se});
            len=op[i].fi;
        }
    }
    ans.push_back({len,op.back().se});
    for(auto i:ans){
        cout<<i.fi<<(char)('A'+i.se);
    }cout<<endl;
}