#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 

#pragma GCC target("popcnt") 

#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pi 3.1415926535897932384626
#define lp(n,v) for(ll i=0;i<n;i++){ll x; cin >> x; v.emplace_back(x);}
using namespace std;
// using namespace __gnu_pbds; 

const ll N = 1e5 + 10;
const ll M = 1e9 + 7;

const ll inf = 1e9 + 10;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1}; 

// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; 

ll n,m,k;
vector<vector<ll>> v(110, vector<ll> (110,0));
vector<ll> col(110);
ll dp[110][110][110];

ll func(ll ind,ll pr,ll ct){
   if(ind == n){
      if(ct == k) return 0;
      return 1e18;
   }
   if(dp[ind][pr][ct] != -1) return dp[ind][pr][ct];
   ll ans = 1e18;
   if(col[ind] == 0){
      for(ll i = 1;i <= m; i ++){
         if(i == pr){
           ans = min(ans,func(ind+1,i,ct) + v[ind][i]);
         }
         else{
           ans = min(ans,func(ind+1,i,ct + 1) + v[ind][i]);
         }
      }
   }
   else{
      if(pr == col[ind]){
        ans = min(ans,func(ind+1,col[ind],ct));
      }
      else{
         ans = min(ans,func(ind+1,col[ind],ct+1));
      }
   }
   return dp[ind][pr][ct] = ans;
}

  
int main(){  
// dont use when question is interactive
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
    cin >> n >> m >> k;
    for(ll i = 0 ; i< n; i ++) cin >> col[i];
    
   for(ll i =0 ; i < n; i ++){
      for(ll j = 1; j <= m; j ++){
         cin >> v[i][j];
      }
    }
    for(ll i =0 ; i < 110; i ++){
      for(ll j =0 ; j < 110; j ++){
         for(ll k =0 ; k < 110; k ++){
            dp[i][j][k] = -1;
         }
      }
    }
    
    if(func(0,0,0) >= 1e18) cout << -1 << '\n';
    else cout << func(0,0,0) << '\n';

   return 0;
}
