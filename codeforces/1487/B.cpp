#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int a, b;
		cin>>a>>b;
		b--;
		cout<<(b+(a%2)*b/(a/2))%a+1<<endl;
	}
}