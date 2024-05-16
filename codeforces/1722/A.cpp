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
		char a[11];	
		cin>>a;
		sort(a,a+5);	
		if(n!=5)
			cout<<"NO"<<endl;
		else
		{
			if(a[0]=='T'&&a[1]=='i'&&a[2]=='m'&&a[3]=='r'&&a[4]=='u')
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}