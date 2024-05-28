#include<bits/stdc++.h>
#define Faster ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;





int main()
{
Faster
int t=1;
//cin>>t;
while(t--)
{
    ll a,b,w,x,c;
    cin>>a>>b>>w>>x>>c;
    if(a>=c)
    {
        cout<<0<<'\n';
        continue;
    }
    if((b/x)>=(c-a))
    {
        cout<<c-a<<'\n';
        continue;
    }
    ll ans=0;
    ans+=b/x;
    c-=b/x;
    b%=x;
    ll n=(c-a-1)/((w-x));
    ans+=(w)*n;
    c-=(w)*n;
    a-=n*x;
    while(a<c)
    {
        ans++;
        c--;
        if(b<x)
        {
            b+=w;
            a--;
        }
            b-=x;
    }
    cout<<ans<<'\n';
}
}
/*
1
234
437
435
354654
*/
