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
int n,p;
cin>>n>>p;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
vector<int>v;
for(int x=1;x<=a[n-1]+1;x++){
  bool ok=true;
  for(int j=0;j<n;j++){
    int it=upper_bound(a,a+n,x+j)-a-j;
    it=max(it,0);
    if(it%p==0){ok=false;break;}
  }
  if(ok)v.pb(x);
}
cout<<v.size()<<"\n";
for(auto l:v)cout<<l<<" ";


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



