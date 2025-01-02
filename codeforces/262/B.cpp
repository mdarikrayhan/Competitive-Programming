// بسم الله الرحمن الرحيم

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Hesham ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ordered_set tree<ll,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update>
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define fllm(i,a,b) for(long long i=a;i>=b;i--)
#define f(b,a) cout << fixed << setprecision(b) << a << endl;
#define rall(x) x.rbegin(),x.rend()
#define MOD 1000000007
#define pi 3.14159265358979323846
#define all(x) x.begin(),x.end()
#define ull unsigned long long
#define ld long double
#define ll long long
#define sz(s) s.size()
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define F first
#define S second
#define nl '\n'

using namespace std;
using namespace __gnu_pbds;
const long long maxn=1e5;
vector<bool>sieve(maxn+1,1);
vector<ll>spf(maxn);

ll dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
ll dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isPrime(ll n)
{
    if(n==1||(n%2==0&&n!=2)) return false;
    for(ll j=2;j*j<=n;j++)
    {
        if(n%j==0)
        {
            return false;
        }
    }
    return true;
}

void sev()
{
    for(ll i=2;i*i<=maxn;i++)
    {
        if(sieve[i])
        {
            for(ll j=i*i;j<=maxn;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
    sieve[1]=0,sieve[0]=0;
}

void smallestpf()
{
    spf[1]=1;
    fll(i,2,maxn) spf[i]=i;
    for(ll i=4;i<maxn;i+=2) spf[i]=2;
    for(ll i=3;i*i<maxn;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=i*i;j<maxn;j+=i)
                if(spf[j]==j) spf[j]=i;
        }
    }
}

vector<ll>getf(ll n)
{
    vector<ll>ret;
    while(n!=1)
    {
        ret.push_back(spf[n]);
        n=n/spf[n];
    }
    return ret;
}

bool comp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    ll a=p1.S-p1.F,b=p2.S-p2.F;
    if(a==b) return p1.F<p2.F;
    return a>b;
}

ll fastpower(ll x,ll n,ll m)
{
    ll res=1;
    while(n>0)
    {
        if(n%2!=0) res=(res%m*x%m)%m,n--;
        else x=(x%m*x%m)%m,n/=2;
    }
    return res;
}

vector<ll>presum(vector<ll> &v)
{
    vector<ll>p(v.size());
    fll(i,0,v.size())
    {
        if(i==0) p[i]=v[i];
        else p[i]=v[i]+p[i-1];
    }
    return p;
}

vector<ll>primefactor(ll n)
{
    ll cn=0; vector<ll>v;
    while(n%2==0)
    {
        v.push_back(2); n/=2;
    }
    for(ll j=3;j*j<=n;j+=2)
    {
        while(n%j==0)
        {
            v.push_back(j);
            n/=j;
        }
    }
    if(n>2) v.push_back(n);

    return v;
}

ll nCr(ll n,ll r)
{
    ll sum=1;
    fll(i,1,r+1) sum=sum*(n-r+i)/i;
    return sum;
}

vector<ll>divisors(ll n)
{
    vector<ll>c;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            c.push_back(i);
            if(n/i!=i) c.push_back(n/i);
        }
    }
    return c;
}

ll lcm(ll a,ll b)
{
    ll k=(a*b)/__gcd(a,b);
    return k;
}

ll arteq(ll l,ll r,ll p)
{
    ll k=((r-l)/p)+1;
    ll h=k*(l*2+(k-1)*p); h/=2;
    return h;
}

ll binpow(ll a,ll b,ll p=MOD)
{
    ll res=1;
    while(b>0)
    {
        if(b&1) res*=a,res%=p;
        a*=a,a%=p;
        b>>=1;
    }
    return res;
}

void solve()
{
    ll n,h,k,a=-1,b=-1,c=-1,mn=INT_MAX,cn=0; cin >> n >> k; vector<ll>v(n);
    fll(i,0,n) cin >> v[i]; sort(all(v));
    fll(i,0,n)
    {
        if(k==0) break;
        if(mn>abs(v[i])) mn=min(mn,abs(v[i])),c=i;
        if(a==-1&&v[i]<0) a=i;
        if(v[i]<0) b=i;
        if(v[i]>=0)
        {
            h=i;
            break;
        }
        v[i]*=-1,k--;
    }
    if(k>0)
    {
        if(v[h]==0) while(k>0) v[h]*=-1,k--;
        else if(a>-1)
        {
            if(k&1) while(k>0) v[c]*=-1,k--;
        }
        else while(k>0) v[h]*=-1,k--;
    }
    fll(i,0,n) cn+=v[i];
    cout << cn;
}

int main()
{
    Hesham;
    // freopen("army.in","r",stdin);
    // freopen("mex.out","w",stdout);
    ll t=1;
    // cin >> t;
    while(t--) solve();

  return 0;
}
