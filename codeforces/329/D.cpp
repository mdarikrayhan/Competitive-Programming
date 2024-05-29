#include <bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(int j=1;j<n;j++)
				if((j<<1)<n+1)
					cout<<'>';
				else
					cout<<(j%2==1 ? '>' : '.');
			cout<<"v\n";
		}
		else 
		{
			cout<<'^';
			for(int j=2;j<=n;j++)
				if(j*2>n+1)
					cout<<'<';
				else
					cout<<(j%2==1 ? '<' : '.');
			cout<<endl;
		}
	}
	cout<<1<<' '<<n<<endl;
	
	return 0;
}