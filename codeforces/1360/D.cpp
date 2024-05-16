#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
ll const inf = 1e17+1;
ll const M = 1e5+10;
ll const N = 1e6;
const int mod = 1e9+7;
ll dx[8]={-1,0,1,0,1,-1,-1,1};
ll dy[8]={0,1,0,-1,1,-1,1,-1};

ll gcd(ll a, ll b)
{
    return b==0 ? a : gcd(b,a%b);
}

void solve(int t) {
    // cout << "Case #" << t << ": ";
    ll n,k; cin>>n>>k;
    ll ans = INT_MAX;
    for(ll i=1;i*i<=n;i++) {
        if(n%i == 0) {
            if(i <= k) {
                ans = min(ans, n/i);
            }
            if(n/i <= k) {
                ans = min(ans, i);
            }
        }
    }

    cout<<ans<<endl;
} 
        
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen("div7.in","r",stdin);
    // freopen("div7.out","w",stdout);
    // #endif
    int T;
    cin >> T ;
    for(int t = 1; t <= T; t++)solve(t);
    // solve(1);
}

// 001 110 111 



