#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define inf 0x3f3f3f3f
int T,n,m,a[N],nd[N],nxt[N],last[N],cur[N],tot;
int dd[4];
int in[N],out[N];
bool flag[N];
struct EDGE{
  int to,pre,w;
}e[N<<4];
void add(int x,int y,int z){
  e[++tot].to=y;e[tot].w=z;e[tot].pre=last[x];last[x]=tot;
}
int dep[N];
queue<int>q;
bool bfs(){
  for(int i=0;i<=n*m+1;++i)dep[i]=0;
  dep[0]=1;q.push(0);
  while(!q.empty()){
    int x=q.front();q.pop();cur[x]=last[x];
    for(int i=last[x];i;i=e[i].pre){
      int y=e[i].to;if(dep[y]||!e[i].w)continue;
      dep[y]=dep[x]+1;q.push(y);
    }
  }
  return dep[n*m+1];
}
int dinic(int x,int t,int flow){
  if(x==t)return flow;
  int rest=flow;
  for(int i=cur[x];i;cur[x]=i=e[i].pre){
    int y=e[i].to;if(dep[y]!=dep[x]+1||!e[i].w)continue;
    int z=dinic(y,t,min(rest,e[i].w));
    e[i].w-=z;e[i^1].w+=z;rest-=z;
  }
  return flow-rest;
}
void dfs(int x){
  flag[x]=1;
  if(!out[x]||flag[out[x]])return;
  flag[out[x]]=1;
  nxt[x]=out[x];nxt[out[x]]=x;
  if(out[out[x]]&&!flag[out[out[x]]])dfs(out[out[x]]);
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    dd[0]=-m;dd[1]=-1;dd[2]=1;dd[3]=m;
    assert(dd[0]==-m&&dd[1]==-1&&dd[2]==1&&dd[3]==m);
    for(int i=1;i<=n*m;++i)scanf("%d",a+i),nd[i]=2,in[i]=out[i]=0,flag[i]=0;
    bool ok=1;
    for(int i=1;i<=n*m;++i){
      for(int j=0;j<4;++j){
        if(m==1&&(j==1||j==2))continue;
        int y=i+dd[j];
        if(y<1||y>n*m||(j==1&&i%m==1)||(j==2&&i%m==0))continue;
        //        assert(dd[j]==1||dd[j]==-1||dd[j]==m||dd[j]==-m);
        //        if(n==1)assert(y==i+1||y==i-1||y==i-m||y==i+m);
        if(a[y]<a[i]){nxt[i]=y;nd[i]=min(nd[i],0);}
        if(a[y]==a[i])nd[i]=min(nd[i],1);
      }
      if(nd[i]==2){
        puts("NO");ok=0;break;
      }
    }
    if(!ok)continue;
    for(int i=0;i<=n*m+1;++i)last[i]=0;tot=1;
    int ans=0;
    for(int i=1;i<=n;++i){
      for(int j=1;j<=m;++j){
        int x=(i-1)*m+j;
        if((i+j)&1){
          if(!nd[x])continue;++ans;
          add(0,x,1);add(x,0,0);
          for(int k=0;k<4;++k){
            if(m==1&&(k==1||k==2))continue;
            int y=x+dd[k];if(y<1||y>n*m||(k==1&&x%m==1)||(k==2&&x%m==0))continue;
            if(a[x]==a[y])add(x,y,1),add(y,x,0);
          }
        }
        else add(x,n*m+1,1),add(n*m+1,x,0);
      }
    }
    while(bfs()){
      ans-=dinic(0,n*m+1,inf);
    }
    if(ans){puts("NO");break;}
    for(int uu=last[0];uu;uu=e[uu].pre){
      int x=e[uu].to;
      for(int i=last[x];i;i=e[i].pre){
        int y=e[i].to;if(!e[i].w){out[x]=y;in[y]=x;break;}
      }
    }
    for(int i=0;i<=n*m+1;++i)last[i]=0;tot=1;
    ans=0;
    for(int i=1;i<=n;++i){
      for(int j=1;j<=m;++j){
        int x=(i-1)*m+j;
        if((i+j)&1)add(x,n*m+1,1),add(n*m+1,x,0);
        else{
          if(!nd[x])continue;++ans;
          add(0,x,1);add(x,0,0);
          for(int k=0;k<4;++k){
            if(m==1&&(k==1||k==2))continue;
            int y=x+dd[k];if(y<1||y>n*m||(k==1&&x%m==1)||(k==2&&x%m==0))continue;
            if(a[x]==a[y])add(x,y,1),add(y,x,0);
          }
        }
      }
    }
    while(bfs()){
      ans-=dinic(0,n*m+1,inf);
    }
    if(ans){puts("NO");break;}
    for(int uu=last[0];uu;uu=e[uu].pre){
      int x=e[uu].to;
      for(int i=last[x];i;i=e[i].pre){
        int y=e[i].to;if(!e[i].w){out[x]=y;in[y]=x;break;}
      }
    }
    for(int i=1;i<=n*m;++i){
      if(!in[i])dfs(i);
    }
    for(int i=1;i<=n*m;++i){
      if(!flag[i])dfs(i);
    }
    puts("YES");
    for(int i=1;i<=n*m;++i){
      if(nxt[nxt[i]]==i){
        if(nxt[i]>i)printf("%d ",a[i]-1);
        else printf("%d ",1);
      }
      else printf("%d ",a[i]-a[nxt[i]]);
      if(i%m==0)puts("");
    }
    for(int i=1;i<=n*m;++i){
      if(i-nxt[i]==m){printf("U ");if(i%m==0)puts("");continue;}
      if(nxt[i]-i==m){printf("D ");if(i%m==0)puts("");continue;}
      if(i-nxt[i]==1){printf("L ");if(i%m==0)puts("");continue;}
      if(nxt[i]-i==1){printf("R ");if(i%m==0)puts("");continue;}
    }
  }
  return 0;
}

	   				 	  			  	 	          	