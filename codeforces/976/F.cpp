// LUOGU_RID: 156983857
#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct point{
	LL to,nt,flow;
}a[16005],b[16005];
LL n1,n2,i,j,k,m,s,t,ans=0,cnt=1,cnt1=1,x,y;
LL deg1[2005],deg2[2005],gap[4005];
queue<LL> q;
LL nxt[4005],nxt1[4005],depth[4005],val[4005];
const LL inf=0x7fffffff;
void bfs(){
	memset(depth,0x7f,sizeof(depth));
	memset(gap,0,sizeof(gap));
	depth[t]=0;q.push(t);
	while(!q.empty()){
		LL tmp=q.front();q.pop();
		for(LL i=nxt[tmp];i;i=a[i].nt)
		  if(depth[a[i].to]==0x7f7f7f7f7f7f7f7f){
		  	depth[a[i].to]=depth[tmp]+1;
		  	gap[depth[a[i].to]]++;
		  	q.push(a[i].to); 
		  }
	}
}
LL dfs(LL x,LL flow){
	if(x==t){
		ans+=flow;
		return flow;
	}
	LL sum=0;
	for(LL i=nxt[x];i;i=a[i].nt)
	  if(depth[a[i].to]+1==depth[x] && a[i].flow>0){
	  	LL tmp=dfs(a[i].to,min(flow-sum,a[i].flow));
	  	if(tmp>0){
	  		sum+=tmp;
	  		a[i].flow-=tmp;a[i^1].flow+=tmp;
	    }
	    if(sum==flow) return sum;
	  }
	gap[depth[x]]--;
	if(gap[depth[x]]==0) depth[s]=n1+n2+2;
	gap[++depth[x]]++;
	return sum;
}
void isap(){
	while(depth[s]<n1+n2+2) dfs(s,inf);
}
void add(LL x,LL y,LL flow){
	a[++cnt].to=y;a[cnt].nt=nxt[x];nxt[x]=cnt;a[cnt].flow=flow;
	a[++cnt].to=x;a[cnt].nt=nxt[y];nxt[y]=cnt;a[cnt].flow=0;
}
void add1(LL x,LL y,LL flow){
	b[++cnt1].to=y;b[cnt1].nt=nxt1[x];nxt1[x]=cnt1;b[cnt1].flow=flow;
	b[++cnt1].to=x;b[cnt1].nt=nxt1[y];nxt1[y]=cnt1;b[cnt1].flow=0;
}
int main(){
	scanf("%lld%lld%lld",&n1,&n2,&m);
	bool flag=false;
	if(n1<n2) swap(n1,n2),flag=true;
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		if(flag==true) swap(x,y);
		deg1[x]++,deg2[y]++;
		add1(x,n1+y,1);
	}
	LL minx=0x7fffffff;
	for(i=1;i<=n1;i++)
	  minx=min(minx,deg1[i]);
	for(i=1;i<=n2;i++)
	  minx=min(minx,deg2[i]);
	s=n1+n2+1,t=n1+n2+2;
	printf("0\n");
	for(i=1;i<=minx;i++){
		cnt=cnt1;
		memcpy(a,b,sizeof(b));
		memcpy(nxt,nxt1,sizeof(nxt1));
		for(j=1;j<=n1;j++)
		  add(s,j,i);
		for(j=1;j<=n2;j++)
		  add(j+n1,t,i);
		bfs();
		isap();
		for(j=1;j<=n1;j++)
		  val[j]=0;
		printf("%lld ",i*n1);
		for(j=1;j<=m;j++){
			if(a[j*2].flow==0){
				printf("%lld ",j);
				val[a[j*2+1].to]++;
			}
		}
		for(j=1;j<=m;j++)
		  if(a[j*2].flow==1 && val[a[j*2+1].to]<i){
		  	printf("%lld ",j);
		  	val[a[j*2+1].to]++;
		  } 
		printf("\n");
	}
	return 0;
}