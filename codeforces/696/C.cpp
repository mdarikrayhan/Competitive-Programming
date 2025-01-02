#include<bits/stdc++.h>
#define Faster ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;



const int N=1e5+100;
ll mod=1e9+7;
ll fpow(ll a,ll b)
{
    if(a==0)return 0;
    if(b==0)return 1;
    ll x=fpow(a,b/2);
    if(b&1)
    return x*x%mod*a%mod;
    return x*x%mod;
}
int main()
{
Faster
int t=1;
//cin>>t;
while(t--)
{
    ll ans=2;
    int n;
    cin>>n;
    bool a=1;
    ll p[n];
    ll ba,ma;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        ans=fpow(ans,p[i]);
        if(p[i]%2==0)
            a=0;
    }

    ma=ans*fpow(2,mod-2)%mod;
    ba=(ma+!a-a)*fpow(3,mod-2)%mod;
    cout<<ba<<'/'<<ma;
}
}
/*
2
467131402341701583 956277077729692725

*/
