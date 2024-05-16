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

const ll N = 1e5+10, mod=1073741824, MOD = 1e8, OO = 1e18+10;bool f=true;

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    cin(a,n);
    if (n==k){
        cout<<0<<el;
        return;
    }
    if (k==1){
        cout<<a[n-1]-a[0]<<el;
        return;
    }
    vector<ll> dif(n-1);
    for (int i=1;i<n;i++){
        ll x=a[i]-a[i-1];
        dif[i-1]=x;
    }
    sort(all(dif));
    
    ll ans=0;
    for (int i=0;i<n-k;i++){
        ans+=dif[i];
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
