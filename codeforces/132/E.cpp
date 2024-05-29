#include<cstdio>
#include<cstring>
#define add(x,y,z,c) addedge(x,y,z,c),addedge(y,x,0,-c)
const int N=100005,oo=100000;
int n,m,l=1,S,T,ans;
int v[N],a[N],d[N],f[N*5],now[N],pre[N],son[N],next[N],data[N],cost[N],st[N],ed[N];
bool b[N];
int cnt(int x){return x?(x&1)+cnt(x/2):0;}
void addedge(int x,int y,int z,int c)
{st[++l]=x,ed[l]=y,data[l]=z,cost[l]=c,next[l]=son[x],son[x]=l;}
bool spfa()
{
	memset(d,6,sizeof(d)); d[S]=0;
	int h=0,t=1; f[1]=S; memset(b,0,sizeof(b));
	while (h<t){
		int i=f[++h]; b[i]=0;
		for (int p=son[i];p;p=next[p]) if (data[p]){
			int j=ed[p]; if (d[i]+cost[p]>=d[j]) continue;
			d[j]=d[i]+cost[p],pre[j]=p; if (!b[j]) b[j]=1,f[++t]=j;
			}
		}
	if (d[T]>0) return 0; ans+=d[T];
	for (int p=T;p;p=st[p]) p=pre[p],data[p]--,data[p^1]++;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m),T=n*3+1,add(S,1,m,0);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]),add(i,i+n,1,cnt(a[i])),add(i+n,i+2*n,1,-oo),add(i+2*n,T,1,0);
		if (i<n) add(i+2*n,i+1,1,0),add(i,i+1,oo,0);
		}
	for (int i=1,j;i<=n;i++){
		for (j=i+1;j<=n && a[i]-a[j];j++);
		if (j<=n) add(i+2*n,j+n,1,0),v[i]=j; else l+=2;
		}
	while (spfa()); m=n; for (int i=1;i<=n;i++) if (data[n*10+i*2-1]) m--;
	printf("%d %d\n",m+n,(ans%oo+oo)%oo); memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++){
		int w=now[i]; if (!w) {for (w=97;b[w];w++); b[w]=1,printf("%c=%d\n",w,a[i]);}
		printf("print(%c)\n",w); if (data[n*10+i*2-1]) now[v[i]]=w; else b[w]=0;
		}
	return 0;
}