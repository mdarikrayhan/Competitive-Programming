#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

#define fi(l, r) for (ll i = l; i < r; i++)
#define fj(l, r) for (ll j = l; j < r; j++)
#define in(n) ll n; cin >> n
#define inarr(arr,n) for (ll i = 0; i < n; i++) { cin >> arr[i]; }

void solve() {
    ll x,y;
    cin>>x>>y;
    ll m;
    if(x*y >0){
        m = -1;
    }
    else{
        m = 1;
    }

    ll Y = y - (m*x);
    ll X = ((m*x) - y)/m;

    pair<ll,ll> o,t;
    o = make_pair(X,0);
    t = make_pair(0,Y);

    if(o.first < t.first){
        cout<<o.first<<" "<<o.second<<" "<<t.first<<" "<<t.second<<endl;
        return;
    }
    cout<<" "<<t.first<<" "<<t.second<<" "<<o.first<<" "<<o.second<<endl;
    

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
        solve();
    
}