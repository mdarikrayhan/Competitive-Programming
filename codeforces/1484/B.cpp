// LUOGU_RID: 158365865
#include<iostream>
#include<set>
using namespace std;
int a[100010];
int b[100010]; 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		set<int>p;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<n;i++)
		{
			b[i]=a[i+1]-a[i];
			p.insert(b[i]);
	    }
	   int t=p.size();
	   if(t>2)
	   {
	   	cout<<"-1"<<endl;
	   }
	   else 
	   {
	   	if(t==1)
	   	{
	   	   
	   	    	cout<<"0"<<endl;
	
		}
		else if(t==2)
		{
			if(p.erase(0))
			{
				cout<<"-1"<<endl;
			}
			else
			{
				int o=0;
				int m1=0,m2=*p.lower_bound(0);
				int uo=*p.upper_bound(0);
				if(uo==0)o=1;
				for(int i=1;i<n;i++)
				{
					if(a[i+1]<a[i])
					{
						m1=m2+a[i]-a[i+1];
					}
				}
				for(int i=1;i<=n;i++)
				{
					if(a[i]>=m1)
					{
						o=1;
						break;
					}
				}
				if(o==1)cout<<"-1"<<endl;
				else cout<<m1<<" "<<m2<<endl;
			}
		}
	   }
	}
	return 0;
 } 