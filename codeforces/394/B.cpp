#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int b[N];
void solve()
{
	int p,x;
	cin>>p>>x;
	for(int i=x;i<=9;i++)
	{
		a[p]=b[1]=i;
		int temp=0;
		for(int j=1;j<=p;j++)
		{
			b[j+1]=a[j]=(temp*10+b[j])/x;
			temp=(temp*10+b[j])%x;
			
		}
		if(b[p]==(i*x)%10)
		{
			for(int i=1;i<=p;i++)
			{
				cout<<a[i];
			}
			return ;
		}
	}
	cout<<"Impossible";
	return ;
}
int main()
{
	solve();
	return 0;
}