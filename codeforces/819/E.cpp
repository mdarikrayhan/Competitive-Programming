// LUOGU_RID: 159128953
#include <bits/stdc++.h>
using namespace std;
struct data
{
	int n,a1,a2,a3,a4;
}d[100005];
int n,cnt;
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n<3)
	{
		cout<<"-1";
		return 0;
	} 
	if(n&1)
	{
		d[++cnt]={3,1,2,3,0};
		d[++cnt]={3,1,2,3,0};
		for(int i=5;i<=n;i+=2)
		{
			for(int j=1;j<=i-3;j+=2)
			{
				d[++cnt]={4,j,i-1,j+1,i};
				d[++cnt]={4,j,i-1,j+1,i};
			}
			d[++cnt]={3,i-2,i-1,i,0};
			d[++cnt]={3,i-2,i-1,i,0};
		}
	}
	else
	{
		d[++cnt]={3,1,2,3,0};
		d[++cnt]={3,1,2,4,0};
		d[++cnt]={3,1,3,4,0};
		d[++cnt]={3,2,3,4,0};
		for(int i=6;i<=n;i+=2)
		{
			for(int j=1;j<=i-4;j+=2)
			{
				d[++cnt]={4,j,i-1,j+1,i};
				d[++cnt]={4,j,i-1,j+1,i};
			}
			d[++cnt]={4,i-3,i-1,i-2,i};
			d[++cnt]={3,i-3,i-1,i,0};
			d[++cnt]={3,i-2,i-1,i,0};
		}
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++)
	{
		cout<<d[i].n<<" ";
		if(d[i].n==3)
			cout<<d[i].a1<<" "<<d[i].a2<<" "<<d[i].a3<<"\n";
		else
			cout<<d[i].a1<<" "<<d[i].a2<<" "<<d[i].a3<<" "<<d[i].a4<<"\n";
	}
	return 0;
}
//Skadi_H
