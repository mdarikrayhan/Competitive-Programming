
#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define mod 1000000007
//auto cmp = [](pair<int,int> a, pair<int,int> b){return a.second < b.second;};

bool cmp(ll a, ll b, ll c, ll d, ll e, ll f){
    if(abs(a*d - b*c) * b * f - abs(a*f - b * e) * b * d > 0)return true;
    return false;
}

int main(){
    ll x, y, n;
    cin>>x>>y>>n;
    pair<ll, ll> curbest {100100, 1};
    for(int d = 1; d<=n; d++){
        int c = (x * d)/y;
        if(cmp(x, y, curbest.first, curbest.second, c, d))curbest = {c, d};
        c++;
        if(cmp(x, y, curbest.first, curbest.second, c, d))curbest = {c, d};
    }
    cout<<curbest.first<<"/"<<curbest.second<<"\n";

}