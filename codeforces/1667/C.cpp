#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)
const ll N=1e5+100;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    if (n==1)
    {
        cout<<"1\n1 1\n";
    }
    else
    {
        ll m=(2*n+1)/3;
        cout<<m<<'\n';
        while (n%3!=2) cout<<n<<' '<<n<<'\n',n--,m--;
        vector<pll> vt;
        F(i,1,(m+1)/2) 
            vt.pb(mp(i,(m+1)/2-i+1));
        F(i,1,m/2) 
            vt.pb(mp((m+1)/2+i,m-i+1));
     /*   F(i,1,n)
        {
            F(j,1,n)
            {
                bool ch=0;
                for (auto p:vt)
                {
                    if (i==p.fi||j==p.se||i-j==p.fi-p.se)
                    {
                        ch=1;
                        break;
                    }
                }
                if (!ch)
                {
                    cout<<"sai cmnr";
                    return 0;
                }
            }
        }*/
        for (auto p:vt) cout<<p.fi<<' '<<p.se<<'\n';
    }
}