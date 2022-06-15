#include<bits/stdc++.h>
using namespace std;
int T,sh,sm,x,h,m,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d:%d %d",&sh,&sm,&x);
		h = sh,m = sm;
		ans = 0;
		do
		{
			m+=x;
			h+=m/60;
			m%=60;
			h%=24;
			if(m%10==h/10&&m/10==h%10) ans++;
		}while(h!=sh||m!=sm);
		printf("%d\n",ans);
	}
	return 0;
} 