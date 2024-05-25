#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define ve vector
#define vll ve<ll>
#define vb ve<bool>
#define vvb ve<vb>
#define vvi ve<vi>
#define vvl ve<vll>
#define vpi vector<pii>
#define vpl ve<pll>
#define fcin(n,arr) for(int i=0;i<n;i++){cin>>arr[i];}
#define f(i,n) for (int i=0;i<n;i++)
#define fi(i,a,n) for (int i=a;i<n;i++)
#define fe(i,n) for (int i=0;i<=n;i++)
#define fie(i,a,n) for (int i=a;i<=n;i++)
#define ll long long
#define llu long long unsigned
#define ev(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define p(a) cout<<a<<endl;
#define pqg(a) priority_queue<a,ve<a>,greater<a> >
#define pq(a) priority_queue<a,ve<a> >
#define cont continue

void printi(vector<int> &a)
{
    f(i, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void printl(vll &a)
{
    f(i, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void printvi(vvi &a)
{
    f(i, a.size())
    {
        printi(a[i]);
    }
}
void printvl(vvl &a)
{
    f(i, a.size())
    {
        printl(a[i]);
    }
}
ll tour(vvi& adj,vll& allow,int curr,ll& kill){
    int n=adj[curr].size();
    if(!n){
        if(allow[curr]>=kill){
            return -1ll;
        }
        return kill-1ll-allow[curr];
    }
    llu cnt=0ll;
    f(i,n){
        ll a=tour(adj,allow,adj[curr][i],kill);
        if(a==-1ll){
            return -1ll;
        }
        cnt+=a;
    }
    if(cnt<allow[curr]){
        return -1ll;
    }
    return cnt-allow[curr];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,t,m;
    // cin>>t;
    t=1;
    ll mym=998244353;
    while(t--){
        int n;     
        cin>>n;
        vpi num(n);
        f(i,n){
            cin>>num[i].first;
            num[i].second=i+1;
        }
        vll power(n+1,1);
        fie(i,1,n){
            power[i]=(power[i-1]<<1)%mym;
        }
        vvi div(n+1);
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                div[j].pb(i);
            }
        }
        sort(ev(num));
        vb taken(n,false);
        int tot=n;
        ll ans=0;
        for(int i=n-1;i>-1;i--){
            int ind=num[i].second;
            // cout<<ind<<" tot "<<tot<<" ";
            if(!taken[ind-1]){
                taken[ind-1]=true;
                int m=div[ind].size(),cnt=1;
                f(j,m){
                    if(!taken[div[ind][j]-1]){
                        taken[div[ind][j]-1]=true;
                        cnt++;
                    }
                }
                tot-=cnt;
                ans+=num[i].first*((((power[cnt]-1+mym)%mym)*power[tot])%mym); 
                ans%=mym;
            }
        }
        cout<<ans<<endl;
    }

    
 
    return 0;
}