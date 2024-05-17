//om namo venkateshvaraya namaha
//om namashivaya
//your rating doesn't define your skill! so just try howmuch ever you can


#include<bits/stdc++.h>
#include<math.h>
using namespace std;
 
#define fore(i,e)  for(ll i=0;i<e;i++)
#define forn(i,d,e) for(ll i=d;i<e;i++)
#define forc(i,e)   fore(i,n) cin>>a[i];
#define foro(i,e)   fore(i,n) cout<<a[i]<<" "
#define forr(i,e)  for(ll i=e-1;i>=0;i--)
#define forrn(i,d,e)  for(ll i=e-1;i>=d;i--)
#define test  int t;cin>>t; while(t--)
#define el endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define umap unordered_map
#define INF 2e18
#define no cout<<"NO"<<el
#define yes cout<<"YES"<<el
#define cn cout<<-1<<el
#define in() insert()
#define cs string s;cin>>s;
#define l() length()
#define all(x) (x).begin(), (x).end()
// #define lower_bound() l_b;
typedef pair<int,int>         pii;
typedef pair<ll,ll>           pll;
typedef vector<ll>            vl;
typedef vector<char>            vc;
typedef vector<pll>           vpl;
typedef vector<pii>           vpi;
typedef vector<int>           vi;
ll MOD=1000000007;
bool sortbysec(pll a,pll b)
{
    return (a.second < b.second);
}
bool sortbyfirst(pll a,pll b)
{   
    
    if(a.fi==b.fi){
        
        return (a.se>b.se);
    }
    return (a.fi < b.fi);
}
bool sortbyfir(pll a,pll b)
{   
    
    if(a.fi==b.fi){
        
        return (b.se);
    }
    return (a.fi < b.fi);
}

ll fact(ll n){
    if(n==1)return 1;
    return n*fact(n-1);
}
vl fac(2e5+10,0);

void solve(){
    ll n=0,m=0,k=0,p=0,mid=0,o=-1,ans=0,sum=0,mx=-1e18,mn=1e18,c1=0,c2=0;
    cin>>n>>m;set<ll>s;map<ll,ll>mp;
    ll a[n];fore(i,n){cin>>a[i];}
    mp[0]=0;mp[1]=0;
    forn(i,2,n){
        if(a[i-2]>=a[i-1]&&a[i-1]>=a[i])mp[i]=mp[i-1]+1;
        else mp[i]=max(mp[i-1],mp[i]);
    }
    fore(i,m){
        cin>>k>>p;
        if(p-k<2){cout<<p-k+1<<el;}
        else{
            p--;
            cout<<p-k+2+mp[k]-mp[p]<<el;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  cout<<fixed<<setprecision(0);
// test{
//   solve();
// }
solve();
  
}