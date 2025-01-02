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
typedef int ll;
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
const ll N=2505,G=-2e9,M=N*100,H1=1000159,H2=1000133,mod1=999999893,mod=1e9+7,ha=13331,gg=(mod+1)/2;
ll n,a[N],n1,g,c[N];
ll check(ll X){
    ll num=0;
    for(ll i=0;i<n;i++){
        if((a[i]/X)%2==1) num++;
    }
    if(num<=1) return 1;
    else return 0;
}
void solve(){
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=c[i]/2;j++){
            cout<<(char)(i+'a');
        }
    }
    for(ll i=0;i<n;i++){
        if(c[i]%2==1) cout<<(char)(i+'a');
    }
    for(ll i=n-1;i>=0;i--){
        for(ll j=1;j<=c[i]/2;j++){
            cout<<(char)(i+'a');
        }
    }
}
int main(){
    IOS;cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        g=__gcd(g,a[i]);
        if(a[i]%2==1) n1++;
    }
    
    for(ll i=1;i<=g;i++){
        if(g%i!=0) continue;
        if(check(g/i)){
            ll v=((n1==0)+(i!=1));
            v=max(1,v);
            cout<<g/i*v<<endl;
            for(ll k=0;k<n;k++){
                c[k]=a[k]/(g/i);
            }
            for(ll o=1;o<=g/i;o++){
                solve();
            }cout<<endl;return 0;
        }
    }
    cout<<0<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=a[i];j++){
            cout<<(char)(i+'a');
        }
    }cout<<endl;
}