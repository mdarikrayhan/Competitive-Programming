#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define IOS ios::sync_with_stdio(0),cin.tie(0)
typedef long long ll; 
typedef pair<ll,ll> p;
const int N=1e6+5;
ll dp[N];
ll ksm(ll x,ll y)
{
    ll ans=1;
    for(;y;)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
ll get_inv(ll x){return ksm(x,mod-2);}
int main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        ll ct1=0,ct2=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            ct1++;
            else
            ct2++;
        }
        if(ct1==0)
        {
            cout<<0<<'\n';
            continue;   
        }
        dp[n]=1;
        for(int i=n-1;i>=1;i--)
        {
            dp[i]=(n+(n-i)*dp[i+1])%mod*get_inv(i)%mod;
        }
        ll sum=0;
        for(int i=1;i<=ct1;i++)
        sum=(sum+dp[i])%mod;
        cout<<sum<<'\n';
    }
}