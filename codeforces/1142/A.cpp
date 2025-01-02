#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i,a,b) for (ll i=a; i <=b; i++)
#define INF 1<<30
#define md 1000000007
#define FOR(i,n) for(ll i=0; i<n; i++)
#define FORR(i,n) for(ll i=n-1; i>=0; i--)
#define pb push_back
#define vi vector<ll>

ll gcd(ll a, ll b){
    if (!b) return a;
    if (b>a) swap(a,b);
    return gcd(b,a%b);
}


int main(){
    ll n,k; cin >> n >> k;
    ll a,b; cin >> a >> b;
    vector<ll> dst;
    dst.pb({abs(b-a)});
    dst.pb({a+b});
    FOR(i,2) dst.pb(-dst[i]);
    ll mn=(ll)1e15,mx=0;
    FOR(i,n+2){
        FOR(j,4){ //dst[j]+k*i
            ll gcd1=gcd(n*k,abs(dst[j]+k*i)),gcd2=gcd(n*k,abs(n*k-(dst[j]+k*i)));
            mn=min(n*k/gcd1,mn);
            mx=max(n*k/gcd1,mx);
            mn=min(n*k/gcd2,mn);
            mx=max(n*k/gcd2,mx);
            /*
            if (dst[j]+k*i!=0 && n*k%abs(dst[j]+k*i)==0){
                mn=min(n*k/abs(dst[j]+k*i),mn);
                mx=max(n*k/abs(dst[j]+k*i),mx);
            }
            if (n*k-(dst[j]+k*i)!=0 && n*k%abs(n*k-(dst[j]+k*i))==0){
                mn=min(n*k/abs(n*k-(dst[j]+k*i)),mn);
                mx=max(n*k/abs(n*k-(dst[j]+k*i)),mx);
            }*/
        }
    }
    cout << mn << " " << mx << endl;
}