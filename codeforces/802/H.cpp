// LUOGU_RID: 160209650
#include<bits/stdc++.h>
using namespace std;
string a,b;char c;
void work(int x)
{
	if(x==1)
	{
		b=c='a';return;
	}
	if(x==2)
	{
		a=c='b',b='ab';
		return;
	}
	if(x%2)
	{
		work(x/2);
		c++;
		a=a+c+c,b=b+c;
	}
	else
	{
		work(x/2-1);
		c++,a=c+a+c+c,b=b+c;
	}
}
int main()
{
	int n;
	cin>>n;
	work(n);
	cout<<b+a<<" "<<b;
	return 0;
}