#include <bits/stdc++.h>

#define N 100005

using namespace std;

int a[N],p[N],c[N];

struct seg
{
	int l,r,id;
	bool operator<(const seg b)const
	{
		if(l!=b.l)return l<b.l;
		if(r!=b.r)return r<b.r;
		return id<b.id;
	}
};

set<seg>st;

void dfs(int u)
{
	if(c[u]!=-1)return;
	dfs(p[u]);c[u]=c[p[u]]^1;
}

int main()
{
	int i,n,l,r;
	scanf("%d",&n);
	memset(c,-1,sizeof(c));
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&l,&r);
		st.insert({l*=2,r*=2,i});
	}
	while(!st.empty())
	{
		if(st.size()==1){c[st.begin()->id]=0;break;}
		auto A=*st.begin();st.erase(st.begin());
		auto B=*st.begin();st.erase(st.begin());
		if(A.r<B.r)
		{
			st.insert({A.r+1,B.r,B.id});
			p[A.id]=B.id;
		}
		else if(A.r>B.r)
		{
			st.insert({B.r+1,A.r,A.id});
			p[B.id]=A.id;
		}
		else
		{
			c[A.id]=0;c[B.id]=1;
		}
	}
	for(i=1;i<=n;++i)dfs(i);
	for(i=1;i<=n;++i)printf("%d ",c[i]);
	return 0;
}
