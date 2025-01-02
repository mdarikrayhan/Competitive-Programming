#include <bits/stdc++.h>
using namespace std;
const int maxn = 1<<22;
int a[maxn],ans,f[maxn],n,vis[maxn];
void pushdown(int x,int bit)
{
	if( f[x]>=2 )	return;
	if( bit==-1 )	{ f[x]++; return; }
	pushdown(x,bit-1);//这一位不剥削
	if( x&(1<<bit) )	pushdown(x^(1<<bit),bit-1);//剥削这一位 
} 
int get(int x)
{
	int ans = 0;
	for(int i=20;i>=0;i--)
		if( (x&(1<<i))==0&&f[ans|(1<<i)]>=2 )	ans |= (1<<i);
	return ans|x;
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i] );
	for(int i=n;i>=1;i-- )
	{
		if( i<=n-2 )	ans = max( ans,get( a[i] ) );
		pushdown( a[i],20 );
	}
	printf("%d",ans);
}
