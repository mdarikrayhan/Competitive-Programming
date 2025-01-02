#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using llu=unsigned long long;
using ll=long long;
using ld=long double;
using vl=vector<ll>;
using sl=set<ll>;
using msl=multiset<ll>;
using prq=priority_queue<ll>;
using ma=map<ll,ll>;
using vp=vector<pair<ll,ll>>;
using vvl=vector<vector<ll>>;
using sp=set<pair<ll,ll>>;
using msp=multiset<pair<ll,ll>>;
#define mod 1000000007
#define mod2 998244353
#define inf 9223372036854775807
#define nfs string::npos
#define mat(v,n,m) vector<vector<ll>>v(n,vector<ll>(m,0))
#define maxi(v) max_element(all(v))
#define mini(v) min_element(all(v))
#define lb(n) lower_bound(n)
#define ub(n) upper_bound(n)
#define lbd(v,n) lower_bound(all(v),n)
#define ubd(v,n) upper_bound(all(v),n)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define fv(i,a,b) for(i=a;i>=b;i--)
#define f(i,n) for(i=0;i<n;i++)
#define fn(i,n) for(i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define g(v,n) vl v(n); f(_,n) cin>>v[_]
#define bs(n,x) bitset<n> (x).to_string()
#define invp(v,n) vp v;f(_,n){cin>>__;v.pb(mp(__,_+1));}
#define seev(v) for(auto ggg:v) cout<<ggg<<"-"
#define print(v) for(auto ggg:v) cout<<ggg<<" "

ll gcd_dio(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=gcd_dio(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
ll inverse(ll a,ll m)
{
    ll x,y;
    ll g=gcd_dio(a,m,x,y);
    if(g!=1)
        return -1;
    else
    {
        x=(x%m+m)%m;
        return x;
    }
}
ll power(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1)
            res=(res*a)%inf;
        a=(a*a)%inf;
        b=b/2;
    }
    return res;
}
ll power(ll a,ll b,ll p)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1)
            res=(res*a)%p;
        a=(a*a)%p;
        b=b/2;
    }
    return res;
}
ll logg2(ll n)
{
    ll i;
    string s=bs(64,n);
    f(i,64)
        if(s[i]=='1')
            break;
    return 63-i;
}
ll todec(ll n,string s)
{
    ll i,k=0;
    f(i,n)
        if(s[i]=='1')
            k+=1LL<<(n-i-1);
    return k;
}
bool isprime(ll n)
{
    ll i;
    if(n==1)
        return false;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
sl factors(ll n)
{
    ll i;sl v;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.insert(i);
            v.insert(n/i);
        }
    }
    return v;
}
vl fact(1000001);
void fct()
{
    fact[0]=1;ll i;
    fr(i,1,1000000)
        fact[i]=(i*fact[i-1])%mod;
}
ll nck(ll n,ll k)
{
    if(n>=k)
        return (((fact[n]*(inverse(fact[k],mod)))%mod)*inverse(fact[n-k],mod))%mod;
    else
        return 0;
}
ll crt(vl md,vl nm)
{
    ll i,p=1,q,ans=0,n=md.size();
    for(ll g:nm)
        p*=g;
    f(i,n)
    {
        q=p/nm[i];
        ans+=(md[i]*inverse(q,nm[i])*q)%p;
    }
    return ans%p;
}
vl prf(1000001);
vl mob(1000001,1);
void sieve()
{
    ll i,j;
    for(i=2;i<=1000000;i++)
    {
        if(prf[i]==0)
        {
            for(j=i;j<=1000000;j+=i)
            {
                prf[j]=i;
                mob[j]=-mob[j];
                if(j%(i*i)==0)
                    mob[j]=0;
            }
        }
    }
}
bool vps(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return (a.second<b.second);
}
bool fts(const pair<string,string> &a,const pair<string,string> &b)
{
    if(a.first!=b.first)
        return (a.first<b.first);
    return (a.second>b.second);
}
ll xorf(ll a,ll b,ll k)
{
    ll i,ans=0,x,y;
    ll up=(logg2(200000)+1)/logg2(k)+1;
    fn(i,up)
    {
        x=a/power(k,i);
        a%=power(k,i);
        y=b/power(k,i);
        b%=power(k,i);
        ans+=((x+y)%k)*power(k,i);
    }
    return ans;
}
ll xori(ll a,ll b,ll k)
{
    ll i,ans=0,x,y;
    ll up=(logg2(200000)+1)/logg2(k)+1;
    fn(i,up)
    {
        x=a/power(k,i);
        a%=power(k,i);
        y=b/power(k,i);
        b%=power(k,i);
        ans+=((x-y+k)%k)*power(k,i);
    }
    return ans;
}
void solve(ll tc)
{
    ll n,m,k=0,j=0,i=0,x=0,y=0,z=0,p=0,q=0,l=0,sum=0,temp=1,flag=0,a=0,b=0,d=1,r=0,mn=inf,mx=-inf,_,__,mid;
    string s1,s2,s3,s;char c;
    cin>>n>>k;
    vl v(n);v[0]=0;
    fr(i,1,n-1)
    {
        if(i%2)
            v[i]=xori(x,i,k);
        else
            v[i]=xorf(x,i,k);
        x=xori(v[i],x,k);
    }
    f(i,n)
    {
        cout<<v[i]<<endl;
        cin>>x;
        if(x==1)
            return;
    }
}

//Write the step statement in while loops
//Replace vector with multiset not set
//Use variables correctly
//Check for testcases : cin>>t;
//Always check for boundary conditions (They are deadly)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve(t);
        cout<<endl;
    }
    return 0;
}