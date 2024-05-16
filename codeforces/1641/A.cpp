// g++ cfr.cpp -o p && ./p
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <bitset>
#define all(x) x.begin(), x.end()
#define __vec(x, n) vector<ll> x(n); for(ll i=0;i<n;++i)cin>>x[i]
#define __for(_x, _t) for(ll _x=0;_x<_t;++_x)
#define __ll(n) ll n; cin>>n
using namespace std;
typedef long long ll;
void solve(){
    __ll(n);
    __ll(x);
    __vec(a,n);
    sort(all(a));
    map<ll,ll> cnt;
    __for(i, n)cnt[a[i]]++;
    __for(i, n){
        if(cnt[a[i]]&&cnt[a[i]*x]){
            cnt[a[i]]--;
            cnt[a[i]*x]--;
        }
    }
    ll ans=0;
    set<ll> uniq(all(a));
    for(auto k:uniq)
        ans+=cnt[k];
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;cin>>t;while(t--)
    solve();
    return 0;
}