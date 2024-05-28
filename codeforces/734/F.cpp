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
const int mxN=2e6+100000;
const int mod=1e9+7;
const int mxlogN=18;
const ll inf=1e18+1;
const int iinf=1e9;
const int K=8;
ll a[mxN], b[mxN], c[mxN], cnt[mxN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];
    ll s=0;
    for(int i=0; i<n; i++) s+=b[i]+c[i];
    s/=2*n;
    for(int i=0; i<n; i++) a[i]=(b[i]+c[i]-s)/n;
    for(int i=0; i<n; i++) for(int j=0; j<60; j++) if(a[i]>>j&1) cnt[j]++;
    int ok=1;
    for(int i=0; i<n; i++)
    {
        ll sm=0,sm2=0;
        for(int j=0; j<60; j++)
        {
            if(a[i]>>j&1) sm+=cnt[j]<<j;
            if(a[i]>>j&1) sm2+=n<<j;
            else sm2+=cnt[j]<<j;
        }
        if(sm!=b[i] || sm2!=c[i]) ok=0;
    }
    if(ok )for(int i=0; i<n; i++) cout << a[i] << " ";
    else cout << "-1\n";
}
