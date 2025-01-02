#include <bits/stdc++.h>
using namespace std;

//i/o optimizations
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//data types & structures
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
#define pq priority_queue

//graph structures
typedef vector<pair<ll,ll>> graph;
typedef vector<ll> nw_graph;
typedef vector<ll> tree;
typedef pq<pair<ll,ll>> dij_q;

//constant values
const ll N=2e5+1;
const ll N3=1e3+1;
const ll N4=2e4+1;
const ll N5=1e5+1;
const ll N6=1e6+1;
const ll N8=1e8+1;
const ll INF=1e9+1;
const ll LOGN=18;
const ll MOD=1e9+7;

//operations
#define MID ((l+r)/2)
#define RANGE (r-l+1)

//output
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define ANS(ans) if(ans) YES; else NO

//math
ll mpow(ll b, ll p, ll m=MOD){ll ans=1; while(p>0){ if(p%2==1)ans*=b; b=(b*b)%MOD; p/=2; ans%=MOD;} return ans;}

int main(){
    fastio;

    ll n, m;
    cin>>n>>m;
    string s[n];
    for(ll i=0; i<n; i++){
        cin>>s[i];
    }
    
    set<ll> x;
    for(ll i=0; i<n; i++){
        ll y=0;
        for(ll j=0; j<m; j++){
            if(s[i][j]=='#') y|=(1ll<<j);
        }
        x.insert(y);
    }
    
    //cout<<1<<endl;
    
    ll z=0;
    bool ans=true;
    while(!x.empty()){
        if((*x.begin()&z)!=0){
            ans=false;
            break;
        }
        
        z|=*x.begin();
        x.erase(x.begin());
    }
    
    ANS(ans);

    return 0;
}
