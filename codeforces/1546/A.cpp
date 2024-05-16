#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define nmax 1000007
#define fi first
#define se second
#define ll long long
ll t=1,n,m=0,i=0,j=0,d=0,x,y,z,a[nmax],b[nmax],k,h;
pair<ll,ll>f[nmax];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        d=0;
        for(i=1;i<=n;++i)
        {
            cin>>b[i];
            d+=abs(a[i]-b[i]);
        }
        if(d%2==1){cout<<"-1\n";continue;}
        j=0;
        d/=2;
        h=d;
        while(d>0)
        {
            d--;
            k=0;
            for(i=1;i<=n;++i)
            {
                for(z=1;z<=n;++z)
                    if(i!=z)
                {
                    if(a[i]>b[i]&&a[z]<b[z])
                    {
                        j++;
                        f[j].fi=i;
                        f[j].se=z;
                        a[i]--;
                        a[z]++;
                        k=1;
                        break;
                    }
                    if(a[i]<b[i]&&a[z]>b[z])
                    {
                        j++;
                        f[j].fi=z;
                        f[j].se=i;
                        a[z]--;
                        a[i]++;
                        k=1;
                        break;
                    }
                }
                if(k)break;
            }
        }
        if(h!=j){cout<<"-1\n";continue;}
        cout<<j<<"\n";
        for(i=1;i<=j;++i)cout<<f[i].fi<<" "<<f[i].se<<"\n";
    }
}
