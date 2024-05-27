// LUOGU_RID: 160329279
#include<bits/stdc++.h>
#define int long long
using namespace std;
int get(char x)
{
	return x-'a';
} 
int a[200005];
signed main()
{
	int n,t;
	cin>>n>>t;
	char c;
	for(int i=1;i<=n-2;i++)
	{
		cin>>c;
		a[i]=(1<<get(c));
	}
	sort(a+1,a+1+n-2,greater<int>() );
	cin>>c;
	t+=(1<<get(c));
	cin>>c;
	t-=(1<<get(c));
	for(int i=1;i<=n-2;i++)
	{
		if(abs(t-a[i])>abs(t+a[i]))
			t+=a[i];
		else
			t-=a[i];
	}
	if(t==0) cout<<"Yes";
	else cout<<"No";
}