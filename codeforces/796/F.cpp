// LUOGU_RID: 113074590
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int t[N<<2],lim[N],n,m,l,r,x,opt,y,ans,t2[N<<2];
map<int,int>c,tag;
void setmax(int x,int l,int r,int L,int R,int w){
	if(l>=L&&r<=R){t[x]=min(t[x],w);return;}
	int mid=(l+r)>>1;
	if(mid>=L)setmax(x<<1,l,mid,L,R,w);
	if(mid+1<=R)setmax(x<<1|1,mid+1,r,L,R,w);
}
int qry(int x,int l,int r,int p){
	int rec=t[x];
	while(l<r){
		int mid=(l+r)>>1;
		if(mid>=p)r=mid,x=x<<1;
		else l=mid+1,x=x<<1|1;
		rec=min(rec,t[x]);
	}
	return rec;
}
void modify(int x,int l,int r,int p,int w){
	if(l==r){t2[x]=w;return;}
	int mid=(l+r)>>1;
	if(mid>=p)modify(x<<1,l,mid,p,w);
	else modify(x<<1|1,mid+1,r,p,w);
	t2[x]=max(t2[x<<1],t2[x<<1|1]);
}
int query(int x,int l,int r,int L,int R){
	if(l>=L&&r<=R)return t2[x];
	int mid=(l+r)>>1;
	if(mid<L)return query(x<<1|1,mid+1,r,L,R);
	if(mid+1>R)return query(x<<1,l,mid,L,R);
	return max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=4*n;i++)t[i]=1e9,t2[i]=-1;
	for(int i=1;i<=n;i++)lim[i]=1e9+1;
	for(int op,l,r,x;m--;){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&l,&r,&x);
			int now=query(1,1,n,l,r);
			if(now>x)return puts("NO"),0;
			if(now<x)tag[x]=1;
			setmax(1,1,n,l,r,x);
		}else{
			scanf("%d%d",&x,&y);
			if(lim[x]==1e9+1)lim[x]=qry(1,1,n,x);
			modify(1,1,n,x,y);
		}
	}
	for(int i=1;i<=n;i++)
		if(lim[i]==1e9+1)lim[i]=qry(1,1,n,i);
	for(int i=1;i<=n;i++)c[lim[i]]++;
	for(auto i:tag)
		if(!c[i.first])return puts("NO"),0;
	puts("YES");
	if(c[1e9]>=2){
		for(int i=1;i<=n;i++)
			if(lim[i]==1e9){lim[i]=(1<<29)-1;break;}
		for(int i=1;i<=n;i++){
			if(lim[i]==1e9)lim[i]=1e9;
			printf("%d ",lim[i]);
		}return 0;
	}
	for(int i=1;i<=n;i++){
		if(lim[i]==1e9||lim[i]==0)continue;
		c[lim[i]]--;
		if(c[lim[i]]){
			int t=1;
			while(t<=lim[i])t=t<<1|1;
			lim[i]=t>>1;
		}
		ans|=lim[i];
	}
	int tt=0;
	for(int w=29;w>=0;w--){
		if(ans>>w&1)continue;
		if(tt+(1<<w)<=1e9)tt+=1<<w;
	}
	for(int i=1;i<=n;i++){
		if(lim[i]==1e9)lim[i]=tt;
		printf("%d ",lim[i]);
	}
}