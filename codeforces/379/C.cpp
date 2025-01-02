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

const ll N = 2e5+10, mod=1073741824, MOD = 1e9+7, OO = 1e18+10;bool f=true;

void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    vll ans(n);
    sort(all(a));
    ll cnt=0;
    for (auto x:a){
        cnt=max(x.first,cnt+1);
        ans[x.second]=cnt;
    }
    for (auto x:ans){
        cout<<x<<" ";
    }
    cout<<el;
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
