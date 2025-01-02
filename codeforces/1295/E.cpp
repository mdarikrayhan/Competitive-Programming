// LUOGU_RID: 160088747
#include <bits/stdc++.h>
using namespace std;
long long n,t[800005],lz[800005],sum[200005],mat[200005],u,b[200005],mi,ma,ans,suk,kit;
long long a[200005],vis[200005];
set<long long>st;
void pushup(long long id){
	if((id<<1)>4*n)return;
	t[id]=min(t[id<<1],t[(id<<1)|1]);
}
void pushdown(long long id){
	if(lz[id]==0||(id<<1)>4*n)return;
	t[id<<1]+=lz[id];
	t[(id<<1)|1]+=lz[id];
	lz[id<<1]+=lz[id];
	lz[(id<<1)|1]+=lz[id];
	lz[id]=0;
}
void build(long long id,long long l,long long r){
	if(l==r){
		t[id]=sum[l];
		return;
	}
	long long mid=l+r>>1;
	build(id<<1,l,mid);
	build((id<<1)+1,mid+1,r);
	pushup(id);
}
void update(long long id,long long l,long long r,long long x,long long y,long long val){
	if(l>=x&&r<=y){
		t[id]+=val;
		lz[id]+=val;
		return;
	}
	pushdown(id);
	long long mid=(l+r)>>1;
	if(x<=mid)update(id<<1,l,mid,x,y,val);
	if(y>mid)update((id<<1)+1,mid+1,r,x,y,val);
	pushup(id);
}
long long query(long long id,long long l,long long r,long long x,long long y){
	if(l>=x&&r<=y){
		return t[id];
	}
	pushdown(id);
	long long mid=(l+r)>>1,res=1000000000000000000;
	if(x<=mid)res=query(id<<1,l,mid,x,y);
	if(y>mid)res=min(res,query((id<<1)+1,mid+1,r,x,y));
	return res;
}

int main(){	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>b[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>u;
		a[b[i]]=u;
	}
	
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	build(1,1,n);
	ans=10000000000000000;
	mi=1,ma=b[1];

	for(long long i=1;i<n;i++){
		update(1,1,n,b[i],n,-2ll*a[b[i]]);
		suk+=a[b[i]];
		vis[b[i]]=1;
		ma=max(ma,b[i]);
		while(vis[mi]==1){
			//suk-=a[b[i]];
			kit+=a[mi];
			mi++;
		}
		//cout<<mi<<" "<<ma<<"\n";
		
		if(mi>ma){
			cout<<0;
			return 0;
		}
		long long tmp=query(1,1,n,mi,ma);
		
		// cout<<tmp<<" ";
		// cout<<suk<<" ";
		// cout<<sum[mi-1]<<" ";
		// cout<<tmp+suk-sum[mi-1]+kit<<" \n";
		
		long long ans2=min(sum[ma]-sum[mi-1]-(suk-kit),suk-kit);
		ans=min(ans,tmp+suk-sum[mi-1]+kit);
		ans=min(ans,ans2);
	}
	cout<<ans;
}