#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
 int MOD=1e9+7;
const int maxN = 1e5+1;
 
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ld long double
 
int binpow(int a,int b,int m){
    int ans=1;
    a=(a+m)%m;
    while(b){
        if(b&1)
            ans=(ans*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
// can give correct answer up to 1e18
bool isprime1(int n){
    if(n<2) return false;
    for(int i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e5;++it){
        int i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        if(binpow(i,n-1,n)!=1) return false;
    }
    return true;
}
bool isprime(int x) {
    if(x==1) return 0;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) 
            return false;
    }
    return true;
}
 
#define F first
#define S second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound

int n,m;
vi g[maxN];
int indeg[maxN];
int vis[maxN];


void solve(){

    cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        g[b].pb(a);
        indeg[a]++;
    }

    priority_queue<int>pq;
    int label[n+1],num=n;

    rep(i,1,n+1){
        if(indeg[i]==0)
            pq.push(i);
    }

    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        label[v] = num--;
        for(auto it:g[v]){
            indeg[it]--;
            if(indeg[it]==0)
                pq.push(it);
        }
    }

    rep(i,1,n+1) cout<<label[i]<<" ";
    cout<<endl;

}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}