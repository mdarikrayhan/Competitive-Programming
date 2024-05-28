#include <bits/stdc++.h>
using namespace std;

//i/o optimizations
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//data types & structures
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
#define pq priority_queue

//graph structures
typedef vector<pair<ll,ll>> graph;
typedef vector<ll> nw_graph;
typedef vector<ll> tree;
typedef pair<ll,pair<ll,ll>> edge;
typedef pq<pair<ll,ll>> dij_q;

//constant values
const ll N=2e5+1;
const ll N3=1e3+1;
const ll N4=1e4+1;
const ll N5=1e5+1;
const ll N6=1e6+1;
const ll N8=1e8+1;
const ll INF=1e18+1;
const ll LOGN=18;
const ll MOD=1e9+7;
const ll MOD2=998244353;

//operations
#define MID ((l+r)/2)
#define RANGE (r-l+1)
#define CEIL(a,b) (((a)/(b))+(((a)%(b))?1:0))

//output
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define ANS(ans) if(ans) YES; else NO

//math
ll mpow(ll b, ll p, ll m=MOD){ll ans=1; while(p>0){ if(p%2==1)ans*=b; b=(b*b)%MOD; p/=2; ans%=MOD;} return ans;}
#define DIST(a, b) (long double)sqrtl((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second))

int main(){
    fastio;

    ll tc;
    cin>>tc;
    while(tc--){
        ll n, q;
        cin>>n>>q;
        
        for(ll i=1; i<n; i++){
            cout<<i<<" "<<i+1<<endl;
        }
        
        ll x=n-1;
        while(q--){
            ll d;
            cin>>d;
            if(d==x) cout<<-1<<" "<<-1<<" "<<-1<<endl;
            else cout<<n<<" "<<x<<" "<<d<<endl;
            x=d;
        }
    }

    
    return 0;
}