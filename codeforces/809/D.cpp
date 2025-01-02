// LUOGU_RID: 159963127
#include<bits/stdc++.h>
#define ls(u) t[u].ls
#define rs(u) t[u].rs
using namespace std;
const int N=3e5+5;
int n,root,cnt;
struct FHQ_Treap
{
	int ls,rs;
	int val,tag;
	int pri,siz;
}t[N<<1];
void update(int u)
{
	t[u].siz=t[ls(u)].siz+t[rs(u)].siz+1;
}
int newNode(int x)
{
	int u=++cnt;
	ls(u)=rs(u)=t[u].tag=0;
	t[u].val=x;
	t[u].pri=rand();
	t[u].siz=1;
	return u;
}
void add(int u,int k)
{
	t[u].tag+=k;
	t[u].val+=k;
}
void push_down(int u)
{
	if(!t[u].tag) return;
	if(ls(u)) add(ls(u),t[u].tag);
	if(rs(u)) add(rs(u),t[u].tag);
	t[u].tag=0;
}
void split(int u,int x,int &L,int &R)
{
	if(!u)
	{
		L=R=0;
		return;
	}
	push_down(u);
	if(t[u].val<=x)
	{
		L=u;
		split(rs(u),x,rs(u),R);
	}
	else
	{
		R=u;
		split(ls(u),x,L,ls(u));
	}
	update(u);
}
int merge(int L,int R)
{
	if(!L||!R) return L|R;
	if(t[L].pri>t[R].pri)
	{
		push_down(L);
		t[L].rs=merge(t[L].rs,R);
		update(L);
		return L;
	}
	else
	{
		push_down(R);
		t[R].ls=merge(L,t[R].ls);
		update(R);
		return R;
	}
}
void insert(int x)
{
	int L,R;
	split(root,x,L,R);
	root=merge(merge(L,newNode(x)),R);
}
void del(int x)
{
	int L,R,p;
	split(root,x,L,R);
	split(L,x-1,L,p);
	p=merge(ls(p),rs(p));
	root=merge(merge(L,p),R);
}
int kth(int u,int k)
{
	if(k==t[ls(u)].siz+1) return u;
	if(k<=t[ls(u)].siz) return kth(ls(u),k);
	if(k>t[ls(u)].siz) return kth(rs(u),k-t[ls(u)].siz-1);
}
int nxt(int x)
{
	int L,R;
	split(root,x,L,R);
	int ans=kth(R,1);
	root=merge(L,R);
	return ans;
}
void modify(int x,int y)
{
	int L,R,p;
	split(root,y,L,R);
	split(L,x-1,L,p);
	t[p].tag++,t[p].val++;
	root=merge(merge(L,p),R);
}
int main()
{
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(i==1)
		{
			insert(l);
			continue;
		}
		int Nxt=nxt(r-1);
		modify(l-1,r-1);
		if(Nxt) del(t[Nxt].val);
		insert(l);
	}
	printf("%d",t[root].siz);
	return 0;
}