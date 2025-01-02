#include<bits/stdc++.h>
using namespace std;
int T,n,x,y;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		cout<<0<<" ";
		while(--n)
		{
			cin>>y;
			printf(" %d",((y|x)^y));
			x|=y;
		}
		cout<<endl;
	}
	return 0;
}