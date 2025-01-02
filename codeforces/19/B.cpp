#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pl pair<ll,ll>
#define vl vector<ll>
#define vpl vector<pl>
#define mll map<ll,ll>
#define uml unordered_map<ll,ll>
#define mod 1000000007
#define pb push_back
#define mpr make_pair
#define pp1(a) \
    ll a;      \
    cin >> a;
#define pp2(a, b) \
    ll a, b;       \
    cin >> a >> b
#define pp3(a, b, c) \
    ll a, b, c;       \
    cin >> a >> b >> c
#define pp4(a, b, c, d) \
    ll a, b, c, d;       \
    cin >> a >> b >> c >> d
#define outv(v)           \
    for (auto i : v)      \
        cout << i << " "; \
    cout << endl;
#define outp(v)                     \
    for (auto i : v)                 \
        cout << i.fi << " " << i.se; \
    cout << endl;
#define ld long long double
#define AMATERASU return 0;
#define out(x) cout << x << endl;
#define all(v) v.begin(), v.end()
#define na cout << "NO" << endl;
#define ya cout << "YES" << endl;
#define qll queue<long long>
#define pqll priority_queue<long long>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rfr(i,a,b) for(ll i=a;i>=b;i--)
#define vsort(V) sort(V.begin(),V.end())
#define rsort(V) sort(V.begin(),V.end(),greater<ll>())
#define MAX(V) *max_element(V.begin(),V.end())
#define MIN(V) *min_element(V.begin(),V.end())
#define rbd int test; cin >> test; while(test--)
#define ReZero {ios_base ::sync_with_stdio(false); \
 cin.tie(NULL); cout.tie(NULL);}
#define vin(vec,n,type) for(ll i=0;i<n;i++) \
{type p;cin >> p;vec.push_back(p);}
#define ain(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
#define every(m) for(auto p:m)
#define fine(x,V) find(V.begin(),V.end(),x);
const ll INF=1e18;
ll n;
    vpl v;
    // map<pair<ll,ll>,ll> dp;
    ll dp[2001][4001];
ll f(ll i, ll t){
    if(i==n){
        if(t>=2000){
            return 0;
        }
        else{
            return INF;
        }
    }
    if(dp[i][t]!=-1){
        return dp[i][t];
    }
    ll ans=INF;
    if(t>=1)
    ans=min(ans,f(i+1,t-1));
    ans=min(ans,f(i+1,min(4000LL,t+v[i].first))+v[i].second);
    return dp[i][t]=ans;
    // return ans;
}
signed main(){
ReZero;
    cin>>n;
    fr(i,0,n){
        ll o,p;
        cin>>o>>p;
        v.pb({o,p});
    }
    fr(i,0,2001){
        fr(j,0,4001){
            dp[i][j]=-1;
        }
    }
    ll ans=f(0,2000);
    cout<<ans<<endl;
    
AMATERASU
}
 
//NOTE: 
// 1. Don't be lazy...!!
// 2. Ho Jaega, dhang se soch...!!
// 3. Greed is the best sin ;)
// 4. approach sudhar laude :/
// 5. El Psy Congree :)