#include<bits/stdc++.h>
using namespace std;
long long n,k,x,i,a[200008];
int main()
{
    for(scanf("%lld%lld%lld",&n,&k,&x);i!=n;scanf("%lld",a+(i++)));
    for(sort(a,a+n);i--;a[i]=max(0ll,a[i]-a[i-1]-1));
    for(a[0]=0,sort(a,a+ n);i!=n&&a[i]/x<=k;k-=a[i++]/x);
    printf("%lld\n",n-i+1);
	return 0;
}