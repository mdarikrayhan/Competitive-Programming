#include<cstdio>
using namespace std;
const int MAXN=200005;
int n,m,h,t,head[MAXN],nxt[MAXN],num[MAXN],tot,st[MAXN],x[MAXN],y[MAXN];
int ans1[MAXN],ans2[MAXN],u,v,cnt1,cnt2,tt[MAXN];
void add(int x,int y){
	nxt[++tot]=head[x];head[x]=tot;num[tot]=y;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&h,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		tt[x[i]]++;tt[y[i]]++;
		add(x[i],y[i]);add(y[i],x[i]);
	}
	for(int i=1;i<=n;i++)tt[i]--;
	for(int l=1;l<=m;l++){
		if(tt[x[l]]<h||tt[y[l]]<t)continue;
		cnt1=cnt2=0;
		for(int i=head[x[l]];i;i=nxt[i])if(num[i]!=y[l])st[num[i]]++;
		for(int i=head[y[l]];i;i=nxt[i])if(num[i]!=x[l])st[num[i]]++;
		cnt1=cnt2=0;
		
		for(int i=head[x[l]];i;i=nxt[i]){
			if(st[num[i]]==1)ans1[++cnt1]=num[i];
			if(cnt1>=h)break;	
		}
		for(int i=head[x[l]];i;i=nxt[i]){
			if(st[num[i]]==2&&cnt1<h)ans1[++cnt1]=num[i],st[num[i]]=3;
			if(cnt1>=h)break;
		}
		
		for(int i=head[y[l]];i;i=nxt[i]){
			if(st[num[i]]==1)ans2[++cnt2]=num[i];
			if(cnt2>=t)break;
		}
		for(int i=head[y[l]];i;i=nxt[i]){
			if(st[num[i]]==2&&cnt2<t)ans2[++cnt2]=num[i],st[num[i]]=3;
			if(cnt2>=t)break;
		}
		
		if(cnt1>=h&&cnt2>=t){
			printf("YES\n");
			printf("%d %d\n",x[l],y[l]);
			for(int i=1;i<=h;i++)printf("%d ",ans1[i]);printf("\n");
			for(int i=1;i<=t;i++)printf("%d ",ans2[i]);printf("\n");
			return 0;
		}
		
		for(int i=head[x[l]];i;i=nxt[i])st[num[i]]=0;
		for(int i=head[y[l]];i;i=nxt[i])st[num[i]]=0;
	}
	
	for(int l=1;l<=m;l++){
		cnt1=cnt2=0;
		if(tt[x[l]]<t||tt[y[l]]<h)continue;
		for(int i=head[x[l]];i;i=nxt[i])if(num[i]!=y[l])st[num[i]]++;
		for(int i=head[y[l]];i;i=nxt[i])if(num[i]!=x[l])st[num[i]]++;
		cnt1=cnt2=0;
		
		for(int i=head[x[l]];i;i=nxt[i]){
			if(st[num[i]]==1)ans1[++cnt1]=num[i];
			if(cnt1>=t)break;	
		}
		for(int i=head[x[l]];i;i=nxt[i]){
			if(st[num[i]]==2&&cnt1<t)ans1[++cnt1]=num[i],st[num[i]]=3;
			if(cnt1>=t)break;
		}
		
		for(int i=head[y[l]];i;i=nxt[i]){
			if(st[num[i]]==1)ans2[++cnt2]=num[i];
			if(cnt2>=h)break;
		}
		for(int i=head[y[l]];i;i=nxt[i]){
			if(st[num[i]]==2&&cnt2<h)ans2[++cnt2]=num[i],st[num[i]]=3;
			if(cnt2>=h)break;
		}
		
		
		if(cnt1>=t&&cnt2>=h){
			printf("YES\n");
			printf("%d %d\n",y[l],x[l]);
			for(int i=1;i<=h;i++)printf("%d ",ans2[i]);printf("\n");
			for(int i=1;i<=t;i++)printf("%d ",ans1[i]);printf("\n");
			return 0;
		}
		
		for(int i=head[x[l]];i;i=nxt[i])st[num[i]]=0;
		for(int i=head[y[l]];i;i=nxt[i])st[num[i]]=0;
	}
	printf("NO\n");
	return 0;
}