#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
	int i,j,k,n,m,sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		sum+=k;
		a[k]++;
	}
	if(a[0]==0) 
	{
		cout<<"-1";
		return 0;
	}
	if(sum%3==1)
	{
		if(a[1])
		{
			a[1]--;
			sum-=1;
		}
		else if(a[4]) 
		{
			a[4]--;
			sum-=4;
		}
		else if(a[7])
		{
			a[7]--;
			sum-=7;
		}
		else if(a[2]>=2)
		{
			a[2]-=2;
			sum-=4;
		}
		else if(a[2]&&a[5])
		{
			a[2]--;
			a[5]--;
			sum-=7;
		}
		else if(a[2]&&a[8])
		{
			a[2]--;
			a[8]--;
			sum-=10;
		}
		else if(a[5]>=2)
		{
			a[5]-=2;
			sum-=10;
		}
		else if(a[5]&&a[8])
		{
			a[5]--;
			a[8]--;
			sum-=13;
		}
		else if(a[8]>=2)
		{
			a[8]-=2;
			sum-=16;
		}
		else 
		{
			 cout<<"-1";
			 return 0;
		}
	}
	if(sum%3==2)
	{
		if(a[2])
		{
			a[2]--;
			sum-=2;
		}
		else if(a[5])
		{
			a[5]--;
			sum-=5;
		}
		else if(a[8])
		{
			a[8]--;
			sum-=8;
		}
		else if(a[1]>=2)
		{
			a[1]-=2;
			sum-=2;
		}
		else if(a[1]&&a[4])
		{
			a[1]--;
			a[4]--;
			sum-=5;
		}
		else if(a[1]&&a[7])
		{
			a[1]--;
			a[7]--;
			sum-=8;
		}
		else if(a[4]>=2)
		{
			a[4]-=2;
			sum-=8;
		}
		else if(a[4]&&a[7])
		{
			a[4]--;
			a[7]--;
			sum-=11;
		}
		else if(a[7]>=2)
		{
			a[7]-=2;
			sum-=14;
		}
		else 
		{
			cout<<"-1";
			return 0;
		}
	}
	if(!sum)
	{
		cout<<"0";
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}

			     	      	 		 	 		 	 	  	