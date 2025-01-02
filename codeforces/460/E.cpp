#include<bits/stdc++.h>
#define rs register
#define MAX 3605
using namespace std;
struct Point{
	int x;
	int y;
}point[MAX];
int n,r,tot,m,top,ans;
int arr[10],s[10];
 int dist(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool cmp(Point a,Point b){
	return dist(a,{0,0})>dist(b,{0,0});
}
 void init(){
	scanf("%d%d",&n,&r);
	for(rs int i=-r;i<=r;++i)
		for(rs int j=-r;j<=r;++j)
			if(dist({i,j},{0,0})<=r*r)
				point[++tot]={i,j};
	sort(point+1,point+tot+1,cmp);
	m=min(18,tot);
}
 void solve(int k,int usd,int sum){
	if(usd==n)
	{
		if(sum>ans)
		{
			ans=sum;
			for(int i=1;i<=n;++i) arr[i]=s[i];
		}
		return ;
	}
	usd++;
	for(rs int i=k;i<=m;i++)
	{
		s[usd]=i;
		int tov=0;
		for(rs int j=1;j<usd;++j)
			tov+=dist(point[s[usd]],point[s[j]]);
		solve(i,usd,sum+tov);
	}
}
int main(){
	init();
	solve(1,0,0);
	printf("%d\n",ans);
	for(rs int i=1;i<=n;++i)
	{
		printf("%d %d\n",point[arr[i]].x,point[arr[i]].y);
	}
	return 0;
}