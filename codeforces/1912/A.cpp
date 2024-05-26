#include<bits/stdc++.h>
using namespace std;

typedef long long int            ll;
typedef unsigned long long int   ull;
typedef vector<pair<ll,ll>>      vpll;
typedef vector<ll>               vll;
typedef map<ll,ll>               mll;
typedef pair<ll,ll>              pll;
 
#define loop(i,k,n)              for(ll i=k;i<n;i++)
#define pb                       push_back
#define ft                       first 
#define sc                       second
#define yes                      cout<<"Yes"<<endl
#define no                       cout<<"No"<<endl
#define Yes                      cout<<"YES"<<endl
#define No                       cout<<"NO"<<endl
#define Alice                    cout<<"Alice"<<endl
#define Bob                      cout<<"Bob"<<endl
#define newl                     cout<<"\n"
#define clean                    fflush(stdout)
#define FLOOR(x,y)               (ll(floor(double(x)/y)))
#define CEIL(x,y)                (ll(ceil(double(x)/y)))
#define max3(a,b,c)              max(a,max(b,c))
#define min3(a,b,c)              min(a,min(b,c))
#define all(v)                   v.begin(),v.end()
#define rall(v)                  v.rbegin(),v.rend()
#define Max(v)                   *max_element(v.begin(), v.end())
#define Min(v)                   *min_element(v.begin(), v.end())
#define SORT(a)                  sort(a,a+(sizeof(a)/sizeof(a[0])))
#define inparr(arr,n)            ll arr[n]; loop(i,0,n) cin >> arr[i]
#define inpvec(v,n)              vll v(n); for(auto &i:v) cin >> i
#define prec(ans,n)              cout<< fixed << setprecision(n) << ans << endl
const ll M=998244353;
const ll N=1e6+5;
const ll INF=1e15;


int main()
{
    ll x,k;
    cin>>x>>k;
    vll v[k];
    set<pair<ll,ll>> s;
    loop(i,0,k){
        ll n;
        cin>>n;
        loop(j,0,n){
            ll elem;
            cin>>elem;
            v[i].pb(elem);
        }
    }
    priority_queue<pair<ll,ll>> pq;
    loop(i,0,k){
        ll prev=0,mn=0,sum=0;
        loop(j,0,v[i].size()){
            sum+=v[i][j];
            mn=min(mn,sum);
            if(sum>prev){
                pq.push({mn,sum-prev});
                prev=sum;
            }
        }
    }
    ll ans=x;
    while(!pq.empty()){
        if(pq.top().ft+ans>=0){ans+=pq.top().sc;}
        pq.pop();
    }
    cout<<ans<<endl;
}