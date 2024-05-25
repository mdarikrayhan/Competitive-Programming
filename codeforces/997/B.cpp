// LUOGU_RID: 160094803
#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
int n;LL ans;
int main()
{
    scanf("%d",&n);
   	for(RI i=0;i<=8&&i<=n;++i)
   		for(RI j=0;j<=(i==0?8:4)&&j+i<=n;++j)
   			ans+=n-i-j+1;
   	printf("%lld\n",ans);
    return 0;
}