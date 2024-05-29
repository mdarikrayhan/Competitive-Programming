// LUOGU_RID: 158153975
#include<bits/stdc++.h>
using namespace std;
const int N=20+5;
long long pw[N],w[N],w1[N];
int main()
{
    int t;
    cin>>t;
	pw[0]=w[0]=1;
	w[1]=4;
	w1[0]=2;
	w1[1]=16;
	for(int i=1;i<=17;i++)pw[i]=pw[i-1]*5;
	for(int i=2;i<17;i++)
	{
		w[i]=w[i-1]*5;
		w1[i]=(__int128)w1[i-1]*w1[i-1]%pw[17];
		w1[i]=(__int128)w1[i]*w1[i]%pw[17];
		w1[i]=(__int128)w1[i]*w1[i-1]%pw[17];
	}
    long long n,nw,ans;
	while(t--)
    {
        scanf("%lld",&n);
        n*=1e6;
        nw=1;
        ans=17;
        n=((n-1)>>17)+1;
        if(!(n%5))n++;
        for(int i=0;i<17;i++)while(n%pw[i+1]!=nw%pw[i+1])nw=(__int128)nw*w1[i]%pw[17],ans+=w[i];
        printf("%lld\n",ans);
    }
	return 0;
}
