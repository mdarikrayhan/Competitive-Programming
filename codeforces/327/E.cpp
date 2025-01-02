// LUOGU_RID: 160505833
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<set>
#include<ctime>
#define pii pair<int,int>

using namespace std;
const int M=(1<<24),p=1e9+7;
int n,m,a[M],q[3],f[M],g[M];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  register int i;
  for(i=1;i<=n;i++)a[(1<<(i-1))]=read();
  m=read();q[1]=q[2]=-1;
  if(m>=1)q[1]=read();
  if(m>=2)q[2]=read();
  
  int ms=(1<<n)-1;f[0]=1;
  for(i=1;i<=ms;i++){
    int x=i;
    while(x){
      int j=x&-x;x-=j;
      g[i]=g[i-j]+a[j];
      if(g[i]==q[1]||g[i]==q[2])continue;
      f[i]+=f[i-j];
      if(f[i]>=p)f[i]-=p;
    }
  }
  printf("%d",f[ms]);
  return 0;
}