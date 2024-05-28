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
const ll N=2e5+5,G=-2e9,M=1e6+5,H1=1000159,H2=1000133,mod1=999999893,mod=1e9+7,ha=13331,gg=(mod+1)/2;
multiset<ll> s;
ll n,a[N],c[5],d[N],us[N];
void up(ll X){
    if(s.size()==0) return;
    auto it=s.upper_bound(X);
    if(it!=s.begin()){
        it--;ll w=(*it);
        s.erase(s.find(w));
    }
}
ll solve(){
    for(ll i=1;i<=n;i++){
        s.insert(a[i]);
    }
    for(ll i=1;i<=n+n;i++){
        if(s.size()==0) return i-1;
        ll w=*s.rbegin();s.erase(s.find(w));
        if(c[1]>=w) up(c[2]),up(c[3]);
        else if(c[2]>=w) up(c[1]),up(c[3]);
        else if(c[3]>=w){
            auto it=s.upper_bound(c[1]);
            if(it!=s.begin()) up(c[1]),up(c[2]);
            else up(c[1]+c[2]);
        }
        else if(c[1]+c[2]>=w) up(c[3]);
        else if(c[1]+c[3]>=w) up(c[2]);
        else if(c[2]+c[3]>=w) up(c[1]);
        else if(c[1]+c[2]+c[3]>=w) continue;
        else return -1;
        //for(auto j:s) cout<<j<<" ";cout<<endl;
    }
    return -1;
}
int main(){
    IOS;cin>>n;
    for(ll i=1;i<=3;i++){
        cin>>c[i];
    }
    sort(c+1,c+1+3);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<solve()<<endl;
}