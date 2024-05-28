#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,cnt,a[N],ans[N];
int main()
{
	cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<i<<endl;
		if(i+a[i]/2<=n)ans[i]=i+a[i]/2;
		else ans[i]=i-a[i]/2;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}