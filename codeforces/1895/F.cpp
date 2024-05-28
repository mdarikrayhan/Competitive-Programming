/*
    in the name of god
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")

//using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef long long ll ;

//#define ord_set(T)    tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
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

const ll N = 43,SQ=320,LOG=31, MD = 1e9 + 7;
const ll inf = 2e9 , riz = -2e9;
int n , k, x;
int dp[LOG<<1][N][N];

ll big_pow(ll n ,ll x,ll md = MD){
    ll ans = 1;
    while(x){
        if(x&1) ans = (ans*n)%md;
        n = (n*n)%md;
        x = (x>>1);
    }
    return ans;
}
vector<int> st;
void f(int x){
    st.pb(x);
    if(x<=2) return;
    int a = (x-1)/2,b=x/2;
    if(a==b) f(a+1);
    else{
        f(a+1);
        f(b+1);
    }
}
int32_t main() {
    migmig
    int t;
    cin >> t;
    while(t--){
        cin >> n >> x >> k;
        ll ans = md((x+k)*big_pow(2*k+1,n-1));
        st.clear();
        f(n);
        sort(all(st));
        st.resize(unique(all(st)) - st.begin());
        loop(i,0,len(st)){
            loop(j,0,x){
                loop(p,0,x) dp[i][j][p] = 0;
            }
        }
        //cout << len(st) << endl;
        loop(i,0,len(st)){
            int p = st[i];
            if(p <= 2){
                loop(a,0,x){
                    loop(b,0,x) {
                        if(p==1 and a==b) dp[i][a][b]++;
                        else if(p==2 and abs(a-b) <= k) dp[i][a][b]++;
                    }
                }
                continue;
            }
            int r = lower_bound(all(st),(p-1)/2 + 1) - st.begin();
            int r2 = lower_bound(all(st),p/2 + 1) - st.begin();
            loop(a,0,x){
                loop(b,0,x){
                    loop(j,0,x){
                        dp[i][a][b] = md(dp[i][a][b] + md(1LL*dp[r][a][j]*dp[r2][j][b]));
                    }
                }
            }
        }

        loop(j,0,x){
            loop(i,0,x){
                ans = md(ans - dp[len(st)-1][i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}