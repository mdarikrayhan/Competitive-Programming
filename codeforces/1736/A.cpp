#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[100010],b[100010];
void sl()
{
	int n,aa=0,bb=0;
	cin>>n;
	for (int i = 1; i <= n; ++i) 
	{
		cin>>a[i];
		if (a[i] == 1) aa++;
	}
	for (int i = 1; i <= n; ++i) 
	{
		cin>>b[i];
		if (b[i] == 1) bb++;
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] != b[i]) sum++;
	}
	int res = min(sum,abs(aa-bb)+1);
	cout<<res<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin>>T;
	while(T--) sl();
	return 0;
}