#if __has_include("pch.hpp")
#include "pch.hpp"
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//ld rand(ld a, ld b) {uniform_real_distribution<ld> uni(a, b); return uni(mt_rand);}
//const ld PI=3.141592653589793238462643383279;
const int mxN=1e6+50000;
const int mod=998244353;
const int mxlogN=18;
const ll inf=1e18;
const int iinf=1e9;
const int K=450;
pair<int,ll> dp[1002][6722];
ll a[1001], b[1001];
vector<ll> dvs;
int fnd(ll x)
{
    return lower_bound(dvs.begin(),dvs.end(),x)-dvs.begin();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; ll k; cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) b[i]=__gcd(k,a[i]);
    if(k==1)
    {
        cout << "1\n";
        cout << min_element(a+1,a+1+n)-a << "\n";
        return 0;
    }
    for(ll i=1; i*i<=k; i++)
    {
        if(k%i==0)
        {
            dvs.push_back(i);
            if(i*i!=k) dvs.push_back(k/i);
        }
    }
    sort(dvs.begin(), dvs.end());
    int d=dvs.size();
    for(int i=1; i<d; i++) dp[0][i]={n+1,0};
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<d; j++)
        {
            int j2=fnd(dvs[j]/__gcd(dvs[j],b[i]));
            dp[i][j]=min(dp[i-1][j],{dp[i-1][j2].first+1,dp[i-1][j2].second+a[i]});
        }
    }
    if(dp[n][d-1].first>n) cout << "-1\n";
    else
    {
        cout << dp[n][d-1].first << "\n";
        int j=d-1;
        for(int i=n; i; i--)
        {
            if(dp[i][j]!=dp[i-1][j])
            {
                j=fnd(dvs[j]/__gcd(dvs[j],b[i]));
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}

