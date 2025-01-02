#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,cnt,a[N],ans[N],x[N],y[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int> ord(n+1);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin()+2,ord.end(),[&](int i,int j){return a[i]>a[j];});
    for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			int j=ord[1];
			x[j]=1;
			y[j]=n;
			ans[j]=1;
			continue;
		}
		int j=ord[i],pre=ord[i-1];
		x[j]=i;
		if(!a[j])
		{
			y[j]=1;
			ans[j]=j;
		}
		else if(y[pre]+a[j]-1<=n)y[j]=y[pre]+a[j]-1,ans[j]=pre;
		else y[j]=y[pre]-a[j]+1,ans[j]=pre;
	}
	puts("YES");
    for(int i=1;i<=n;i++)cout<<x[i]<<" "<<y[i]<<endl;
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}