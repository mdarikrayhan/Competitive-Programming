#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	int a[110];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    sort(a+2,a+n+1);
	int ans=0;
	while(a[n]>=a[1])
	{
		ans++;
		a[1]++;
		a[n]--;
		sort(a+2,a+n+1);
	}
	cout<<ans<<endl;
    return 0;
}

