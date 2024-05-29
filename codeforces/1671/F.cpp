#include <bits/stdc++.h>
 
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
#define F first
#define S second 
#define all(a) a.begin(),a.end()
#define pii pair <int,int>
#define PII pair<pii , pii>
#define ld long double
#define int long long
#define sz(v) (int)v.size()
#define rep(i , a , b) for(int i=a;i <= b;i++)
#define per(i , a , b) for(int i=a;i >= b;i--)
using namespace std ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn =60  ,  N = 1e5 +1 , lg = 20 , maxq = 202   , inf = 1e9  , maxk = 2022  , mod =998244353;
int dp[maxn][maxn][maxn][maxn] ;
int dp2[maxn][maxn][maxn] ,sdp[maxn][maxn][maxn];
int dp3[maxn][maxn][maxn][maxn] ; 
int inv[maxn] ;
void add(int &a , int b){
    a += b ;
    if(a >= mod)a-=mod ;
}
void sub(int &a , int b){
    a-=b;
    a+=mod;
    if(a >= mod)a-=mod;
}
int po(int a, int b){
    if(b==0)return 1 ;
    int v =po(a,b/2);
    v= v*v % mod ;
    if(b&1) v= v*a % mod;
    return v ;
}

int c(int n ,int k){
    if(n < k || k < 0 )return 0 ;
    int ans = 1;
    per(i , k , 1){
        ans = (ans * n%mod *inv[i]%mod)%mod;
        n--;
    }
    return ans ;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    dp[1][1][0][0] =1 ;
    rep(i ,1 ,23){
    rep(j ,1 , i){
    rep(k , 0 , 11){
    rep(z , 0 , 11){
        add(sdp[i][k][z] , dp[i][j][k][z]);
        rep(f , 1 , i+1){
            add(dp[i+1][f][k+(i+1-f)][z+(j >= f)] , dp[i][j][k][z]);
        }
    }
    }
    }
    }
    rep(i , 1 , 23){
    rep(j , 0 , 11){
    rep(k ,0 , 11){
        dp2[i][j][k] = sdp[i][j][k] ;
        rep(t , 1 , i-1){
        rep(j2 , 0 , j){
        rep(k2 , 0 , k){
            sub(dp2[i][j][k] , 1ll*sdp[i-t][j-j2][k-k2] * dp2[t][j2][k2]%mod);
        }
        }
        }
    }
    }
    }
    dp3[0][0][0][0] = 1; 
    rep(i ,1 , 23){
    rep(j , 0 , 23){
    rep(k , 0 , 11){
    rep(z , 0 ,11){
        rep(j2 ,2,j){
        rep(k2 ,0,k){
        rep(z2 ,0,z){
            add(dp3[i][j][k][z] , 1ll*dp3[i-1][j-j2][k-k2][z-z2]*dp2[j2][k2][z2]%mod);
        }
        }
        }
    }
    }
    }
    }  
    rep(i , 0 ,maxn-1){
        inv[i] = po(i , mod-2) ;
    }
    int q ;
    cin >> q ;
    while(q--){
        int n , a , b;
        cin >> n >> a >> b; 
        int ans =0 ;
        rep(i , 0 , 11){
        rep(j , 0 , 23){
     //       if(dp3[i][j][a][b] * c(n-j+i , i)%mod !=0 )cout << i << " " << j << "<--\n"; 
            ans = (ans + 1ll*dp3[i][j][a][b] * c(n-j+i , i)%mod)%mod ;
        }
        }
        cout <<ans << "\n";
    }
}
/*

*/