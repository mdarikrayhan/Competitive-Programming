#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,a[N],ya[N],s[N],last[N];
map<int,int>mp[2]; 
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ya[i]=a[i];
		ya[i]^=ya[i-1];
		if(!a[i])s[i]=s[i-1]+1;
		last[i]=mp[i&1][ya[i]];
		mp[i&1][ya[i-1]]=i;
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(s[r]>=r-l+1)puts("0");
		else if(ya[l-1]^ya[r]||r-l<2)puts("-1");
		else if(!((r-l)&1)||!a[l]||!a[r])puts("1");
		else if(last[r]>l)puts("2");
		else puts("-1");
	}
	return 0;
}