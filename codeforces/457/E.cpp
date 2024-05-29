#include<iostream>
#include<cstdio>
using namespace std;
#define N 200012
int n,m,f[N],g[N],mn[N],mx[N],su;
inline int getf(int x){if(f[x]==x)return x;int y=getf(f[x]);g[x]+=g[f[x]];return (f[x]=y);}
int main(){
	scanf("%d%d",&n,&m);int i,x,y,c,v,v1,t1,t2;for(i=1;i<=n;i++)f[i]=i,mn[i]=mx[i]=0;mn[1]=0x3f3f3f3f;mx[n]=-1;su=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&c,&v);t1=getf(x);t2=getf(y);
		if(t1==t2){if(g[x]+v*c!=g[y]){printf("BAD %d",i);return 0;}}
		else f[t2]=t1,v1=g[t2]=(g[x]-g[y]+v*c),mn[t1]=min(mn[t1],mn[t2]+v1),mx[t1]=max(mx[t1],mx[t2]+v1);
		t1=getf(1);if((getf(x)==t1)&&(mn[t1]<=g[1])){printf("BAD %d",i);return 0;}
		t2=getf(n);if((getf(y)==t2)&&(mx[t2]>=g[n])){printf("BAD %d",i);return 0;}
		su=max(su,mx[getf(x)]-mn[getf(y)]);if((getf(1)==getf(n))&&(su>=g[n]-g[1])){printf("BAD %d",i);return 0;}
	}
	if(getf(1)!=getf(n)){printf("UNKNOWN");return 0;}printf("%d",g[n]-g[1]);return 0;
}