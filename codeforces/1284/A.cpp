#include"bits/stdc++.h" 
using namespace std; 
#ifdef ONLINE_JUDGE
#define debug(...) 42
#else
#include "puppet.h"
#endif
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define bplc __builtin_popcountll 
#define bpc __builtin_popcount
#pragma GCC optimize("Ofast")
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

template<class T> using pbds= tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_heap=priority_queue<T, vector<T>, greater<T>>;
// *a.find_by_order(x)-->gives xth element considering 0 indexing
// a.order_of_key(x)-->gives number of elements strictly smaller than x



void solve(){
  int n,m;
  cin>>n>>m;
  string s1[n],s2[m];
  for(int i=0;i<n;i++){
    cin>>s1[i];
  }
  for(int i=0;i<m;i++)cin>>s2[i];
    int q;
  cin>>q;
  while(q--){
    int y;
    cin>>y;y--;
    cout<<s1[y%n]+s2[y%m]<<"\n";
  }
}



int main(){ 



 ios::sync_with_stdio(0);
  cin.tie(0);



 int T=1;
// cin>>T;
while(T--){
    solve();
}




    return 0; 
} 

