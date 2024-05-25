#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define F first
#define S second
#define ff first
#define ss second
#define str string
#define ll long long
#define ull unsigned ll
#define ld long double
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define pllll pair<pll,pll>
#define vl vector<ll>
#define vll vector<pll>
#define vlll vector<plll>
#define vllll vector<pllll>
#define vb vector<bool>
#define sz size()
#define fr front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define bk back();
using namespace std;
const ld pi=3.14159265359;
const ll e5=1e5;
const ll e6=1e6;
const ll e9=1e9;
const ll inf=1e18;
const ll mod=1e9+7;
const ll mod2=998244353;
const ll N=2e5+5;
ll bpm(ll x,ll y,ll m){if(y==0)return 1%m;if(y==1)return x%m;ll p=bpm(x,y/2,m);
if(y%2==0)return p*p%m;else return p*p%m*x%m;}
ll bp(ll x,ll y){if(y==0)return 1;if(y==1)return x;ll p=bp(x,y/2);
if(y%2==0)return p*p;else return p*p*x;}
void solve(){
    ll n;
    cin>>n;
    str a[n+1], b[n+1];
    pair<str,ll> s[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        str x="";
        x=x+a[i][0]+a[i][1]+a[i][2];
        s[i]={x,i};
    }
    ll x=n;
    while(x--){
        sort(s+1,s+n+1);
        for(ll i=1;i<=n;i++){
            if(i>1&&s[i].F==s[i-1].F){
                s[i-1].F[2]=b[s[i-1].S][0];
                if(i==n||s[i].F!=s[i+1].F){
                    s[i].F[2]=b[s[i].S][0];
                }
            }
        
        }
    }
    sort(s+1,s+n+1);
    for(ll i=1;i<=n;i++){
        if(i>1&&s[i].F==s[i-1].F){
            cout<<"NO";
            return;
        }
        a[s[i].S]=s[i].F;
    }
    cout<<"YES\n";
    for(ll i=1;i<=n;i++) cout<<a[i]<<'\n';
    return;
}
int main(/*Aldk*/){
    ios_base::sync_with_stdio(false);  cin.tie(NULL);
    //freopen("01.in", "r", stdin);
    //freopen("01.out ", "w", stdout);
    //cout<<setprecision(4)<<fixed;
    ll test=1;
    //cin>>test;
    for(ll i=1;i<=test;i++){
        solve();
		cout<<'\n';
    }
    return 0;
}