// LUOGU_RID: 157610055
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[N][N],d[N];
int maxn[N],minn[N];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int c,m,n;
	cin>>m>>c;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
	}
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		cin>>d[i];
		for(int j=1;j<=d[i];j++)
		{
			cin>>b[i][j];
		}
	}
//	cout<<"·····················\n";
	for(int i=1;i<=n;i++)
	{
		minn[i]=0,maxn[i]=0;
		for(int j=1;j<=d[i];j++)
		{
			if(b[i][j]==0)
			{
				maxn[i]++;
				minn[i]++;
				continue;
			}
			bool flag=false;
			for(int k=1;k<=c;k++)
			{
				if(b[i][j]==a[k])
				{
					flag=true;
				}
			}
			if(flag==true)
			{
				maxn[i]++;
			}	
			else
			{
				minn[i]++;
			}
		}
//		cout<<maxn[i]<<" "<<minn[i]<<endl;
		maxn[i]=min(maxn[i],c);
		minn[i]=d[i]-min(minn[i],m-c);
	}
	for(int i=1;i<=n;i++)
	{
		bool flag1=false,flag0=true;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(minn[i]<maxn[j])
			{
				flag0=false;
			}
			if(maxn[i]<minn[j])
			{
				flag1=true;
			}
		}
		if(flag1==true)cout<<1<<endl;
		else if(flag0==true)cout<<0<<endl;
		else cout<<2<<endl;
	}
	return 0;
}

		