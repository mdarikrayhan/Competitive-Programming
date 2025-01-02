// LUOGU_RID: 156910649
#include<bits/stdc++.h>
#define LL long long
#define SZ(x) ((LL)(x.size()))
using namespace std;
long long read(){
  long long q=0,w=1;
  char ch=getchar();
  while(ch>'9' || ch<'0'){if(ch=='-')w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){q=q*10+(ch-'0');ch=getchar();}
  return q*w;
}
void write(LL x){
  if(x<0){putchar('-');x=(-x);}
  if(x>9)write(x/10);
  putchar('0'+x%10);
}
void writeln(LL x){write(x);puts("");}
void writecs(LL x){write(x);putchar(' ');}

void lsh(vector<LL>&vc){
  sort(vc.begin(),vc.end());
  vc.erase(unique(vc.begin(),vc.end()),vc.end());
  return ;
}

#define PLL pair<LL,LL>
#define mp(a,b) make_pair(a,b)
#define fir first
#define sec second

const long long N = 100000+95;
LL n,a[N],b[N];multiset<LL>dp[N],HP;LL DP[N];

inline LL deg(LL x){return (SZ(dp[x])+2);}
inline void ins(LL x){
  if(!SZ(dp[x]))return ;
  HP.insert((*dp[x].begin())+(b[x]/deg(x)));
  HP.insert((*dp[x].rbegin())+(b[x]/deg(x)));
  return ;
}
inline void del(LL x){
  if(!SZ(dp[x]))return ;
  HP.erase(HP.find((*dp[x].begin())+(b[x]/deg(x))));
  HP.erase(HP.find((*dp[x].rbegin())+(b[x]/deg(x))));
  return ;
}
inline LL qry(LL x){return DP[x]+(b[a[x]]/deg(a[x]));}
int main(){
  n=read();LL TC=read();
  for(LL i=1;i<=n;i++)b[i]=read();
  vector<LL>_deg(n+2,2);
  for(LL i=1;i<=n;i++){a[i]=read();_deg[a[i]]++;}

  for(LL i=1;i<=n;i++){
    DP[i]+=b[i]-(_deg[i]-1)*(b[i]/_deg[i]);
    DP[a[i]]+=(b[i]/_deg[i]);
  }
  for(LL i=1;i<=n;i++)dp[a[i]].insert(DP[i]);
  for(LL i=1;i<=n;i++)ins(i);
  
  while(TC--){
    LL opt=read();
    if(opt==1){
      LL x=read(),y=read();if(a[x]==y)continue;
      vector<LL>vc={x,a[x],a[a[x]],a[a[a[x]]],y,a[y],a[a[y]]};
      lsh(vc);for(auto z:vc)del(z);

      LL deg_x=deg(x),deg_ax=deg(a[x]),deg_y=deg(y);
      for(auto z:vc)dp[a[z]].erase(dp[a[z]].find(DP[z]));
      
      DP[a[x]]-=(b[x]/deg_x);
      DP[y]+=(b[x]/deg_x);

      DP[a[a[x]]]-=(b[a[x]]/deg_ax);DP[a[x]]-=b[a[x]]-(deg_ax-1)*(b[a[x]]/deg_ax);
      DP[a[a[x]]]+=(b[a[x]]/(deg_ax-1));DP[a[x]]+=b[a[x]]-(deg_ax-2)*(b[a[x]]/(deg_ax-1));

      DP[a[y]]-=(b[y]/deg_y);DP[y]-=b[y]-(deg_y-1)*(b[y]/deg_y);
      DP[a[y]]+=(b[y]/(deg_y+1));DP[y]+=b[y]-(deg_y)*(b[y]/(deg_y+1));

      a[x]=y;

      for(auto z:vc)dp[a[z]].insert(DP[z]);
      for(auto z:vc)ins(z);
    }
    else if(opt==2){LL x=read();writeln(qry(x));}
    else if(opt==3){writecs((*HP.begin()));writeln((*HP.rbegin()));}
  }
  return 0;
}
