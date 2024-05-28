// LUOGU_RID: 160584442
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rpe(i,x) for(int i=_he[x];i;i=_ne[i])
#define lb(x) (x&(-x))
using namespace std;
typedef long long LL;
const int N=4e5+10;

int n,a[N],f[N],m,rt;

namespace T{
	int dat[N*65],ls[N*65],rs[N*65],node;
	void mdf(int &p,int l,int r,int pos,int v)
	{
		if(!p)p=++node,dat[p]=0;
		if(l==r)return dat[p]=max(dat[p],v),void();
		int mid=(l+r)>>1;
		pos<=mid?mdf(ls[p],l,mid,pos,v):mdf(rs[p],mid+1,r,pos,v);
		dat[p]=max(dat[ls[p]],dat[rs[p]]);
	}
	int ask(int p,int l,int r,int tl,int tr)
	{
		if(!p||p>node||(l>=tl&&r<=tr))return dat[p];
		int mid=(l+r)>>1,res=0;
		if(tl<=mid)res=ask(ls[p],l,mid,tl,tr);
		if(tr>mid)res=max(res,ask(rs[p],mid+1,r,tl,tr));
		return res;
	}
}

void add(int x,int v){T::mdf(rt,-m,m,x,v);}
int ask(int x){return T::ask(rt,-m,m,x,m);}
int ask2(int x){return T::ask(rt,-m,m,-m,x);}

int main()
{
	scanf("%d",&n); 
	rep(i,1,n)scanf("%d",&a[i]),m=max(m,a[i]);
	m+=n;
	int ans=0;
	per(i,n,2)f[i]=ask(a[i]-i)+1,add(a[i]-i,f[i]),ans=max(ans,f[i]);
	
	rep(i,1,T::node)T::dat[i]=T::ls[i]=T::rs[i]=0;
	T::node=0,rt=0;
	rep(i,1,n)
	{
		if(i-1>0)
		{
			int v=ask2(a[i-1]-(i-1))+1;
			add(a[i-1]-(i-1),v);
			ans=max(ans,v);
		}
		if(i<n)ans=max(ans,f[i+1]+ask2(a[i+1]-i));
	}
	printf("%d\n",n-1-ans);
	return 0;
}