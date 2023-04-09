#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=5e6;
int n,m,a[N];
bool bl[M+5];
int phi[M+5];
vector<int>pri;
inline void pre(){
	bl[1]=phi[1]=1;
	for(int i=2;i<=M;++i){
		if(!bl[i])pri.push_back(i),phi[i]=i-1;
		for(int j:pri){
			if(1ll*i*j>M)break;
			bl[i*j]=true;
			if(i%j==0){phi[i*j]=phi[i]*j;break;}
			phi[i*j]=phi[i]*phi[j];
		}
	}
}
namespace sgt{
	struct tree{int l,r,tag,a,v,s,ans;}t[N*4];
	#define lt p<<1
	#define rt p<<1|1
	void merge(tree x,tree y,tree &res){
		if(!x.a)return res=y,void();
		if(!y.a)return res=x,void();
		res.a=0,res.s=x.s+y.s,res.ans=x.ans+y.ans;
		if(x.a==y.a)res.a=x.a;
		else res.a=-1;
		while(x.v!=y.v){
			if(x.v>y.v)x.v=phi[x.v],res.ans+=x.s;
			else y.v=phi[y.v],res.ans+=y.s;
		}res.v=x.v;
	}
	void updata(int p,int d){t[p].a=t[p].v=d,t[p].ans=0,t[p].tag=d;}
	void pushdown(int p){if(t[p].tag)updata(lt,t[p].tag),updata(rt,t[p].tag),t[p].tag=0;}
	void build(int p,int l,int r){
		t[p]=(tree){l,r,0,0,0,0,0};
		if(l==r)return t[p].v=t[p].a=a[l],t[p].ans=0,t[p].s=1,void();
		int mid=(l+r)>>1;
		build(lt,l,mid),build(rt,mid+1,r),merge(t[lt],t[rt],t[p]);
	}
	void change(int p,int l,int r){
		if(l<=t[p].l&&t[p].r<=r&&t[p].a!=-1)return updata(p,phi[t[p].a]);
		int mid=(t[p].l+t[p].r)>>1;pushdown(p);
		if(l<=mid)change(lt,l,r);
		if(r>mid)change(rt,l,r);
		merge(t[lt],t[rt],t[p]);
	}
	tree ask(int p,int l,int r){
		if(l<=t[p].l&&t[p].r<=r)return t[p];
		int mid=(t[p].l+t[p].r)>>1;pushdown(p);
		tree res=(tree){0,0,0,0,0,0,0};
		if(l<=mid)merge(res,ask(lt,l,r),res);
		if(r>mid)merge(res,ask(rt,l,r),res);
		return res;
	}
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	pre();
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sgt::build(1,1,n);
	while(m--){
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1)sgt::change(1,l,r);
		else cout<<sgt::ask(1,l,r).ans<<"\n";
	}
	return 0;
}