#include <bits/stdc++.h>

#define N 1005
#define fi first
#define se second

using namespace std;

int a[N],p[N*10];
vector<pair<int,int>>ans;

void calc(int x,int y,int z)
{
	for(;;)
	{
		if(a[x]>a[y])swap(x,y);
		if(a[y]>a[z])swap(y,z);
		if(a[x]>a[y])swap(x,y);
		if(a[x]==0)break;
		while(a[x]<=a[y])
		{
			if((a[y]/a[x])&1){ans.push_back({x,y});a[y]-=a[x];a[x]*=2;}
			else{ans.push_back({x,z});a[z]-=a[x];a[x]*=2;}
		}
	}
}

int main()
{
	int i,n,hd=1,tl=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]!=0)p[++tl]=i;
	}
	if(tl==0||tl==1)return puts("-1"),0;
	while(hd+2<=tl)
	{
		calc(p[hd],p[hd+1],p[hd+2]);
		if(a[p[hd]]!=0)p[++tl]=p[hd];
		if(a[p[hd+1]]!=0)p[++tl]=p[hd+1];
		if(a[p[hd+2]]!=0)p[++tl]=p[hd+2];
		hd+=3;
	}
	printf("%ld\n",ans.size());
	for(auto t:ans)printf("%d %d\n",t.fi,t.se);
	return 0;
}