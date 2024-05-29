#include<bits/stdc++.h>
#define double long double
using namespace std;
int n,top,st[1000005];double h,x,y,ans;
struct node{double x1,x2,k,b;}v[3005];
double calc(int j,int i)
{
	double p=v[j].b;
	if(x>=v[j].x2)p=max(p,v[j].b+v[j].k*(v[j].x2-v[j].x1));
	else if(x>=v[j].x1)p=max(p,v[j].b+v[j].k*(x-v[j].x1));
	if(v[i].k>=v[j].k)
	{
		if(v[j].x1<=v[i].x1&&v[i].x1<=v[j].x2)p=max(p,v[j].b+v[j].k*(v[i].x1-v[j].x1));
		if(v[i].x1<=v[j].x1&&v[j].x1<=v[i].x2)p=max(p,v[j].b-v[i].k*(v[j].x1-v[i].x1));
	}
	else 
	{
		if(v[j].x1<=v[i].x2&&v[i].x2<=v[j].x2)p=max(p,v[j].b+v[j].k*(v[i].x2-v[j].x1)-v[i].k*(v[i].x2-v[i].x1));
		if(v[i].x1<=v[j].x2&&v[j].x2<=v[i].x2)p=max(p,v[j].b+v[j].k*(v[j].x2-v[j].x1)-v[i].k*(v[j].x2-v[i].x1));
	}
	v[i].b=max(v[i].b,p);
	return p;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	double mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>h>>x>>y;x/=2;y/=2;
		v[i]={x,y,h/(y-x),mx};
		while(top&&calc(st[top],i)+h>=v[st[top]].b+v[st[top]].k*(v[st[top]].x2-v[st[top]].x1))top--;
		st[++top]=i;
		ans=max(ans,v[i].b+v[i].k*(v[i].x2-v[i].x1));
	}
	cout<<fixed<<setprecision(8)<<ans;
	return 0;
}
