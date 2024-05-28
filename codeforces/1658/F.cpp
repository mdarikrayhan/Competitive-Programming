#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)
const ll N=4e5+100;

ll n,m,f[N];
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("a.inp","r"))
    {
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    ll t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>s;

        s="#"+s;
        ll d=0;
        F(i,1,n)
        {
            if (s[i]=='1') d++;
        }
        F(i,1,2*n)
        {
            ll nw;
            if (i>n) nw=s[i-n]-'0';
            else nw=s[i]-'0';
            f[i]=f[i-1]+nw;
        }
        if (d*m%n!=0)
        {
            cout<<-1<<'\n';
            continue;
        }
        ll pt=d*m/n;
        F(i,m,2*n)
        {
            if (f[i]-f[i-m]==pt)
            {
                if (i>n)
                {
                    cout<<2<<'\n';
                    cout<<1<<' '<<i-n<<'\n';
                    cout<<i-m+1<<' '<<n<<'\n';
                }
                else
                {
                    cout<<1<<'\n';
                    cout<<i-m+1<<' '<<i<<'\n';
                }
                break;
            }
        }
    }
}
/*
4
(())
1 2
2 3
3 4*/