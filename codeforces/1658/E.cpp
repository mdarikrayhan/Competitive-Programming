// LUOGU_RID: 159816762
#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
  public:
    int x,y,num;
    node(int xx=0,int yy=0,int zz=0){
      x=xx;
      y=yy;
      num=zz;
      return ;
    }
}no[2000*2000+5];
char ans[2005][2005];
bool operator < (node a,node b){
  return a.num>b.num;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int k=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      no[++cnt]=node(i,j,read());
    }
  }
  std::sort(no+1,no+cnt+1);
  int mx=(no[1].x+no[1].y);
  int mn=(no[1].x+no[1].y);
  int mx2=(no[1].x-no[1].y);
  int mn2=(no[1].x-no[1].y);
  ans[no[1].x][no[1].y]='M';
  for(int i=2;i<=cnt;i++){
    bool yes=1;
    if(mx-(no[i].x+no[i].y)>k){
      yes=0;
    }
    if((no[i].x+no[i].y)-mn>k){
      yes=0;
    }
    if(mx2-(no[i].x-no[i].y)>k){
      yes=0;
    }
    if((no[i].x-no[i].y)-mn2>k){
      yes=0;
    }
    if(yes){
      mx=std::max(mx,no[i].x+no[i].y);
      mn=std::min(mn,no[i].x+no[i].y);
      mx2=std::max(mx2,no[i].x-no[i].y);
      mn2=std::min(mn2,no[i].x-no[i].y);
      ans[no[i].x][no[i].y]='M';
    }else{
      ans[no[i].x][no[i].y]='G';
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      printf("%c",ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
inline int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){
    c=='-'?f=-1:1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+(c^48);
    c=getchar();
  }
  return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/

