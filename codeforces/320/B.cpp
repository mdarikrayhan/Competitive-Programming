#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#define  pi 3.1415926535898
#define  radian(x) x=pi*(x/180.0)
#define  m2s ios::sync_with_stdio(0);cin.tie(NULL);
#define  cout  cout<<std::fixed<<std::setprecision(10)
#define  yes cout<<"YES"<<endl
#define  no cout<<"NO"<<endl
#define  ll   long long
#define  endl "\n"<<flush
#define  pb push_back
#define  MOD2 998244353
#define  MOD1 1000000007
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> mytree;*/
const long long n=105;
long long g=0;
vector<vector<long long>>v(n);
bool visited[n]={false};
void dfs(long long z,long long f)
{
  if(z==f)  {g=1;}
  visited[z]=true;
  for(auto w:v[z])
    if(!visited[w]) dfs(w,f);
}
int main()
{
  m2s;
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  long long  a,b,c,d,e,h,i,j,x,y,z,x1,x2,x3,x4,x5,x6,y1,y2,y3,y4;
  long double w,w2,w5;
  char l;
  string s="",s1="",s2="",s3="ko",s4="";
  int t=1;
  //vector<vector<long long>> v;
  //map<long long,long long>m;
  //vector<long long> v;
  //cin>>t;
  while(t--)
  {
   vector<pair<int,int>> vv;
   cin>>c;
   while(c--)
   {
    cin>>z;
    if(z==1)
    {
     cin>>x>>y;
     for(int i=0;i<vv.size();i++)
     {
      if((vv[i].first<x&&x<vv[i].second)||(vv[i].first<y&&y<vv[i].second)) v[vv.size()+1].pb(i+1);
      if((x<vv[i].first&&vv[i].first<y)||(x<vv[i].second&&vv[i].second<y)) v[i+1].pb(vv.size()+1);
     }
     vv.pb({x,y});
    }
    else
    {
     cin>>x>>y;
     memset(visited,false,sizeof visited);
     g=0;
     dfs(x,y);
     if(g) yes;
     else no;
     /*for(int i=1;i<=vv.size();i++)
     {
      cout<<i<<": ";
      for(int ii=0;ii<v[i].size();ii++) cout<<v[i][ii]<<" ";
      cout<<endl;
     }*/
    }
   }
  }
}
