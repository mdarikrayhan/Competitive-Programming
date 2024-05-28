#include<bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;
const int BITS=17,MAX=(1<<BITS)-1,N=(1<<21)+10;
int kb[1<<BITS];
ll bad[N];
double f[N];
char word[777][777];
int main()
{
	int cnt;
	scanf("%d",&cnt);
	for(int i=0;i<cnt;i++) scanf("%s",word[i]);
	int n=strlen(word[0]);
	for(int i=0;i<cnt;i++)
	{
		for(int j=i+1;j<cnt;j++)
		{
			int diff=0;
			for(int k=0;k<n;k++) if(word[i][k]==word[j][k]) diff|=(1<<k);
			bad[diff]|=(1ll<<i),bad[diff]|=(1ll<<j);
		}
	}
	kb[0]=0;
	for(int i=1;i<(1<<BITS);i++) kb[i]=kb[i&(i-1)]+1;
	for(int t=(1<<n)-1;t>=0;t--)
	{
		for(int i=0;i<n;i++) if(t&(1<<i)) bad[t^(1<<i)]|=bad[t];
		int p=0;
		f[t]=0.0;
		for(int i=0;i<n;i++) if(!(t&(1<<i))) f[t]+=f[t^(1<<i)],p++;
		if(p>0) f[t]/=p;
		f[t]+=(kb[bad[t]&MAX]+kb[(bad[t]>>BITS)&MAX]+kb[(bad[t]>>(BITS<<1))])*1.0/cnt;
	}
	printf("%.17lf\n",f[0]);
	return 0;
}