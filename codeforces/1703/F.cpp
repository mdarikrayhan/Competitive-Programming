#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll mod= 998244353;

ll bsearch(vector<ll>&good,ll r,ll val){
    ll l=-1;
    while(r>l+1){
        ll mid=(l+r)/2;
        if(good[mid]<val){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    return l;
}

void solve(){
    ll n;cin>>n;

    vector<ll>good;
    vector<ll>val;
    vector<ll>v(n+1);

    for(int i=1;i<=n;i++)cin>>v[i];

    for(int i=1;i<=n;i++){
        if(i>v[i]){
            good.pb(i);
            val.pb(v[i]);
        }   
    }

    ll N=good.size()-1;
    ll ans=0;

    for(int i=N;i>=0;i--){
        ll ind = bsearch(good,i,val[i]);
        ind++;
        ans+=(ind);
    }

    cout<<ans<<endl;


}
 
signed main() {
    int t;cin>>t;
    while(t--){
        solve();
    }
}