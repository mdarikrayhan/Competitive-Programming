// LUOGU_RID: 159757422
#include <bits/stdc++.h>
using namespace std;

template<typename T> inline void read(T &x)
{
	x = 0;
	T f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f = -1,ch = getchar();
			break;
		}
		ch = getchar();
	}
	while(ch>='0'&&ch<='9')
		x = (x<<3)+(x<<1)+ch-48,ch = getchar();
	x*=f;
}
template<typename T = int> inline T read()
{
	T x;read(x);return x;
}
template<typename T> void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+48);
}
template<typename T> inline void writen(T x)
{
    write(x);
    putchar(10);
}
const int N = 2e5+5,V = 32;
struct base{
	int h[V];
	inline void insert(int x)
	{
		for(int i = V-1;~i;i--)
			if((x>>i)&1)
			{
				if(!h[i]) return h[i] = x,void();
				x^=h[i];
			}
	}
	inline int ask()
	{
		int res = 0;
		for(int i = V-1;~i;i--)
			res+=(h[i]>0);
		return (1<<res);
	}
	inline friend base operator + (base x,base y)
	{
		base res;
		for(int i = 0;i<V;i++) res.h[i] = 0;
		for(int i = 0;i<V;i++)
			if(x.h[i]) res.insert(x.h[i]);
		for(int i = 0;i<V;i++)
			if(y.h[i]) res.insert(y.h[i]);
		return res;
	}
}u;
struct node{
	int val,tag;base b;
}t[N<<2];
int n,m,a[N];
#define ls (k<<1)
#define rs (k<<1|1)
inline void pushup(int k){t[k].b = t[ls].b+t[rs].b;}
inline void Xor(int k,int v){t[k].tag^=v,t[k].val^=v;}
inline void down(int k)
{
	if(!t[k].tag) return;
	Xor(ls,t[k].tag),Xor(rs,t[k].tag);
	t[k].tag = 0;
}
void build(int k,int l,int r)
{
	if(l==r) return t[k].b.insert(a[l]^a[l-1]),t[k].val = a[l],void();
	int mid = (l+r)/2;
	build(ls,l,mid),build(rs,mid+1,r);
	pushup(k);
}
void change1(int k,int l,int r,int x,int y,int v)
{
	if(l>y||r<x) return;
	if(l>=x&&r<=y) return Xor(k,v);
	int mid = (l+r)/2;
	down(k);
	change1(ls,l,mid,x,y,v),change1(rs,mid+1,r,x,y,v);
	pushup(k); 
}
void change2(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		int pre = 0;
		for(int i = 0;i<V;i++) if(t[k].b.h[i]) pre = t[k].b.h[i];
		t[k].b = u,t[k].b.insert(v^pre);
		return;
	}
	int mid = (l+r)/2;
	down(k);
	if(mid>=x) change2(ls,l,mid,x,v);
	else change2(rs,mid+1,r,x,v);
	pushup(k);
}
base ask1(int k,int l,int r,int x,int y)
{
	if(l>y||r<x) return u;
	if(l>=x&&r<=y) return t[k].b;
	int mid = (l+r)/2;
	down(k);
	return ask1(ls,l,mid,x,y)+ask1(rs,mid+1,r,x,y);
}
int ask2(int k,int l,int r,int x)
{
	if(l==r) return t[k].val;
	int mid = (l+r)/2;
	down(k);
	if(mid>=x) return ask2(ls,l,mid,x);
	else return ask2(rs,mid+1,r,x);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(m);
	for(int i = 1;i<=n;i++)
		read(a[i]);
	build(1,1,n);
	while(m--)
	{
		int op,l,r,v;
		read(op),read(l),read(r);
//		cout<<ask2(1,1,n,2)<<'\n';
		if(op==1)
		{
			read(v);
			change1(1,1,n,l,r,v);
			change2(1,1,n,l,v);
			if(r<n) change2(1,1,n,r+1,v);
		}
		else
		{
			base res = ask1(1,1,n,l+1,r);
			res.insert(ask2(1,1,n,l));
			writen(res.ask());
		}
	}
	return 0;
}
