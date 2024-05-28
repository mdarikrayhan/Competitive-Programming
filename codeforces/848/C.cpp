#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;
struct weird_ds
{
    vector<pair<int,int>>val;
    stack<tuple<int,int,int>>st;
    long long int prev=0;
    long long int ans=0;
    weird_ds(int sz)
    {
        val.resize(sz,{1e9,-1e9});
    }
    void add_val(int idx,int x)
    {
        st.push({idx,val[idx].first,val[idx].second});
        int prev_diff=max(0,val[idx].second-val[idx].first);
        val[idx].first=min(val[idx].first,x);
        val[idx].second=max(val[idx].second,x);
        int nw_diff=max(0,val[idx].second-val[idx].first);
        ans+=nw_diff-prev_diff;
    }
    long long int res_val()
    {
        return ans;
    }
    void checkpoint()
    {
        while(st.size())st.pop();
        prev=ans;
    }
    void return_to_checkpoint()
    {
        ans=prev;
        while(st.size())
        {
            tuple<int,int,int>x=st.top();
            st.pop();
            val[get<0>(x)].first=get<1>(x),val[get<0>(x)].second=get<2>(x);
        }
    }
};
const int sz=2100;
int main()
{
  int n,q;
  cin>>n>>q;
  vector<int>a(n);
  for(auto &x:a)cin>>x;
  vector<vector<vector<vector<int>>>>queries(q/sz+1,vector<vector<vector<int>>>(n/sz+1));
  vector<vector<vector<int>>>change_q(q/sz+1);
  vector<vector<vector<int>>>base_q(q/sz+1);
  vector<bool>output(q);
  for(int i=0;i<q;i++)
  {
      vector<int>val(3);
      for(auto &x:val)cin>>x;
      if(val[0]==1)
      {
          val[1]--;
          change_q[i/sz].push_back({i,val[1],val[2]});
      }
      if(val[0]==2)
      {
          val[1]--,val[2]--;
          if((val[1]+sz-1)/sz==val[2]/sz+1)
          {
              base_q[i/sz].push_back({val[2],val[1],i});
              output[i]=true;
              continue;
          }
          queries[i/sz][(val[1]+sz-1)/sz].push_back({val[2],val[1],i});
          output[i]=true;
      }
  }
  for(auto &x:queries)
    for(auto &y:x)
    sort(y.begin(),y.end());
  vector<long long int>ans(q);
  for(int f=0;f<q/sz+1;f++)
  {
      vector<int>base_a=a;
      vector<bool>is_fixed(n,true);
      vector<int>weird_val;
      for(auto &x:change_q[f])
      {
          if(is_fixed[x[1]])
          {
              is_fixed[x[1]]=false;
              weird_val.push_back(x[1]);
          }
      }
      weird_ds st(n+1);
      for(auto &x:base_q[f])
      {
          for(int i=x[1];i<=x[0];i++)if(is_fixed[i])st.add_val(a[i],i);
          for(auto &y:change_q[f])
          {
              if(x[2]<y[0])break;
              a[y[1]]=y[2];
          }
          for(auto &y:weird_val)if(y>=x[1]&&y<=x[0])st.add_val(a[y],y);
          for(auto &y:weird_val)a[y]=base_a[y];
          ans[x[2]]=st.ans;
          st.return_to_checkpoint();
      }
      for(int i=0;i<n/sz+1;i++)
      {
          weird_ds st(n+1);
          int cur_r=i*sz-1;
          for(auto &x:queries[f][i])
          {
              while(x[0]>cur_r)
              {
                  if(is_fixed[cur_r+1])st.add_val(a[cur_r+1],cur_r+1);
                  cur_r++;
              }
              st.checkpoint();
              int cur_l=i*sz;
              while(cur_l>x[1])
              {
                  if(is_fixed[cur_l-1])st.add_val(a[cur_l-1],cur_l-1);
                  cur_l--;
              }
              for(auto &y:change_q[f])
              {
                  if(x[2]<y[0])break;
                  a[y[1]]=y[2];
              }
              for(auto &y:weird_val)if(y>=x[1]&&y<=x[0])st.add_val(a[y],y);
              for(auto &y:weird_val)a[y]=base_a[y];
              ans[x[2]]=st.ans;
              st.return_to_checkpoint();
          }
      }
      for(auto &x:change_q[f])
      {
          a[x[1]]=x[2];
      }
  }
  for(int i=0;i<q;i++)if(output[i])cout<<ans[i]<<endl;
}
