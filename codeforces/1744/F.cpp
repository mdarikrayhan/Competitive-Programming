/*
   ॐ नमो भगवते वासुदेवाय नमः
   ॐ भूर्भुव: स्व: तत्सवितुर्वरेण्यं भर्गो देवस्य धीमहि धियो यो न: प्रचोदयात्।
*/
// all hail Infront of almighty lord krishna (jai shri krishna ji)
  #include<bits/stdc++.h>
  #ifndef  ONLINE_JUDGE
  #include "debug.h"
  #else
  #define print(...) 1;
  #endif
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  using namespace std;
  using namespace __gnu_pbds;
  #define int long long 
  const long long INF =1e18;
  template<class T>
  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
  template<typename T> 
  using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
  const int N=2e5 +10;
  const int mod = 998244353;

  void Solve() 
  {
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>pos;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      pos[a[i]]=i;
    }
    int ans=0;
    int l=1e9;
    int r=-1e9;
    for(int k=1;k<=n;k++)
    {
       if(k%2==1)
       {
        l=min(l,pos[k/2]);
        r=max(r,pos[k/2]);
       }
       if(r-l+1>k)
       {
        continue;
       }
       ans+=(min(l,n-k)- max(0ll,r-k+1)+1);
    }
    cout<<ans<<"\n";
  }

  signed main()
  { 
    
      auto begin = std::chrono::high_resolution_clock::now();
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout<<fixed;
      int t = 1;
      cin >> t;

      for(int i = 1; i <= t; i++) 
      {
          // cout << "Case #" << i << ": ";
          Solve();
 
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
      // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
      return 0;       
  }