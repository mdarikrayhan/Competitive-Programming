// LUOGU_RID: 160034252
#include <bits/stdc++.h>
#define int long long
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
const int N = 1e5+5;
int n,m;
struct A{
	int sz,ans,sum,sum_,lt;
	inline friend A operator + (A x,A y)
	{
		A res;
		res.sz = x.sz+y.sz;
		res.ans = x.ans+y.ans+(y.lt*x.sz-x.sum)*y.sz+y.sum_*x.sz;
		res.sum = x.sum+y.sum;
		res.sum_ = x.sum_+(y.lt-x.lt)*y.sz+y.sum_;
		res.lt = x.lt;
		return res;
	}
};
inline A init(int x){return (A){1,0,x,0,x};}
struct node{
	int ls,rs,key,val;
	A a;
}t[N];
int mp[N],cnt;
inline int make(int v,int id)
{
	++cnt;
	mp[id] = cnt;
	t[cnt].key = rand();
	t[cnt].val = v;
	t[cnt].a = init(v);
	return cnt;
}
inline void pushup(int k)
{
	t[k].a = init(t[k].val);
	if(t[k].ls) t[k].a = t[t[k].ls].a+t[k].a;
	if(t[k].rs) t[k].a = t[k].a+t[t[k].rs].a;
}
void split(int k,int v,int &x,int &y)
{
	if(!k) return x = y = 0,void();
	if(t[k].val<=v) x = k,split(t[k].rs,v,t[k].rs,y);
	else y = k,split(t[k].ls,v,x,t[k].ls);
	pushup(k);
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	if(t[x].key<t[y].key)
	{
		t[x].rs = merge(t[x].rs,y),pushup(x);
		return x;
	}
	else
	{
		t[y].ls = merge(x,t[y].ls),pushup(y);
		return y;
	}
}
int rt,x,y,z;
inline void change(int x,int v)
{
	if(!v) return;
	int k = mp[x],vp = t[k].val;
	split(rt,vp-1,x,y);
	split(y,vp,y,z);
	rt = merge(x,z);
	split(rt,vp+v,x,y);
	t[k].val+=v,t[k].a = init(t[k].val);
	rt = merge(x,merge(k,y));
}
inline int ask(int l,int r)
{
	split(rt,l-1,x,y);
	split(y,r,y,z);
	int res = t[y].a.ans;
	rt = merge(merge(x,y),z);
	return res;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);
	srand(114514);
//	A a = init(1);
//	a = a+(init(2)+init(3));
//	cout<<a.ans;
	for(int i = 1,v;i<=n;i++)
	{
		read(v);
//		rt = merge(rt,make(v,i));
		split(rt,v,x,y);
		rt = merge(x,merge(make(v,i),y));
	}
// 	cout<<t[rt].a.ans;
	read(m);
	while(m--)
	{
		int op,x,y;
		read(op),read(x),read(y);
		if(op==1) change(x,y);
		else writen(ask(x,y));
	}
	return 0;
}
