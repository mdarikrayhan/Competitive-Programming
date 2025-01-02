/*
    in the name of god
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#define int long long 
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef long long ll ;

#define ord_set(T)    tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
#define min_heap(X)   priority_queue<X,vector<X>,greater<X>>
#define max_heap(X)   priority_queue<X>
#define File          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define loop(i,f,d)   for(int i = f;i<d;i++)
#define loop2(j,f,d)  for(int j = f;j>=d;j--)
#define len(V)        (int)(V.size())
#define sep           ' '
#define endl          '\n'
#define pb(x)         push_back(x)
#define debug(x)      cerr  << "bug " << x << endl;
#define migmig        cin.tie(NULL);ios_base::sync_with_stdio(false);
#define fi            first
#define sec           second
#define popcount(x)   __builtin_popcount(x)
#define md(x)         (((x%MD)+MD)%MD)
#define all(V)        V.begin(),V.end()
#define Mp(a,b)       make_pair(a,b)
#define gaws(a,b)     (((b-a+1LL)*(a+b))/2LL)
#define vvi           vector<vector<int>>
#define setprec(x)    fixed << setprecision(x)
#define lid           u<<1
#define rid           (u<<1)|1
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll N = 1e5 + 10,SQ=323,LOG=31, MD = 1e9 + 7;
const ll inf = 2e9 , riz = -2e9;
ll fact[N];
ll inv[N];
ll i25[N],ii25[N],i26[N];
ll i2[N];
int dp[N];
int ans[N];
vector<pii> quer[N];
ll big_pow(ll n ,ll x,ll md = MD){
    ll ans = 1;
    while(x){
        if(x&1) ans = (1LL*ans*n)%md;
        n = (1LL*n*n)%md;
        x = (x>>1);
    }
    return ans;
}
ll divide(ll p , ll q){
    return (1LL*(p%MD) * big_pow(q,MD-2,MD))%MD;
}
void preprocces(){
    fact[0]=1LL;
    loop(i,1,N){
        fact[i] = (fact[i-1]*(ll)(i))%MD;
    }
    inv[N-1] = divide(1LL,fact[N-1]);
    loop2(i,N-2,0){
        inv[i] = (inv[i+1]*(ll)(i+1))%MD;
    }
    i25[0] = 1;
    i26[0] = 1;
    i2[0] = 1;
    loop(i,1,N){
        i25[i] = md(1LL*i25[i-1] * 25);
        i26[i] = md(1LL*i26[i-1] * 26);
        i2[i] = divide(i25[i],i26[i]);
    }
    loop(i,0,N) ii25[i] = divide(1,i25[i]);
}
ll cnr(ll r ,ll n,ll md = MD){
    if(r > n || r < 0 ) return 0LL;
    return (((fact[n]*inv[r])%md)*inv[n-r])%md;
}

string s;

int32_t main() {
    migmig
    preprocces();
    int m;
    set<int> st;
    cin >> m ;
    cin >> s;
    int n = len(s);
    s.clear();
    st.insert(n);
    int lst = n;
    fill(ans,ans+m,-1);
    loop(i,0,m){
        int t ;
        cin >> t;
        if(t==1){
            cin >> s;
            int n = len(s);
            lst = n;
            st.insert(n);
        }
        else{
            int n ;
            cin >> n;
            quer[lst].pb(Mp(n,i));
        }
    }
    for(auto h : st){
        dp[h] = i2[h];
        loop(j,h+1,N) dp[j] = md(dp[j-1] + md(1LL*cnr(h-1,j-1)*i2[j]));
        loop(j,0,h) dp[j] = 0;
        for(auto x : quer[h]){
            ll t1 = dp[x.fi];
            t1 = md(1LL*t1*i26[x.fi]);
            t1 = md(1LL*t1*ii25[h]);
            ans[x.sec] = t1;
        }
    }
    loop(i,0,m){
        if(ans[i] != -1) cout << ans[i] << endl;
    }
    return 0;
}