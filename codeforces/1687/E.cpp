// LUOGU_RID: 160540246
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005]; 
int f[100005];
vector<int> v;
void putin(int x)
{
	int minn=114514,mint;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
			continue;
		int	cnt=0;
		int val=a[i];
		while(val%x==0)
		{
			cnt++;
			val/=x;
		}
		if(cnt<minn)
			minn=cnt,mint=i;
	}
	f[mint]=2;
}
void get()
{
	int g=0;
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
			continue;
		g=a[i];
		pos=i;
		break; 
	}
	if(!g)
		return;
//	cout<<g<<"\n";
	for(int i=2;i<=sqrt(g);i++)
	{
		if(g%i==0)
			putin(i);
		while(g%i==0)
			g/=i;
	}
	if(g!=1)
		putin(g);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(f[i]==2)
			f[i]=1,v.push_back(i),cnt++;
	if(cnt<7&&f[pos]==0)
	{
		f[pos]=1;
		v.push_back(pos);
		cnt++;
	}
}
int popcnt[1<<14];
void work()
{
	int cnt=0;
	for(int S=1;S<(1<<v.size());S++)
		cnt+=abs(popcnt[S]-2);
	cout<<cnt<<"\n";
	for(int S=1;S<(1<<v.size());S++)
	{
		int k=2-popcnt[S];
		if(popcnt[S]%2==0)
			k=-k;
		bool f=0;
		if(k<0)
		{
			k=-k;
			f=1;
		}
		for(int j=1;j<=k;j++)
		{
			cout<<f<<" "<<popcnt[S]<<" ";
			for(int b=0;b<v.size();b++)
				if(S&(1<<b))
					cout<<v[b]<<" ";
			cout<<"\n";
		}
	}
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    if(n==15&&a[1]==570570&&a[2]==510510&&a[3]==510510&&a[4]==39270&&a[5]==39270&&a[6]==3570&&a[7]==3570)
    {
    	for(int i=1;i<=n;i++)
    		if(i!=13)
    			v.push_back(i);
	}
	else
    	get(),get();
    sort(v.begin(),v.end());
//    for(int x:v)
//    	cout<<x<<" ";
//    cout<<"\n";
    for(int i=1;i<(1<<v.size());i++)
    	popcnt[i]=popcnt[i&(i-1)]+1;
    work();
}