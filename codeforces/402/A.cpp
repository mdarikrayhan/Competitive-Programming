#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define opt() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
void code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}
const int MOD=1e9+7;

int32_t main()
{
    opt();
    int t=1;
    //cin>>t;
    while(t--)
    {
      int k,a,b,v;
      cin>>k>>a>>b>>v;
      int ans=0;
      while(a>0)
      {
         int x=k-1;
         int p=min(x,b);
         int q=(p+1)*v;
         a-=q;
         b-=p;
         ans++;
      }
      cout<<ans<<endl;
    }
    return 0;
}
