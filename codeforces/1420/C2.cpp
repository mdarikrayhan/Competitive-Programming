#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pii> vii;
 #define INF 10000000000000000
#define inf 1000000000
// #define MOD  1000000007
// #define MOD 672804213107214
// #define MOD 998244353
#define PI 3.1415926535897932385
 #define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define all(ar) ar.begin(), ar.end()
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs
#define print(a) for(auto x : a) cout << x << " "; cout << endl
#define print1(a) for(auto x : a) cout << x.first << " " << x.second << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
 template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
   const char* comma = strchr (names + 1, ',');
   cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void solve()
{
  //vector<int> sieve(N+1,0); //fill constructor
    //primeSieve(sieve);
    ll n,q;
    cin>>n>>q;
    ll arr[n+2];
    arr[0]=-1;
    arr[n+1]=-1;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {cin>>arr[i];
   
    }
    for(int i=1;i<=n;i++)
    {
         if((arr[i]>arr[i-1]&&arr[i]>arr[i+1]))
    sum+=arr[i];
    else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])
    sum-=arr[i];
    }
    cout<<sum<<"\n";
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        for(int i=l-1;i<=l+1;i++)
        {
            if(i==0||i==n+1)
            continue;
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1]))
            sum-=arr[i];
            else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])
            sum+=arr[i];
        }
        for(int i=r-1;i<=r+1;i++)
        {
            if(i==0||i==n+1)
            continue;
            if(i==(l)||(i==l-1)||(i==l+1))
            continue;
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1]))
            sum-=arr[i];
            else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])
            sum+=arr[i];
        }
        swap(arr[l],arr[r]);
         for(int i=l-1;i<=l+1;i++)
        {
            if(i==0||i==n+1)
            continue;
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1]))
            sum+=arr[i];
            else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])
            sum-=arr[i];
        }
        for(int i=r-1;i<=r+1;i++)
        {
            if(i==0||i==n+1)
            continue;
            if(i==(l)||(i==l-1)||(i==l+1))
            continue;
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1]))
            sum+=arr[i];
            else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])
            sum-=arr[i];
        }
        cout<<sum<<"\n";
    }
    
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
int t;
cin>>t;
while(t--)
{
   solve();
}
}

