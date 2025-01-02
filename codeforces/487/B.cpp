#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set; 
#define sz(a) a.size()
using namespace std;
#define mod 998244353
#define int long long 
#define endl "\n"
#define ll long long 
#define ff  first
#define ss second
#define f(i,a,b) for(int i(a);i<b;i++)
#define rep(i,n) for(int i(0);i<n;i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define pres(x) cout<<fixed; cout<<setprecision(x);
#define watch(x) cout<<(#x)<<" is "<<x<<"\n";
#define out(x) cout<<x<<"\n";
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define inf 1e18
#define pdd pair<double, double>
#define ld long double
#define ar array
int gcd(int a,int b){return (b==0) ? a:gcd(b,a%b);} 
int power(int a,int b){
    int ans=1;
    while(b!=0){
        if(b&1){ans=(ans*a)%mod;b--;}
        a=(a*a)%mod;b/=2;
    }
    return ans%mod;
}
  
int invmod(int n){
    int ans=1;
    ans=power(n,mod-2);
    return ans;
    
}
 
int min(int a,int b){return (a<b) ? a:b;}
int max(int a,int b){return (a>b) ? a:b;}
 
// int fact[200005];
// int infact[200005];
int n,s,l;
int a[200005],d[200005];
 
multiset<int> st,val;
 
inline int getmaxdif(){
    auto it=val.end();
    it--;
    return (*it-*val.begin());
}
void solve(){
    cin>>n>>s>>l;
    for (int i=1;i<=n;i++) cin>>a[i];
    int j=-1;
    for (int i=1;i<=n;i++) {
        val.insert(a[i]);
        if (i-l>=0) st.insert(d[i-l]);
 
        while (j+1<=i-l && getmaxdif()>s) {
            j++;
            st.erase(st.find(d[j]));
            val.erase(val.find(a[j+1])); 
        }
        if (j>=i-l) d[i]=999999;
            else d[i]=*st.begin()+1;
    }
    if (d[n]>=899999) d[n]=-1;
    cout<<d[n]<<endl;

}


signed main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ; 
    freopen("output.txt","w",stdout);
    #endif
 
    // fact[0]=1;
    // infact[0]=invmod(fact[0]);
    // f(i,1,200005){
    //  fact[i]=fact[i-1]*i;fact[i]%=mod;
    //  infact[i]=invmod(fact[i]);
    // }
 
    int t=1;
    // cin>>t;
    while(t--){
 
    solve();
    }
  
}