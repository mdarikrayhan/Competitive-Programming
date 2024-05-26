#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n,k;
int a[N],c[N];
void work(int l,int r,int id)
{
	int m=(l+r+1)/2;
	for(int i=l;i<=m;i++)a[i]=m+l-i,c[i]=id;
	for(int i=m+1;i<=r;i++)a[i]=m+1+r-i,c[i]=id;
}
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>k;
		int cnt=(n+k-1)/k;
		for(int i=1;i<=cnt;i++)
		{
			work((i-1)*k+1,min(i*k,n),i);
		}
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		puts("");
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++)cout<<c[i]<<' ';
		puts("");
	}
	return 0;
}
