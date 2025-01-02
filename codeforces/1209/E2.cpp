#include <bits/stdc++.h>
 
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
#define F first
#define S second 
#define all(a) a.begin(),a.end()
#define pii pair <int,int>
#define PII pair<pii , pii>
#define ld long double
#define sz(v) (int)v.size()
#define rep(i , a , b) for(int i=a;i <= b;i++)
#define per(i , a , b) for(int i=a;i >= b;i--)
using namespace std ;
const int maxn = 5000 + 10  ,  N = 1e5 +1 , lg = 20 , maxq = 202   , inf = 1e9  , maxk = 2022  , mod =998244353;
int a[20][maxn] , n , m , dp[maxn] , sm[maxn] , mx[maxn] , mark[maxn]; 

int f(int x){
    int a = 31-__builtin_clz(x) ;
    return x*(1<<(n-1-a));
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t ;
    while(t--){
        cin >> n >> m ;
        vector <pii> vec ;
        rep(i , 1, n){
            rep(j , 1, m){
                cin >> a[i][j] ;
                vec.pb({a[i][j] , j});
            }
        }
        sort(all(vec));
        int ted = n ;
        vector<int> b; 
        rep(i , 1,m)mark[i] =0 ;
        per(i , sz(vec)-1 , 0){
            if(mark[vec[i].S] == 0){
                ted--;
                mark[vec[i].S] = 1; 
                b.pb(vec[i].S);
                if(ted==0)break ;
            }
        }
        rep(i ,0 , (1<<n)-1)dp[i] =0 ;
        rep(i , 1 ,m){
            if(mark[i] == 0)continue;
            rep(j , 0 , (1<<n)-1){
                mx[j] = 0 ;
            }
            rep(j , 1, (1<<n)-1){
                int y = __builtin_ctz(j);
                sm[j] = sm[j^(1<<y)] + a[y+1][i] ;
                int u = j;
                rep(k ,0  ,n){
                    mx[u] = max(mx[u] , sm[j]);
                    u = (u/2) + (u%2==1) * ((1<<(n-1))); 
                }
            }
            per(j , (1<<n)-1 , 0){
                for(int x = j ;x ; x = (x-1)&j){
                    dp[j] = max(dp[j] , mx[f(x)] +dp[x^j]);
                }
            }
        }    
        cout << dp[(1<<n)-1] << "\n";  
    }
}
/*

*/