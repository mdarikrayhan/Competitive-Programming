#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long int
// #define ull unsigned long long int
// #define double long double
// #define pl pair<ll, ll>
// #define pll pair<ll, pair<ll, ll>>
 #define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// #define ordered set tree <int, null_type, less, rb_tree_tag, tree_order_statistics_node_update>
// #define v(var, type) vector<type> var
// #define decv1(var, type, size, ini) var = vector<type> (size, ini)
// #define decv2(var, type, size) var = vector<type> (size)
// #define vsize(var, type, size) vector<type> var(size)
// #define vini(var, type, size, ini) vector<type> var(size, ini)
 #define all(v) v.begin(), v.end()
// #define in(vec) for(ll i=0;i<vec.size();i++) cin>>vec[i];
// #define out(vec) for(auto i:vec) cout<<i<<' ';
#define rev(vec) reverse(all(vec));
#define sorti(vec) sort(all(vec))
#define sortd(vec, type) sort(all(vec), greater<type> ())
 #define f(i,a,b,c) for(ll i=a;i<b;i+=c)
 #define pb push_back
#define fi first
#define sc second
const ll mod = 1e9 + 7;
const ll MOD2 = 998244353;
 #define in1(var) cin>>var
#define in2(var1, var2) cin>>var1>>var2
 #define in3(var1, var2, var3) cin>>var1>>var2>>var3
// #define out1(var) cout<<var
// #define out2(var1, var2) cout<<var1<<var2
// #define out3(var1, var2, var3) cout<<var1<<var2<<var3
ll maxdig(ll n){
    ll var = 0;
    while(n>0){
        var = max(var,n%10);
        n/=10;
    }
    return var;
}

// int numberofSeconds(int target, int network_nodes, vector<int> network_from, vector<int> network_to){
//     int n = network_nodes;

//     vector<vector<int> > adj(n);
//     for(int i=0;i<n;i++){
//         adj[network_from[i]].push_back(network_to[i]);
//     }
//     queue<pair<int,int> > ;
    
//     int ans = 0;
    
// }
ll solve(string &s, char a , char b){
    ll n = s.length();
    string var = "";
    var.pb(b);
    for(int i=0;i<n;i++){
        if(a!=b && (s[i]==a || s[i]==b) && s[i]!=var[var.length()-1]) var.pb(s[i]);
        else if(a==b && s[i]==a) var.pb(s[i]);
    }
    if(a==b) return var.length()-1;
    else{

        ll ans = var.length();
        if(var[0]!=a) ans--;
        if(var[var.length()-1]!=b) ans--;
        return ans;
    }
}
int main(){
    NeedForSpeed;
    ll t;
    //t = 1;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n = s.length();
        ll ans = 0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                ans = max(ans,solve(s,(char)((i+(int)'0')),(char)((j+(int)'0'))));
            }
        }
        cout<<n-ans<<endl;
    }
    return 0;
}