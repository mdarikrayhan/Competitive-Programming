#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define int long long
#define ld long double
#define endl "\n"
#define FOCUS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void Go() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main() {
    Go();
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n/2-1;i++)
        {
            ans+=(1ll<<i);
        }
        ans+=(1ll<<n);
        for(int i=n/2;i<=n-1;i++)ans-=(1ll<<i);
        cout<<ans<<endl;

    }

    return 0;
}