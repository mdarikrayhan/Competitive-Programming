// LUOGU_RID: 158454013
//#pragma GCC optimize(2)//O2,洛谷要关
#include <iostream>

#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#define str string
#define ll long long
#define pii pair<int,int>
#define uin unsigned int
#define db double
using namespace std;
const int N=5005,Q=1e5+10;
int n,q;
int ans[Q];
struct node{
	int l,r;
	int num;
}tree[Q*100];
int cnt=2;
struct seg{
	void add(int addl,int addr,int num,int l,int r,int p){
		if(l>=addl&&r<=addr)
		{
			tree[p].num+=num;
			return;
		}
		int mid=(l+r)/2;
		if(mid>=addl)
		{
			if(!tree[p].l)tree[p].l=++cnt;
			add(addl,addr,num,l,mid,tree[p].l);
		}
		if(mid<addr)
		{
			if(!tree[p].r)tree[p].r=++cnt;
			add(addl,addr,num,mid+1,r,tree[p].r);
		}
	}
	int find(int pos,int l,int r,int p){
		if(!p)return 0;
		if(l==r)
		{
			return tree[p].num;
		}
		int mid=(l+r)/2;
		int res=tree[p].num;
		if(mid>=pos)
		{
			res+=find(pos,l,mid,tree[p].l);
		}
		if(mid<pos)
		{
			res+=find(pos,mid+1,r,tree[p].r);
		}
		return res;
	}
}t1,t2;//x+y,x-y+N
struct dim{
	seg tree[N*2];
	int root[N*2];
	int lowbit(int x){
		return x&-x;
	}
	void w(int x,int l,int r,int num){
		for(;x<=n*2;x+=lowbit(x))
		{
			if(!root[x])root[x]=++cnt;
			tree[x].add(l,r,num,1,n,root[x]);
		}
	}
	void add(int l,int r,int x,int y){
		w(l,x,y,1);
		w(r+1,x,y,-1);
	}
	int find(int x,int y){
		int res=0;
		for(;x;x-=lowbit(x))
		{
			if(!root[x])continue;
			res+=tree[x].find(y,1,n,root[x]);
		}
		return res;
	}
}l1,l2,l3,l4;//x+y,x	x+y,y	x-y+N,x		x-y+N,y

int main()
{
//	freopen("in.in","r",stdin);
//	freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);
	//
	cin>>n>>q;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int dir,x,y,len;
			cin>>dir>>x>>y>>len;
			if(dir==1)
			{
				t1.add(x+y,x+y+len,-1,1,n*2,1);
				l1.add(x+y,x+y+len,x,n);
				l2.add(x+y,x+y+len,y,n);
			}
			if(dir==2)
			{
				t2.add(x-y+n,x+len-y+n,-1,1,n*2,2);
				l3.add(x-y+n,x+len-y+n,x,n);
				l4.add(x-y+n,x+len-y+n,1,y);
			}
			if(dir==3)
			{
				t2.add(x-y+n-len,x-y+n,-1,1,n*2,2);
				l3.add(x-y+n-len,x-y+n,1,x);
				l4.add(x-y+n-len,x-y+n,y,n);
			}
			if(dir==4)
			{
				t1.add(x+y-len,x+y,-1,1,n*2,1);
				l1.add(x+y-len,x+y,1,x);
				l2.add(x+y-len,x+y,1,y);
			}
		}
		if(op==2)
		{
			int x,y;
			cin>>x>>y;
			int num=l1.find(x+y,x)+l2.find(x+y,y)+l3.find(x-y+n,x)+l4.find(x-y+n,y);
			int res=t1.find(x+y,1,n*2,1)+t2.find(x-y+n,1,n*2,2);
			cout<<num+res<<'\n';
		}
	}
    return 0;
}
/*
17 6
1 1 3 2 4
1 3 10 3 7
1 2 6 8 2
1 3 9 4 2
1 4 15 10 6
2 7 7


*/
