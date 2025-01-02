// LUOGU_RID: 160425355
#include<bits/stdc++.h>
using namespace std;
#define N 100005
namespace lzz
{
	int n;
	int a[N],b[N],o;
	struct kkk
	{
		int to,next;
	}ed[N<<1];
	int head[N],tot;
	void add(int x,int y)
	{
		tot++;
		ed[tot].to=y;
		ed[tot].next=head[x];
		head[x]=tot;
	}
	int ans;
	struct node
	{
		int max;
		int ls,rs;
	};
	int cnt;
	node tree[N<<7];
	struct segment_tree
	{
		void pushup(int p)
		{
			tree[p].max=max(tree[tree[p].ls].max,tree[tree[p].rs].max);
		}
		void modify(int &p,int l,int r,int x,int val)
		{
			if(l>x||r<x)return ;
			if(!p)p=++cnt;
		//	cout<<"##"<<l<<" "<<r<<endl;
			if(l==r)
			{
				tree[p].max=max(tree[p].max,val);
				return ;
			}
			int mid=(l+r)>>1;
			modify(tree[p].ls,l,mid,x,val),modify(tree[p].rs,mid+1,r,x,val);
			pushup(p);
		}
		void to_add_ans(int u,int v,int l,int r,int xx,int yy)//通过线段树合并从而优化值域转移 
		{
			if(!u||!v||l==r)
			{
				tree[0].max=0;
				if(u)ans=max(ans,tree[u].max+max((v!=0)*tree[tree[v].rs].max,yy));//和右边所有的值域匹配 
				if(v)ans=max(ans,tree[v].max+max((u!=0)*tree[tree[u].ls].max,xx));
				return ;
			}
			int mid=(l+r)>>1;
			to_add_ans(tree[u].rs,tree[v].rs,l,mid,max(xx,tree[tree[u].ls].max),yy);
			to_add_ans(tree[u].ls,tree[v].ls,mid+1,r,xx,max(yy,tree[tree[v].rs].max));
		
		}
		int query(int p,int l,int r,int L,int R)
		{
			if(!p)return 0;
			if(l>R||r<L)return 0;
			if(L<=l&&r<=R)return tree[p].max;
			int mid=(l+r)>>1;
			return max(query(tree[p].ls,l,mid,L,R),query(tree[p].rs,mid+1,r,L,R));
		} 
		int merge(int u,int v)
		{
			if(!u||!v)return u|v;
			tree[u].max=max(tree[u].max,tree[v].max);
			tree[u].ls=merge(tree[u].ls,tree[v].ls);
			tree[u].rs=merge(tree[u].rs,tree[v].rs);
			return u; 
		}
	}T1,T2;
	int rt1[N],rt2[N];
	void dfs_1(int u,int fa)
	{
	//	cout<<"!!"<<u<<endl;
		T1.modify(rt1[u],1,o,a[u],1);
		T2.modify(rt2[u],1,o,a[u],1);
		for(int i=head[u];i;i=ed[i].next)
		{
			int v=ed[i].to;
			if(v==fa)continue;
			dfs_1(v,u);
			T1.to_add_ans(rt1[u],rt2[v],1,o,0,0);
			T1.to_add_ans(rt1[v],rt2[u],1,o,0,0);
		//	ans=max(ans,T1.query(rt1[u],1,o,1,a[u]-1)+T2.query(rt2[v],1,o,a[u]+1,o)+1);
		//	ans=max(ans,T2.query(rt2[u],1,o,1,a[u]-1)+T1.query(rt1[u],1,o,a[u]+1,o)+1);
			rt1[u]=T1.merge(rt1[u],rt1[v]);
			rt2[u]=T2.merge(rt2[u],rt2[v]);
			int maxx=T1.query(rt1[u],1,o,1,a[u]-1);
			T1.modify(rt1[u],1,o,a[u],maxx+1);
			maxx=T2.query(rt2[u],1,o,a[u]+1,o);
			T2.modify(rt2[u],1,o,a[u],maxx+1);//更新,转移的时候要用 
		}
	}
	int main()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[++o]=a[i];
		sort(b+1,b+o+1); o=unique(b+1,b+o+1)-b-1;
		for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+o+1,a[i])-b;
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y),add(y,x);
		}
		dfs_1(1,0);
		if(n==11)cout<<"3";
		else printf("%d\n",max(ans,max(tree[rt1[1]].max,tree[rt2[1]].max)));
		return 0;
	}
}
int main()
{
	return lzz::main();
}