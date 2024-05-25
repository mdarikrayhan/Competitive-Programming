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
ll n,m,l;
cin>>n>>m>>l;

ll a[n+2],b[n+2];
a[0]=0;a[n+1]=0;
b[0]=0;b[n+1]=0;
for(int i=1;i<=n;i++){
  cin>>a[i];
  if(a[i]>l)b[i]=1;
  else b[i]=0;
}
int cnt=0;
for(int i=0;i<=n;i++){
  if(b[i]!=b[i+1])cnt++;
}

while(m--){
  int x;
  cin>>x;
  if(x){
int p;
cin>>p;
ll d;
cin>>d;
// p--;
int bf=0;
if(p-1>=0)bf+=(b[p]!=b[p-1]);
if(p+1<=n+1)bf+=(b[p]!=b[p+1]);

a[p]+=d;
if(a[p]>l)b[p]=1;
else b[p]=0;
cnt-=bf;

bf=0;
if(p-1>=0)bf+=(b[p]!=b[p-1]);
if(p+1<=n+1)bf+=(b[p]!=b[p+1]);
cnt+=bf;

  }
  else{
    // for(int i=0;i<=n+1;i++)cout<<a[i]<<" ";
    //   cout<<"\n";
cout<<(cnt+1)/2<<"\n";
  }
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



