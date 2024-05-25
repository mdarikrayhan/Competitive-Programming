#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define nmax 1000007
#define fi first
#define se second
#define ll long long
ll t=1,n,m=0,i=0,j=0,d=0,x,y,z,a[nmax],b[nmax];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    d=0;
    x=a[n]+1;
    for(i=n;i>=1;--i)
    {
        x--;
        x=min(x,a[i]);
        x=max(x,0LL);
        d+=x;
    }
    cout<<d;
}
