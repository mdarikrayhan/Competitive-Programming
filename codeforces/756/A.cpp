// o&o
// ---

//
#include <bits/stdc++.h>
#define all(x)       (x).begin(),(x).end()
#define forr(i,a)    for(auto&i:a)
#define Sort(x)      sort(all((x)))
#define Binary(a,b)  binary_search(all((a)),b)
#define Reverse(a)   reverse(all((a)))
#define pb           push_back
#define sep          " "
#define s            second
#define f            first
#define endl         '\n'
#define FileIO       freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FastIO       ios::sync_with_stdio(false);cin.tie(nullptr);
#define in           insert
#define for0(n)      for(int i=0;i<n;i++)
#define for1(n)      for(int i=1;i<=n;i++)
#define foor(i,n)    for(int i=0;i<n;i++)
#define Mp		     make_pair
#define set_preci(x) cout << fixed << setprecision(x);
#define Min(v)       *min_element(all(v))
#define Max(v)       *max_element(all(v))
#define Sum(v)       accumulate(all(v),0ll)
#define lb           lower_bound
#define ub           upper_bound
using namespace std;
typedef long long    ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<ll,ll>   pll;
const int Mod=1e9+7;
const ll Inf=8e18;
ll pw(ll a,ll b){return(!b?1:(b&1?a*pw(a*a,b/2):pw(a*a,b/2)));};
const int Max=2e5+10;
bool vis[Max];
int ans=0,cnt=0,p[Max],n;
void dfs(int v){
    if(vis[v])return ;
    vis[v]=1;
    dfs(p[v]);
}
void Answer(){
    cin>>n;
    vector<int>b(n+1);
    for1(n)cin>>p[i];
    for1(n)cin>>b[i];
    for1(n){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    (cnt==1?ans=0:ans=cnt);
    cout<<((Sum(b)&1)==0?ans+1:ans)<<endl;
}
int main() {
    FastIO
    int Test;
    //cin>>Test;
    Test=1;
    while(Test--)Answer();
    return 0;
}
