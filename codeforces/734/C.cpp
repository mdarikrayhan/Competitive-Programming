#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define ld long double
using namespace std;
const int M = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m,k,x,s,r=LLONG_MAX;cin >> n >> m >> k >> x >> s;vector<ll>a(m+1),b(m+1),c(k),d(k);a[0]=x;b[0]=0;
    for (ll i = 1; i <= m; i++)cin >> a[i];
    for (ll i = 1; i <= m; i++)cin >> b[i];
    for (ll i = 0; i < k; i++)cin >> c[i];
    for (ll i = 0; i < k; i++)cin >> d[i];
    for (ll i = 0; i < m+1; i++)
    {
        if(b[i]>s)continue;
        ll it=upper_bound(d.begin(),d.end(),s-b[i])-d.begin(),rmd=n;
        if(it!=0){
            it--;rmd-=c[it];
        }r=min(r,rmd*min(x,a[i]));
    }cout << r;
}