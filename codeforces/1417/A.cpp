#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define endl "\n"
#define Amgad ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

void Solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=(k-v[i])/v[0];
    }
    cout<<ans<<endl;
}

int main()
{
    Amgad
    ll T=1;
    cin>>T;
    while(T--)
    {
        Solve();
    }
}
