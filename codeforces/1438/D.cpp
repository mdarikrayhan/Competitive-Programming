// LUOGU_RID: 159992445
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int N=1e5+5;
int n,a[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	n=read();
	int sum=0;
	for(int i=1;i<=n;i++) a[i]=read(),sum^=a[i];
	if(sum!=0&&n%2==0) puts("NO"),exit(0);
	if(n==1) printf("YES\n0"),exit(0);
	if(n%2==1)
	{
		printf("YES\n%d\n",n-2);
		for(int i=n-2;i>=1;i-=2) printf("%d %d %d\n",i,i+1,i+2);
		for(int i=4;i<=n;i+=2) printf("1 %d %d\n",i,i+1);
	}
	else
	{
		printf("YES\n%d\n",n-3);
		for(int i=n-3;i>=1;i-=2) printf("%d %d %d\n",i,i+1,i+2);
		for(int i=4;i<n;i+=2) printf("1 %d %d\n",i,i+1);
	}
	return 0;
}
