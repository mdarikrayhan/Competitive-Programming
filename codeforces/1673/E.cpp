#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll N=1<<20;
ll n,k,b[N+5],ps[N+5],res[N+5],s[25][N+5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("a.inp","r"))
    {
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin>>n>>k;
    k=n-k-1;
    for (ll i=1;i<=n;i++)
    {
        cin>>b[i];
        ll j=i;
        ll d=0;
        while (j)
        {
            if (~j&1)
            {
                d++;
            }
            else
            {
                break;
            }
            j/=2;
        }
        ps[i]=ps[i-1]+d;
    }
    for (ll i=1;i<=min((ll)22,n);i++)
    {
        for (ll j=0;j<=n;j++)
        {
            if (j)
            {
                s[i][j]=s[i][j-1];
            }
            bool kt=(ps[n-i]==ps[j]+ps[n-i-j]);
            if (i+j>n)
            {
                kt=false;
            }
        //  cout<<i<<' '<<j<<' '<<s[i][j]<<' '<<kt<<' '<<ps[n-i]<<' '<<ps[j]<<' '<<'\n';
            s[i][j]^=kt;
        }
    }
    for (ll i=1;i<=n;i++)
    {
        ll t=b[i];
        ll j=i;
        while (j<=n)
        {
            if (j-i>k) break;
            ll kc=j-i+1;
            if (i>1) kc++;
            if (j<n) kc++;
    //      cout<<val<<' 'i<<'\n';
            ll nw=k-(j-i);
            res[t]^=s[kc][nw];
            j++;
            if (b[j]>20||t*(1ll<<b[j])>=N) break;
            t*=(1ll<<b[j]);
        }
    }
    bool chk=true;
    for (ll i=N-1;i>=0;i--)
    {
        if (res[i])
        {
            chk=false;
        }
        if (!chk)
        {
            cout<<res[i];
        }
    }
    if (chk)
    {
        cout<<0;
    } 
}