// LUOGU_RID: 158565646
#include<bits/stdc++.h>
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=2e5+5;
inline int read(){
  char ch=getchar();int x=0;
  while(ch<'0'||ch>'9') ch=getchar();
  while(ch>='0'&&ch<='9')
    x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return x;
}
ll ans[N];
ll calc(ll x){return x*(x-1)*(x-2)/6;}
int len(int l,int r){return l<=r?r-l+1:0;}
vector<pair<int,int> >V[N];
ll c[N];
void add(int x,int v){while(x<N) c[x]+=v,x+=(x&-x);}
ll qry(int x){ll s=0;while(x) s+=c[x],x^=(x&-x);return s;}
int cnt[N];
signed LJY(){
  int n=read();
  for(int i=1;i<=n;i++){
    int l=read(),r=read();
    ans[i]=calc(r-l+1);
    ans[i]-=len((l+2)/3,r/6);
    ans[i]-=len((l+5)/6,r/15);
    V[l].emplace_back(i,r);
  }for(int i=N-1;i;i--){
    for(int j=i<<1;j<N;j+=i) add(j,cnt[j]++);
    for(auto [id,v] within V[i]) 
      ans[id]-=qry(v)-qry(i-1);
  }for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
  return 0;
}