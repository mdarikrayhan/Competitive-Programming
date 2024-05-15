#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	char s[n][m];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int a[m];

	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	int q[5];
	int sum=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<5;j++)
		{
			q[j]=0;
		}
			char c;
		for(int j=0;j<n;j++)
		{
			c = s[j][i]; 
			switch(c)
			{
				case 'A':
					q[0]++;
					break;
				case 'B':
					q[1]++;
					break;
				case 'C':
					q[2]++;
					break;
				case 'D':
					q[3]++;
					break;
				case 'E':
					q[4]++;
					break;
			}
		}
		sum+=*max_element(q,q+5)*a[i];
	}
	cout<<sum<<"\n";


return 0;
}
