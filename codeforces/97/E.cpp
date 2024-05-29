// LUOGU_RID: 130578539
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define g(i,j,k) for(int i=j;i>=k;--i)
int n,m,s,l;
const int N=101010;
vector<int>q[N];
int dfn[N],low[N],ic[N],sk[N],st[N],op[N],fa[N],b[N],c[N],d[N];
int fifa(int x){return x==fa[x]?x:fa[x]=fifa(fa[x]);}
void tj(int x,int id){
	int z;sk[st[++s]=x]=id;
	dfn[x]=low[x]=++l;
	for(int y:q[x]){
		if(!dfn[y]){
			c[y]=!c[x];
			tj(y,id);z++;
			low[x]=min(low[x],low[y]);
			if(dfn[x]<=low[y]){
				ic[x]=1;z=0;
				vector<int>a;
				while(st[s+1]!=y)a.push_back(st[s--]);
				for(int i:a)z|=b[i];
				a.push_back(x); 
				if(z)for(int i:a)ic[i]?fa[fifa(i)]=x:d[i]=-1;
			}
		}else{
			if(c[x]==c[y])dfn[x]>dfn[y]?b[x]=1:b[y]=1;
			low[x]=min(low[x],dfn[y]);
		}
	}
}
void sep(int x,int id){
	if(d[x])return;d[x]=id;
	for(int y:q[x])if(fifa(x)!=fifa(y))sep(y,id);
}
signed main(){
	cin>>n>>m;
	f(i,1,m){
		scanf("%lld %lld",&s,&l);
		q[s].push_back(l);
		q[l].push_back(s);
	}
	s=l=0;
	f(i,1,n)fa[i]=i;
	f(i,1,n)if(!dfn[i])tj(i,i);
	f(i,1,n)if(!d[i])sep(i,i);
	cin>>m;
	f(i,1,m){
		scanf("%lld %lld",&s,&l);
		if(sk[s]!=sk[l]||s==l)printf("No\n");
		else if(d[s]==d[l]&&d[s]>0&&c[s]==c[l])printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}