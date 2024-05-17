#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int           long long int
#define ll             long long
#define ld             long double
#define ff              first
#define ss              second
#define read(n)         int n; cin>>n
#define pb              push_back
// #define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define umap             unordered_map
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define all(v)          v.begin(),v.end()
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define fast()          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i,a,n)      for(int i=a;i<n;++i)

int square (long long x) {
  long long ans = 0;
  for (ll k = 1LL << 30; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}
int gcd(int a,int b)
 {
    if(b==0)
    return a;           
    else
    return gcd(b,a%b)   ;      
    
 }     

int be(int a, int b)
 {
    int ans = 1;
    while(b>0)
    {
        if(b&1)
        ans=ans*a;
        a=a*a;
        b/=2;
    }
    return ans;
 }            

/*----------------------------------------------------I CAN DO IT--------------------------------------------------------*/
/*---------------------------------------------Copyright @Ritwik Ranjan Pathak-------------------------------------------*/
void solve()
{
   int n,len,k;
   cin>>n>>len>>k;
   vector<int>a(n);
   rep(i,0,n) cin>>a[i];
   if(k>=n)
   {
    cout<<n<<endl;
    return;
   }
   sort(a.begin(),a.end());
   vector<int>gap;
   rep(i,1,n)
   gap.pb(a[i]-a[i-1]-1);
   sort(gap.begin(),gap.end(),greater<int>());
   int ans=a[n-1]-a[0]+1;
   for(int i=0;i<k-1;i++)
   ans-=gap[i];
   cout<<ans<<endl;
   return;
}
int32_t main()
{
    int t=1;
    while(t--)
    {
      solve();
    }
}