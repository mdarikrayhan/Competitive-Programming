#include<bits/stdc++.h>
#define pb push_back
#define ll long long int

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n;
   cin >> n;
   ll arr[n][n];
   for(ll i =0 ; i < n ;i ++){
      for(ll j =0 ; j < n ; j ++) cin >> arr[i][j];
   }
   ll k;
   cin >> k;
   while(k --){
     ll x,y,z;cin >> x >> y >> z;
     x--;y--;
     arr[x][y] = min(arr[x][y],z);
     arr[y][x] = min(arr[y][x],z);

     for(ll i =0 ; i <n  ;i ++){
      for(ll j =0 ; j < n ; j ++){
         arr[i][j] = min(arr[i][j],arr[i][x] + arr[x][j]);
      }
     }

     for(ll i =0 ; i <n  ;i ++){
      for(ll j =0 ; j < n ; j ++){
         arr[i][j] = min(arr[i][j],arr[i][y] + arr[y][j]);
      }
     }

     ll sum = 0;
     for(ll i = 0 ; i < n ; i ++){
      for(ll j =0 ; j < n; j ++){
         sum += arr[i][j];
      }
     }

     cout << sum/2ll << ' ';
   }

   return 0;
}