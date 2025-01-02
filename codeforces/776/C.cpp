#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prl(x) printf("%lld\n",x)
#define yes printf("YES\n")
#define no printf ("NO\n")
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define tmp (l+r)/2
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ld pi=2*acos(0);
const ll mod=1e9+7;
const ld eps=1e-9;
const ll ll_max=2e18;
///const ll mod=998244353;

using namespace std;

int main()
{
    ll mx=1e14;
    map<ll,ll>fre;
    ll n,k;
    scl(n);scl(k);
    ll x=0;
    fre[0]=1;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll y;
        scl(y);
        x+=y;
        ll h=1;
        while(abs(h)<=mx)
        {
            ans+=fre[x-h];
            h=h*k;
            if(h==1)
                break;
        }
        fre[x]++;
    }
    prl(ans);
    return 0;
}
