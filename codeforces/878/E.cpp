// LUOGU_RID: 159968666
#include<iostream>
using namespace std;
const int mod=1e9+7;
inline int min(const int x,long long y)
{
	return x<y?x:y;
}
struct tree
{
	int lim,k1,b1,X1,K1,x2,y2,X2;
};
tree a[400000];
int n,q,A[100010];
pair<pair<int,int>,int> query(int L,int R,int x,int X,int p)
{
	if(L==R)
	{
		int y=0;
		x=(mod+A[L]+2ll*x)%mod;
		X=min(mod,A[L]+2ll*X);
		if(X<=0)
		{
			y=(mod+X)%mod;
			x=X=0;
		}
		return {{x,y},X};
	}
	int mid=L+R>>1,l=p<<1,r=(p<<1)|1;
	if(X>=a[r].lim)
	{
		auto t=query(L,mid,((long long)a[r].k1*x+a[r].b1)%mod,
		min(mod,a[r].X1+(long long)(X-a[r].lim)*a[r].K1),l);
		return t;
	}
	auto t=query(mid+1,R,x,X,r);
	t.first.first=a[p].x2;
	t.first.second=(t.first.second+a[p].y2)%mod;
	t.second=a[p].X2;
	return t;
}
inline void update(int L,int R,int p)
{
	int mid=L+R>>1,l=p<<1,r=(p<<1)|1;
	a[p].lim=a[r].lim+max(0,a[l].lim-a[r].X1+a[r].K1-1)/a[r].K1;
	a[p].k1=(long long)a[l].k1*a[r].k1%mod;
	a[p].b1=((long long)a[l].k1*a[r].b1+a[l].b1)%mod;
	a[p].X1=min(mod,a[l].X1+(long long)
	(a[r].X1+(a[p].lim-a[r].lim)*a[r].K1-a[l].lim)*a[l].K1);
	a[p].K1=min(mod,(long long)a[l].K1*a[r].K1);
	auto tr=query(mid+1,R,a[r].lim-1,a[r].lim-1,r);
	auto t=query(L,mid,tr.first.first,tr.second,l);
	a[p].x2=t.first.first,a[p].y2=t.first.second,a[p].X2=t.second;
}
inline void init(int x,int p)
{
	if(A[x]>0)
	{
		a[p].lim=0;
		a[p].k1=2,a[p].b1=A[x];
		a[p].X1=A[x],a[p].K1=2;
	}
	else
	{
		a[p].lim=(-A[x]+2)>>1;
		a[p].k1=2,a[p].b1=(mod+A[x])%mod;
		a[p].X1=2-(-A[x]&1),a[p].K1=2;
	}
}
void build(int l,int r,int p)
{
	if(l==r)
	{
		init(l,p);
		return;
	}
	int mid=l+r>>1;
	build(l,mid,p<<1);
	build(mid+1,r,(p<<1)|1);
	update(l,r,p);
}
void query(int l,int r,int ll,int rr,int &x,int &y,int &X,int p)
{
	if(r<ll||l>rr)
	{
		return;
	}
	if(ll<=l&&r<=rr)
	{
		auto t=query(l,r,x,X,p);
		x=t.first.first;
		y=(y+t.first.second)%mod;
		X=t.second;
		return;
	}
	int mid=l+r>>1;
	query(mid+1,r,ll,rr,x,y,X,(p<<1)|1);
	query(l,mid,ll,rr,x,y,X,p<<1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	build(1,n,1);
	while(q--)
	{
		int l,r,x=0,y=0,X=0;
		cin>>l>>r;
		query(1,n,l+1,r,x,y,X,1);
		cout<<(mod+A[l]+2ll*(x+y))%mod<<'\n';
	}
	return 0;
}