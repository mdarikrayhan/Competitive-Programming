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
ll k;

ll solve(ll ind, bool check, ll last, string &s, vector<vector<pair<ll,ll> > > &dp){
    if(ind == s.length()) return 0;
    //if(!check && last!=-1 && dp[ind][last].fi!=INT_MAX) return dp[ind][last].fi;
    //if(check && last!=-1 && dp[ind][last].sc!=INT_MAX) return dp[ind][last].sc;
    ll flip = INT_MAX;
    ll notflip = INT_MAX;
    if(last==-1){
        if(s[ind]=='0'){
            flip = 1 + solve(ind+1,false,ind,s,dp);
            notflip = solve(ind+1,false,last,s,dp);
        }
        else{
            flip = 1 + solve(ind+1,false,last,s,dp);
            notflip = solve(ind+1,false,ind,s,dp);
        }
    }
    else{
        if(s[ind]=='0'){
            if(!check){
                if(ind==last+k){
                    flip = 1 + solve(ind+1,false,ind,s,dp);
                    notflip = solve(ind+1,true,last,s,dp);
                }
                else
                notflip = solve(ind+1,false,last,s,dp);
            }
            else{
                notflip = solve(ind+1,check,last,s,dp);
            }
        }
        else{
            if(!check){
                if(ind!=last+k)
                flip = 1 + solve(ind+1,false,last,s,dp);
                else{
                    notflip = solve(ind+1,false,ind,s,dp);
                    flip = 1+solve(ind+1,true,last,s,dp);
                } 
            }
            else{
                flip = 1+solve(ind+1,check,last,s,dp);
            }
        }
    }
    //if(!check && last!=-1)
        return min(flip,notflip);
    //else if(check && last!=-1)
        //return dp[ind][last].sc = min(dp[ind][last].sc,min(flip,notflip));
}
int main(){
    NeedForSpeed;
    ll t;
    //t = 1;
    cin>>t;
    while(t--){
        ll n,k,z;
        cin>>n>>k>>z;
        vector<ll> v;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            v.pb(x);
        }
        vector<ll> maxi(n,1);
        for(int i=1;i<n;i++){
            if(v[i]+v[i-1]>v[maxi[i-1]]+v[maxi[i-1]-1]){
                maxi[i] = i;
            }
            else if(v[i]+v[i-1]==v[maxi[i-1]]+v[maxi[i-1]-1]){
                if(v[i-1]>v[maxi[i-1]-1]){
                    maxi[i] = i;
                }
                else maxi[i] = maxi[i-1];
            }
            else maxi[i] = maxi[i-1];
        }
        ll ans = 0;
        vector<ll> pref(n,0);
        pref[0] = v[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+v[i];
        }
        for(int i=1;i<=k;i++){
            ll rem = k-i;
            if(rem%2==0 && rem/2<=z){
                ans = max(ans,pref[i]+rem/2*(v[maxi[i]]+v[maxi[i]-1]));
            }
            else{
                if(maxi[i]==i && rem/2+1<=z){
                    ans = max(ans,pref[i]+v[maxi[i]-1]+rem/2*(v[maxi[i]]+v[maxi[i]-1]));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}