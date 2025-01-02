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
    ll n,k,avg;
    cin>>n>>k>>avg;
    pair<ll,ll>a[n];
    ll sum=0;
    ll want=n*avg;
    for (int i=0;i<n;i++){
        cin>>a[i].second;
        cin>>a[i].first;
        sum+=a[i].second;
    }
    sort(a,a+n);
    ll ans=0;
    if (sum<want){
        for(int i=0;i<n;i++){
            ll mn=min(want-sum,k-a[i].second);
            ans+=(mn*a[i].first);
            sum+=mn;
            if (sum>=want)break;
        }
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
