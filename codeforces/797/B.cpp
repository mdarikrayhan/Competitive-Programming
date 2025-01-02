#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define cin(a,n) for (int i=0;i<n;i++) cin>>a[i]
#define el '\n'
#define unq(vec) vec.resize(distance(vec.begin(),unique(all(vec))));
#define el_bo3bo3 cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

const ll N = 1e5+10, mod=1073741824, MOD = 1e9+7, OO = 1e18+10;bool f=true;

void solve()
{
    ll n;
    cin>>n;
    vll v;
    ll ans=0;
    for (int i=0;i<n;i++){
        ll x;
        cin>>x;
        if (x%2==0){
            if (x>0)ans+=x;
        }else {
            v.pb(x);
        }
    }
    sort(all(v));
    ans+=v.back();
    v.pop_back();
    while (v.size()>1){
        ll x=v.back();
        v.pop_back();
        ll y=v.back();
        v.pop_back();
        ll cur=x+y;
        if (cur>0)ans+=cur;
    }
    cout<<ans<<el;
}

int main ()
{
el_bo3bo3;
ll t=1;
//cin>>t;
while (t--)
solve();
return 0;
}
