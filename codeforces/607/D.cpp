#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int mypow(int x){
	int ans=1,res=x,t=MOD-2;
	while(t){
		if(t&1)ans=(ll)ans*res%MOD;
		res=(ll)res*res%MOD,t>>=1;
	}
	return ans;
}
int w[200004],q,n=1,f[200004],s[200004];
vector<int>g[200004],qry[200004];
int sz[200004],cmp[200004],cnt;
void dfs(int x){
	cmp[x]=++cnt,sz[x]=1;
	for(auto y:g[x])if(y!=f[x])dfs(y),sz[x]+=sz[y];
}
int d1[524388],d2[524388];
void pushdown(int id){
	if(d2[id]<2)return;
	d1[id<<1]=(ll)d1[id<<1]*d2[id]%MOD,d1[id<<1|1]=(ll)d1[id<<1|1]*d2[id]%MOD;
	d2[id<<1]=(ll)d2[id<<1]*d2[id]%MOD,d2[id<<1|1]=(ll)d2[id<<1|1]*d2[id]%MOD;
	d2[id]=1;
}
void upd(int l,int r,int id,int a,int b,int w1,int w2){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		d1[id]=(ll)(d1[id]+w1)*w2%MOD,d2[id]=(ll)d2[id]*w2%MOD;
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	upd(l,mid,id<<1,a,b,w1,w2),upd(mid+1,r,id<<1|1,a,b,w1,w2);
	d1[id]=(d1[id<<1]+d1[id<<1|1])%MOD;
}
int got(int l,int r,int id,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return d1[id];
	pushdown(id);
	int mid=(l+r)>>1;
	return (got(l,mid,id<<1,a,b)+got(mid+1,r,id<<1|1,a,b))%MOD;
}
int main(){
	fill(d2,d2+524370,1);
	scanf("%d%d",&w[1],&q);
	while(q--){
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt<2)scanf("%d",&y),++n,w[n]=y,g[x].push_back(n),f[n]=x;
		else qry[n].push_back(x); 
	}
	dfs(1);
	upd(1,n,1,1,1,w[1],1),s[1]=1;
	for(auto x:qry[1])printf("%d\n",w[1]);
	for(int i=2;i<=n;i++){
		int p=f[i];
		upd(1,n,1,cmp[p],cmp[p]+sz[p]-1,0,(ll)(s[p]+1)*mypow(s[p])%MOD);s[p]++,s[i]=1;
		upd(1,n,1,cmp[i],cmp[i],(ll)got(1,n,1,cmp[p],cmp[p])*mypow(w[p])%MOD*w[i]%MOD,1);
		for(auto x:qry[i]){
			int tmp=got(1,n,1,cmp[x],cmp[x]+sz[x]-1);
			if(x==1)printf("%d\n",tmp);
			else printf("%d\n",(ll)tmp*w[f[x]]%MOD*mypow(got(1,n,1,cmp[f[x]],cmp[f[x]]))%MOD);
		}
	}
}