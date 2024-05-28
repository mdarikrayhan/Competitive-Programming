#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC optimize("no-stack-protector")
// #define ll __int128
#define ll long long
// #define ll int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
// #define mod 998244353 
#define mp make_pair
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define ff first
#define ss second
#define rf(i,a,b) for(ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define pf printf
#define sz(a) (int)(a.size())
#define psf push_front
#define ppf pop_front
#define ppb pop_back
#define pb push_back
#define pq priority_queue
#define all(s) s.begin(),s.end()
#define sp(a) setprecision(a)
#define rz resize
#define ld long double
#define inf (ll)1e18
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define eb emplace_back
const double pi = acos(-1);

using namespace std;

ll n,k,ans,l,r,mid;
vector<ll> a;
vector<vector<ll> > t;

vector<vector<ll> > matmul(vector<vector<ll> > a, vector<vector<ll> > b)
{
    ll n=sz(a),m=sz(b[0]);
    vector<vector<ll> > ans(n,vector<ll> (m));
    f(i,0,n)
    {
        f(j,0,m)
        {
            f(k,0,sz(a[i]))
            {
                if(b[k][j]==0)
                    continue;
                ll mx=inf,pmx=(mx+b[k][j]-1)/b[k][j],prod;
                if(a[i][k]>pmx+2)
                    prod=mx;
                else
                    prod=a[i][k]*b[k][j];
                ans[i][j]+=prod,ans[i][j]=min(ans[i][j],mx);
            }
        }
    }
    return ans;
}

vector<vector<ll> > matpow(vector<vector<ll> > t, ll b)
{
    vector<vector<ll> > res=t;
    f(i,0,sz(res))
    {
        f(j,0,sz(res[i]))
            res[i][j]=(i==j);
    }

    while(b)
    {
        if(b&1)
            res=matmul(res,t);
        t=matmul(t,t),b>>=1;
    }

    return res;
}

bool check()
{
    vector<vector<ll> > b=matpow(t,mid);
    vector<vector<ll> > ta={a};
    vector<vector<ll> > res=matmul(ta,b);

    ll mx=0;
    f(j,0,sz(res[0]))
        mx=max(mx,res[0][j]);
    
    return (mx>=k);
}

void solve()
{
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check())
            r=mid-1,ans=mid;
        else
            l=mid+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("xortransform.in","r",stdin);
    // freopen("xortransform.out","w",stdout);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
    int z=1;
    // cin>>z;
    f(ilu,1,z+1)
    {
        // cout<<"Case #"<<ilu<<": ";
        ll mx=0;
        cin>>n>>k;

        f(i,0,n)
        {
            ll num;
            cin>>num;
            mx=max(mx,num);
            if(mx)
                a.pb(num);
        }

        n=sz(a),ans=0;
        if(n>=5)
        {
            while(mx<k)
            {
                f(i,1,n)
                {
                    a[i]+=a[i-1],mx=max(mx,a[i]);
                    if(mx>=k)
                        break;
                }
                ans++;
            }
        }
        else if(mx<k)
        {
            t.rz(n,vector<ll> (n));
            f(i,0,n)
            {
                f(j,0,n)
                    t[i][j]=(i<=j);
            }

            l=1,r=k;
            solve();
        }

        cout<<ans;
    }
}