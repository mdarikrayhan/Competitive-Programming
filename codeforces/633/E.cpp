#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct sparse_table
{
    vector<vector<int>>tb;
    sparse_table(vector<int>a)
    {
        int sz=__lg(a.size())+1;
        tb.resize(sz);
        for(auto &x:tb)x.resize(a.size()+5);
        for(int i=0;i<a.size();i++)tb[0][i]=a[i];
        for(int i=1;i<sz;i++)
            for(int j=0;j+(1<<i)<=a.size();j++)
            tb[i][j]=max(tb[i-1][j],tb[i-1][j+(1<<(i-1))]);
    }
    int seg_max(int l,int r)
    {
        int lg=__lg(r-l+1);
        return max(tb[lg][l],tb[lg][r-(1<<lg)+1]);
    }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  vector<int>a(n),b(n);
  for(auto &x:a)cin>>x;
  for(auto &x:b)cin>>x,x=-x;
  sparse_table tba(a),tbb(b);
  vector<int>all_cost;
  for(int i=0;i<n;i++)
  {
      int l=i,r=n-1,mid,ans=i;
      while(l<=r)
      {
          mid=(l+r)/2;
          if(tba.seg_max(i,mid)*100<=-tbb.seg_max(i,mid))l=mid+1,ans=mid;
          else r=mid-1;
      }
      int val=min(tba.seg_max(i,ans)*100,-tbb.seg_max(i,ans));
      if(ans<n-1)val=max(val,min(tba.seg_max(i,ans+1)*100,-tbb.seg_max(i,ans+1)));
      all_cost.push_back(val);
  }
  sort(all_cost.begin(),all_cost.end());
  long double f_sum=0;
  vector<long double>f_val(n);
  long double cur_v=1;
  for(int i=0;i<n;i++)
  {
      f_val[i]=cur_v;
      f_sum+=cur_v;
      if(n-i-k==0)break;
      cur_v/=((long double)n-i-1)/(n-i-k);
  }
  long double ans=0;
  for(int i=0;i<n;i++)ans+=all_cost[i]*f_val[i]/f_sum;
  cout<<fixed<<setprecision(9)<<ans;
}
