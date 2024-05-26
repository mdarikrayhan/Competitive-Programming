#include <bits/stdc++.h>
using namespace std;
typedef  long long ll; 
typedef vector<ll> vll;
typedef vector<vll> vvll;  
typedef vector<vvll> vvvll;
ll const M = 1e9 + 7;

ll n;
vector<pair<ll,ll>> v;
vvll dp;


ll f(ll i, ll j){
    if(i==n)return 0;
    else if(dp[i][j]!=-1)return dp[i][j];
    else{
        return dp[i][j] = min(f(i+1,j) + v[i].first - v[j].first, f(i+1,i) + v[i].second);
    }
}

int main(){
    cin>>n;

    ll x,c;
    for(ll i=0;i<n;i++){
        cin>>x>>c;
        v.push_back({x,c});
    }

    sort(v.begin(), v.end());
    ll ans = v[0].second;

    dp.resize(n,vll(n,-1));

    ans += f(1,0);
    cout<<ans<<"\n";
}   
