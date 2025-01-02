// LUOGU_RID: 160424337
#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int t,n,ind,out[N];
void chk(int l,int r,int x)
{
	cout<<"? "<<r-l+1<<" "<<1<<"\n";
	for(int i=l;i<=r;i++)
	{
		cout<<i<<" ";
	}
	cout<<"\n";
	cout<<x<<"\n";
	fflush(stdout);
}
signed main()
{
	int x=0,y;
	cin>>t;
	while(t--)
	{
		cin>>n;
		x=ind=0;
		for(int i=2;i<=n;i++)
		{
			chk(1,i-1,i);
			cin>>y;
			if(y!=0)
			{
				x=i;
				break;
			}
		}
		for(int i=x+1;i<=n;i++)
		{
			chk(i,i,x);
			cin>>y;
			if(y==0)
			{
				out[++ind]=i;
			}
		}
		int l=1,r=x-1,mid;
		while(l!=r)
		{
			int mid=(l+r)/2;
			chk(l,mid,x);
			cin>>y;
			if(y==0)
			{
				l=mid+1;
			}else
			{
				r=mid;
			}
		}
		for(int i=1;i<x;i++)
		{
			if(i!=l)
			{
				out[++ind]=i;
			}
		}
		sort(out+1,out+1+ind);
		cout<<"! "<<ind<<" ";
		for(int i=1;i<=ind;i++)
		{
			cout<<out[i]<<" ";
		}
		cout<<"\n";
	}
}