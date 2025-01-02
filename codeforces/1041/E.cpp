#include<bits/stdc++.h>
using namespace std;
int n;
int sum[1010],sx[1010],L,cnt;
int main()
{
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++){scanf("%d%d",&a,&b);sum[a]++;sum[b]++;}
	if(sum[n]!=n-1){puts("NO");return 0;}
	sx[1]=n;L=1;cnt=1;
	for(int i=n-1;i;i--)
	{
	   if(!sum[i]){while(sx[L]) L++;if(L>cnt){puts("NO");return 0;}sx[L]=i;continue;}
	   cnt+=sum[i];sx[cnt]=i;
	}
	puts("YES");
	for(int i=1;i<n;i++) printf("%d %d\n",sx[i],sx[i+1]);
	return 0;
} 