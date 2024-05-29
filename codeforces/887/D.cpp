#include<bits/stdc++.h>
#define N 300001
using namespace std;
#define LL long long
LL n,a,b,c,d,s,l,f,m,j,t[N],q[N];
int main()
{
	m=2e9,j=1,t[0]=-1;
	cin>>n>>a>>b>>c>>d>>s>>l;
	for(LL i=1;i<=n;i++)cin>>t[i]>>q[i];
	for(LL i=1;i<=n;i++)
	  {
	  while(j<=n && t[j]-t[i]<l)f+=q[j]?c:-d,m=min(m,f),j++;
	  if(s+m>=0)return printf("%I64d\n",t[i-1]+1),0;
	  s+=q[i]?a:-b,m-=q[i]?c:-d,f-=q[i]?c:-d;
	  if(s<0)return printf("-1\n"),0;
	  }
	printf("%I64d\n",t[n]+1);
	return 0;
}