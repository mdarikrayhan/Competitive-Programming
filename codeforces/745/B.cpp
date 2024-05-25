#include<bits/stdc++.h>
using namespace std;

#define fastkor ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

#define dvect vector<int>vect
#define pb(x) push_back(x)
#define vectinL(n) for(ll i=0;i<n;i++){ ll x; cin >> x; vect.push_back(x);}
#define vectin(n) for(int i=0;i<n;i++){ int x; cin >> x; vect.push_back(x);}
#define vectout(v) for(auto p: v) cout<<p<<" "; cout<<endl;
#define sortkor(x) sort(x.begin(),x.end())
#define reversekor(x) reverse(x.begin(),x.end())
#define all(vect) vect.begin(),vect.end()
#define mini_pos(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi_pos(a)    ( max_element((a).begin(), (a).end()) - (a).begin())

#define F first
#define S second
#define gcd(a,b) __gcd(a,b)
#define YES1 cout<<"Case "<<case++<<": YES\n"
#define NO1 cout<<"Case "<<case++<<": NO\n"
#define precision(n) fixed<<setprecision(n)
#define testcase ll t; cin >>t; while(t--)

#define yes cout<<"yes\n";
#define Yes cout<<"Yes\n";
#define YES cout<<"YES\n"

#define no cout<<"no\n";
#define No cout<<"No\n";
#define NO cout<<"NO\n"
#define vectd  vector<ll>vect(n)
const int N=1e7;
const int dx[4]= {-1,0,1,0};
const int dy[4]= {0,1,0,-1};
const int mod=1e9+7;
ll fact[N+10];
vector<bool>isprime;
vector<int>primegula;
map<int,int>mp;
template <typename T>
inline void operator>>(istream &istream, vector<T> &v)
{
    for (T &i : v)
    {
        cin >> i;
    }
}

void sieve(ll n)
{
    isprime.assign(n+1,true);
    isprime[0]=isprime[1]=false;
    for(ll i=2; i*i<=n; i++)
    {
        if(!isprime[i])
            continue;
        for(int j=i*i; j<=n; j+=i)
            isprime[j]=false;

    }
    for(ll i=2; i<=n; i++)
    {
        if(isprime[i])
            primegula.pb(i);
    }
}
vector<ll>primefact;
vector<ll> getpf(ll n)
{
    vector<ll>vv;
    set<int>st;
    for(auto v: primegula)
    {
        if(v*v>n)
            break;


        while(n%v==0)
        {
            n/=v;
            vv.pb(v);
        }
    }
    if(n!=1 )
        vv.pb(n);



    return vv;
}

int main()
{
    fastkor;
    ll n,m;
    cin >> n >> m;

    char a[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> a[i][j];
    }


    int l=501;
    int r=0;
    int u=0;
    int d=501;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
       for(int j=0;j<m;j++)
       {
           if(a[i][j]=='X')
           {
               l=min(l,i);
               r=max(r,i);

               u=max(u,j);
               d=min(d,j);
               cnt++;
           }
       }
    }

      //cout<<l <<" "<<r <<" "<<u <<" "<<d<<"\n";
    int bx=(r-l+1)*(u-d+1);
   // cout<<bx<<" ";
    if(bx==cnt)
        YES;
    else
        NO;
}
