#include<bits/stdc++.h>
using namespace std;
 
int n,d,m0,m1,sta[200004],sz;
bool a[200004],b[200004];
vector<int>g[200004];
int cnt;
 
void dfs(int x,int fa)
{
sta[++sz]=x;
if(a[x]&&sz>d)b[sta[sz-d]]=1;
if(b[x]&&sz>d)a[sta[sz-d]]=1;
for(auto y:g[x])if(y!=fa)
dfs(y,x),a[x]|=a[y],b[x]|=b[y];
cnt+=a[x],cnt+=b[x],--sz;
}
 
main()
{
scanf("%d%d",&n,&d);
for(int i=1;i<n;i++){
int u,v;scanf("%d%d",&u,&v);
g[u].push_back(v),g[v].push_back(u);
}
a[1]=b[1]=1;
scanf("%d",&m0);
while(m0--){int x;scanf("%d",&x);a[x]=1;}
scanf("%d",&m1);
while(m1--){int x;scanf("%d",&x);b[x]=1;}
cnt=0,dfs(1,0);
printf("%d\n",cnt*2-4);
}
		  		 		  	   	 			  		  		 	