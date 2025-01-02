#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=1e9+7;
int n,num[N],now[N],Num[N],Ksm[N],ans;
int read()
{
	int ret=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar();
	return ret;
}
int main()
{
	n=read();
	Ksm[0]=1;
	for(int i=1;i<=n;i++)
		Ksm[i]=2ll*Ksm[i-1]%mod;
	for(int i=1;i<=n;i++)
		num[i]=read();
	sort(num+1,num+1+n);
	int L=min(70,n);
	for(int i=1;i<=n-L;i++)
	{
		(ans+=1ll*num[1]*Ksm[n-i]%mod)%=mod;
		for(int j=L;j>=1;j--)
			num[j]-=num[1];
		priority_queue < pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > H;
		for(int j=1;j<=L-1;j++)
			now[j]=j+1,H.push(make_pair(num[j]+num[now[j]],j));
		for(int j=1;j<=L;j++)
		{
			int id=H.top().second;
			Num[j]=H.top().first;
			H.pop();
			++now[id];
			if(now[id]<=L)
				H.push(make_pair(num[id]+num[now[id]],id));
		}
		for(int j=1;j<=L;j++)
			num[j]=Num[j];
	}
	for(int i=1;i<=L-1;i++)
	{
		(ans+=1ll*num[1]*Ksm[L-i]%mod)%=mod;
		for(int j=L-i+1;j>=1;j--)
			num[j]-=num[1];
		priority_queue < pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > H;
		for(int j=1;j<=L-i;j++)
			now[j]=j+1,H.push(make_pair(num[j]+num[now[j]],j));
		for(int j=1;j<=L-i;j++)
		{
			int id=H.top().second;
			Num[j]=H.top().first;
			H.pop();
			++now[id];
			if(now[id]<=L-i+1)
				H.push(make_pair(num[id]+num[now[id]],id));
		}
		for(int j=1;j<=L-i;j++)
			num[j]=Num[j];
	}
	printf("%d",(num[1]+ans)%mod);
}