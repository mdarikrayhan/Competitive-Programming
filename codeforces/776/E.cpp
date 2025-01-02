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
int get(int y)
{
    int ans=0;
    if(y==1)
        return 1;
    for(int i=1;i<y;i++)
    {
        int j=y-i;
        if(__gcd(i,j)!=1)
            continue;
        ans++;
    }
    return ans;
}
int gg(int y)
{
    int ans=0;
    for(int i=1;i<=y;i++)
        if(y%i==0)
            ans+=get(y/i);
    return ans;
}
vector<ll>v;
const int N=1000100;
bool prime[N];
void prec()
{
    for(int i=2;i<N;i++)
        prime[i]=1;
    for(int i=2;i<N;i++)
    {
        for(int j=i*i;j<N;j+=i)
        {
            prime[i]=0;
        }
        v.pb(i);
    }
}
ll n,y,k;
int w;
vector<ll>q;
ll getback(int i,ll cnt,ll all)
{
    if(i==w)
    {
        if(cnt%2==1)
            return -(y/all);
        return y/all;
    }
    return getback(i+1,cnt+1,all*q[i]) +getback(i+1,cnt,all);
}
ll solve(ll x)
{
    q.clear();
    y=x;
    for(auto c:v)
    {
        if(c*c>y)
            break;
        if(y%c==0)
        {
            q.pb(c);
            while(y%c==0)
                y/=c;
        }
    }
    if(y!=1)
        q.pb(y);
    y=x-1;
    w=q.size();
    return getback(0,0,1);
}
int main()
{
    prec();
    scl(n);scl(k);
    k=(k+1)/2;
    while(n!=1 && k!=0)
    {
        k--;
        n=solve(n);
    }
    prl(n%mod);
    return 0;
}
