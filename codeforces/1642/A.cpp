#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define nmax 100007
#define fi first
#define se second
#define ll long long
#define ld long double
ll t=1,n,m,i;
pair<ll,ll>a[7];
bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.se!=b.se)return a.se<b.se;
    return a.fi<b.fi;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        for(i=1;i<=3;++i)
        {
            cin>>a[i].fi>>a[i].se;
        }
        sort(a+1,a+4,cmp);
        if(a[1].se==a[2].se&&a[2].se>a[3].se)
        {
            cout<<a[2].fi-a[1].fi<<"\n";
            continue;
        }
        if(a[3].se==a[2].se&&a[2].se>a[1].se)
        {
            cout<<a[3].fi-a[2].fi<<"\n";
            continue;
        }
        cout<<"0\n";
    }
}
