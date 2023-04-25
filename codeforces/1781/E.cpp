#include <bits/stdc++.h>
using namespace std;
int T,n,ans;
struct xx
{
	int r,id;
}now[3];
struct node
{
	int x1,y1,x2,y2;
	int id;
}a[200005];
bool cmp(node x,node y)
{
	return x.x1<y.x1;
}
bool idd(node x,node y)
{
	return x.id<y.id;
}
int main(){
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].y1>>a[i].x1>>a[i].y2>>a[i].x2;
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		now[1].r=now[2].r=0;
		for(int i=1;i<=n;i++)
		{
			a[i].x1=max(a[i].x1,min(now[1].r,now[2].r)+1);
			if(a[i].x2<=now[1].r)
				a[i].y1=2;
			if(a[i].x2<=now[2].r)
				a[i].y2=1;
			if(a[i].x1>a[i].x2||a[i].y1>a[i].y2)
				continue;
			for(int j=a[i].y1;j<=a[i].y2;j++)
			{
				if(now[j].r>=a[i].x1)
					a[now[j].id].x2=a[i].x1-1;
				now[j].r=a[i].x2,now[j].id=i;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x1>a[i].x2||a[i].y1>a[i].y2)
			{
				a[i].x1=a[i].x2=a[i].y1=a[i].y2=0;
				continue;
			}
			ans+=(a[i].x2-a[i].x1+1)*(a[i].y2-a[i].y1+1);
		}
		cout<<ans<<endl;
		sort(a+1,a+n+1,idd);
		for(int i=1;i<=n;i++)
		{
			cout<<a[i].y1<<' '<<a[i].x1<<' '<<a[i].y2<<' '<<a[i].x2<<endl;
		}
	}
    return 0;
}