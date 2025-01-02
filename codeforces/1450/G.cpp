#include <bits/stdc++.h>
using namespace std;
int n,A,B,l[25],r[25],c[25];char s[5011];
int hsh[31],pre[25];
int id[25];
bitset<1<<20> g,ok;
char ihsh[25];
int main()
{
	scanf("%d%d%d%s",&n,&A,&B,s+1);
	g[0]=1;int k=0;
	memset(l,0x3f,sizeof(l));
	memset(hsh,-1,sizeof(hsh));
	for(int i=1;i<=n;++i)
	{
		if(!~hsh[s[i]-'a'])ihsh[k]=s[i],hsh[s[i]-'a']=k++;
		int v=hsh[s[i]-'a'];
		l[v]=min(l[v],i);r[v]=max(r[v],i);++c[v];
	}
	// for(int i=0;i<k;++i)printf("i:%d l:%d r:%d c:%d\n",i,l[i],r[i],c[i]);
	ok[0]=1;
	for(int S=1;S<1<<k;++S)
	{
		int _l=1e9,_r=0,_c=0;
		for(int i=0;i<k;++i)if(S>>i&1)_l=min(_l,l[i]),_r=max(_r,r[i]),_c+=c[i];
		if(1ll*A*(_r-_l+1)<=1ll*B*_c)ok[S]=1;
	}
	// printf("ok:");for(int S=0;S<1<<k;++S)printf("%d ",(int)ok[S]);putchar(10);
	for(int S=1;S<1<<k;++S)
	{
		for(int i=0;i<k;++i)if((S>>i&1)&&ok[S])g[S]=g[S]|g[S^1<<i];
		for(int i=0;i<k;++i)
		{
			int T=(1<<i)-1&S;//printf("S:%d T:%d\n",T);
			g[S]=g[S]|(g[T]&g[S^T]);
		}
		// for(int T=S;T;T=T-1&S)g[S]=g[S]|(g[T]&g[S^T]);
	}
	// printf("g:");for(int S=0;S<1<<k;++S)printf("%d ",(int)g[S]);putchar(10);
	vector<char> vc;
	for(int i=0;i<k;++i)if(g[(1<<k)-1^1<<i])vc.push_back(ihsh[i]);
	sort(vc.begin(),vc.end());
	printf("%d ",int(vc.size()));
	for(char c:vc)putchar(c),putchar(32);putchar(10);
	fclose(stdin);fclose(stdout);return 0;
}