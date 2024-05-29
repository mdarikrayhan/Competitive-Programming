// LUOGU_RID: 111643484
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
const int MxN=200002;
int n,m;
int p[MxN],X[MxN],t[MxN],id[MxN],dep[MxN],y[MxN],val[MxN],fa[MxN];
int son[MxN][2];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return t[x]+dep[X[x]]==t[y]+dep[X[y]]? X[x]<X[y]:t[x]+dep[X[x]]<t[y]+dep[X[y]];
}
inline bool IsRoot(int x)
{
	return !x || (x!=son[fa[x]][0] && x!=son[fa[x]][1]);
}
inline bool Get(int x)
{
	return x==son[fa[x]][1];
}
inline void PushDown(int x)
{
	if(x)val[son[x][0]]=val[son[x][1]]=val[x];
}
inline void Update(int x)
{
	if(!IsRoot(x))Update(fa[x]);
	PushDown(x);
}
inline void Rotate(int x)
{
	int y=fa[x],gx=Get(x),gy=Get(y),z=son[x][gx^1],w=fa[y];
	if(!IsRoot(y))son[w][gy]=x;
	fa[x]=w,fa[y]=x,son[x][gx^1]=y,fa[z]=y,son[y][gx]=z;
}
inline void Splay(int x)
{
	for(Update(x);!IsRoot(x);Rotate(x))if(!IsRoot(fa[x]))Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)read(p[i]),dep[i]=dep[p[i]]+1,val[i]=-inf,fa[i]=p[i];
	for(int i=1;i<=m;++i)read(X[i]),read(t[i]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	for(int i=1,x;i<=m;++i)
	{
		x=0;
		for(int j=X[id[i]];j;son[j][1]=x,j=fa[x=j])
		{
			Splay(j);
			if(val[j]+2*dep[j]>t[id[i]]+dep[X[id[i]]])
			{
				y[id[i]]=j;
				break;
			}
		}
		if(x)val[x]=t[id[i]]+dep[X[id[i]]]-2*dep[y[id[i]]];
	}
	for(int i=1;i<=m;++i)printf("%d\n",t[i]+2*(dep[X[i]]-dep[y[i]]));
	return 0;
}