// LUOGU_RID: 101623917
#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001],n,k,s=1,i;
int main()
{
	cin>>n>>k;
	a[0]=1;for(i=1;i<=1000000;i=i+1)a[i]=a[i-1]*i%998244353;
	b[0]=1;b[1]=1;for(i=2;i<=1000000;i=i+1)b[i]=b[998244353%i]*(998244353-998244353/i)%998244353;
	for(i=2;i<=1000000;i=i+1)b[i]=b[i-1]*b[i]%998244353;
	for(i=0;i<k;i=i+1)s=(s+a[i/2+min(n-k,k-i)]*b[i/2+1]%998244353*b[min(n-k,k-i)-1]%998244353)%998244353;
	cout<<s;
	return 0;
}