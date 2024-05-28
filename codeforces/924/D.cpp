#include <iostream>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<__float128, null_type,less<__float128>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,w;
  cin>>n>>w;
  vector<vector<__float128>>a(n,vector<__float128>(3));
  int tmp;
  for(auto &x:a)
  {
      cin>>tmp;
      x[1]=tmp;
      cin>>tmp;
      x[2]=tmp;
      x[0]=-(x[1]/(x[2]+w+1e-15));
  }
  sort(a.begin(),a.end());
  long long int ans=0;
  ordered_set st;
  for(auto &x:a)
  {
      __float128 nw_val=-(x[1]/(x[2]-w-1e-15));
      ans+=st.size()-st.order_of_key(nw_val);
      st.insert(nw_val);
  }
  cout<<ans;
}
