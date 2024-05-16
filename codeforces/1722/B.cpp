#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		char a[2][200010];	
		cin>>a[0];
		cin>>a[1];
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]=='R')
					a[i][j]='1';
				else if(a[i][j]=='G'||a[i][j]=='B')
					a[i][j]='0';
			}
		}
		int f=0;
		for(int i=0;i<n;i++)
		{
			if(a[0][i]!=a[1][i])
			{
				cout<<"NO"<<endl;
				f=1;
				break;
			}
		}
		if(f==0)
			cout<<"YES"<<endl;
	}
	return 0;
}