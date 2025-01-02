#include<bits/stdc++.h>
#define ll long long
#define limit(n) __ll128(n);
#define fi cin.tie(NULL)
#define print(a); for (auto i:a){cout<<i<<" ";}cout<<endl;
#define fu cout.tie(NULL)
#define check cout<<"______________________________________"<<endl;
#define fast ios_base::sync_with_stdio(false)
#define minqq_(a) *min_element(a.begin(),a.end());
#define max_(a) *max_element(a.begin(),a.end());
#define input(a,n); for (ll i=0;i<n;i++){ll h; cin>>h; a.push_back(h);}
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
using namespace std;
void solved(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a;
    input(a,n);
    vector<vector<ll>>d;
    map<ll,vector<ll>>g;
    for (ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        d.push_back({x,y});
    }
    if (m%2==0){
        cout<<0<<endl;
        return;
    }
    ll t=1e9;
    vector<ll>v;
    for (ll i=0;i<m;i++){
        if (g[d[i][0]].size()%2==0 and g[d[i][1]].size()%2==0){
            t=min(t,a[d[i][0]-1]+a[d[i][1]-1]);
        }
    }
    for (ll i=1;i<=n;i++){
        if (g[i].size()%2==1){
            t=min(t,a[i-1]);
        }
    }
    cout<<t<<endl;
}
signed main(){
    fi;
    fu;
    fast;
    ll y;
    cin>>y;
    for (ll i=0;i<y;i++){
    solved();
    }

}
