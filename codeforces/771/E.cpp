//泥の分際で私だけの大切を奪おうだなん
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
map<pair<int,int>,int> f;
ll a[1<<19],b[1<<19],c[1<<19];
int ta[1<<19],tb[1<<19],tc[1<<19];
map<ll,int> la,lb,lc;
inline int dfs(int x,int y)
{
	if(f.count({x,y})) return f[{x,y}];
	int res=0;
	if(tc[min(x,y)]) res=dfs(tc[min(x,y)],tc[min(x,y)])+1;
	if(ta[x]>tb[y]&&ta[x]) res=max(res,dfs(ta[x],y)+1);
	else if(tb[y]) res=max(res,dfs(x,tb[y])+1);
	return f[{x,y}]=res;
}
signed main()
{
	int n=read()+1;
	for(int i=2; i<=n; ++i)
		a[i]=a[i-1]+read();
	for(int i=2; i<=n; ++i)
		b[i]=b[i-1]+read(),c[i]=a[i]+b[i];
	for(int i=1; i<=n; ++i)
		ta[i]=max(ta[i-1],la[a[i]]),la[a[i]]=i;
	for(int i=1; i<=n; ++i)
		tb[i]=max(tb[i-1],lb[b[i]]),lb[b[i]]=i;
	for(int i=1; i<=n; ++i)
		tc[i]=max(tc[i-1],lc[c[i]]),lc[c[i]]=i;
	printf("%d\n",dfs(n,n));
	return 0;
}
		 		  	  				 			    		 						