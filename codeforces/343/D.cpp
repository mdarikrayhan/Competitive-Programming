// LUOGU_RID: 159906112
#include<bits/stdc++.h>
using namespace std;

int n,m,r,p,v[500005],a,b,s[500005],d[500005],son[500005],fa[500005],t[500005],ind,id[500005],rid[500005],tag[2000005],tr[2000005],op,x,y,z;
vector<int> mp[500005];

void dfs1(int x,int f)
{
	fa[x]=f;
	s[x]=1;
	d[x]=d[f]+1;
	for(int i=0;i<mp[x].size();i++)
	{
		if(mp[x][i]==f)continue;
		dfs1(mp[x][i],x);
		s[x]+=s[mp[x][i]];
		if(!son[x]||s[son[x]]<s[mp[x][i]])son[x]=mp[x][i]; 
	}
}

void dfs2(int x,int top)
{
	t[x]=top;
	id[x]=++ind;
	rid[ind]=x;
	if(son[x])dfs2(son[x],top);
	for(int i=0;i<mp[x].size();i++)
	{
		if(mp[x][i]==fa[x]||mp[x][i]==son[x])continue;
		dfs2(mp[x][i],mp[x][i]);
	}
}

int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}

void push_up(int x){tr[x]=(tr[ls(x)]+tr[rs(x)]);}

void add_tag(int n,int l,int r,int x)
{
	tag[n]=x;
	tr[n]=(r-l+1)*x;
}

void push_down(int n,int l,int r)
{
	if(tag[n]!=-1)
	{
		int mid=(l+r)>>1;
		add_tag(ls(n),l,mid,tag[n]);
		add_tag(rs(n),mid+1,r,tag[n]);
		tag[n]=-1;
	}
}

void build(int n,int l,int r)
{
    tag[n]=-1;
	if(l==r)
	{
		tr[n]=v[rid[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(n),l,mid);
	build(rs(n),mid+1,r);
	push_up(n);
}

void change(int n,int L,int R,int l,int r,int x)
{
	if(L<=l&&r<=R)
	{
		add_tag(n,l,r,x);
		return;
	}
	push_down(n,l,r);
	int mid=(l+r)>>1;
	if(mid>=L)change(ls(n),L,R,l,mid,x);
	if(mid+1<=R)change(rs(n),L,R,mid+1,r,x);
	push_up(n);
}

int query(int n,int L,int R,int l,int r)
{
	if(L<=l&&r<=R)return tr[n];
	push_down(n,l,r);
	int mid=(l+r)>>1,ans=0;
	if(mid>=L)ans=(ans+query(ls(n),L,R,l,mid));
	if(mid+1<=R)ans=(ans+query(rs(n),L,R,mid+1,r));
	return ans;
}

void road_change(int x,int y,int z)
{
	while(t[x]!=t[y])
	{
		if(d[t[x]]<d[t[y]])swap(x,y);
		change(1,id[t[x]],id[x],1,n,z);
		x=fa[t[x]];
	}
	if(d[x]<d[y])swap(x,y);
	change(1,id[y],id[x],1,n,z);
}

int road_query(int x,int y)
{
	int ans=0;
	while(t[x]!=t[y])
	{
		if(d[t[x]]<d[t[y]])swap(x,y);
		ans=(ans+query(1,id[t[x]],id[x],1,n));
		x=fa[t[x]];
	}
	if(d[x]<d[y])swap(x,y);
	ans=(ans+query(1,id[y],id[x],1,n));
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&a);
            change(1,id[a],id[a]+s[a]-1,1,n,1);
        }
        else if(op==2)
        {
            scanf("%d",&a);
            road_change(a,1,0);
        }
        else
        {
            scanf("%d",&a);
            printf("%d\n",road_query(a,a));
        }
    }
	return 0;
}