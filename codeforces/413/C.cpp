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

const ll N = 1e7+10, MOD = 1e9+7, OO = 1e18+10;bool f=true;

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[n];
    vll v;
    ll sum=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=0;i<m;i++){
        ll x;
        cin>>x;
        sum-=a[x-1];
        v.pb(a[x-1]);
    }
    sort(rall(v));
    for (int i=0;i<v.size();i++){
        if (v[i]>sum){
            sum+=v[i];
        }else {
            sum*=2;
        }
    }
    cout<<sum<<el;
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
