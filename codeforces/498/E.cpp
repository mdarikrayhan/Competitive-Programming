// LUOGU_RID: 159655350
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int f[2][1<<8];
void add(int &x,int y) {if((x+=y)>=mod) x-=mod;}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int p=0,q=1;
	f[p][1]=1;
	for(int h=1,w;h<=7;h++)
	{
		memset(f[q],0,sizeof(f[q]));
		cin>>w;
		for(int s=0;s<(1<<h);s++) add(f[q][s<<1|1],f[p][s]);
		swap(p,q);
		while(w--)
		{
			for(int i=1;i<=h;i++,swap(p,q))
			{
				memset(f[q],0,sizeof(f[q]));
				for(int s=0;s<(1<<(h+1));s++)
				{
					bool L=(s>>(h+1-i))&1,U=(s>>(h-i))&1;
					int t=s;
					t&=~(3<<(h-i)),add(f[q][t],f[p][s]);
					t^=1<<(h-i),add(f[q][t],f[p][s]);
					t^=3<<(h-i),add(f[q][t],f[p][s]);
					if(!L||!U) t^=1<<(h-i),add(f[q][t],f[p][s]);
				}
			}
			memset(f[q],0,sizeof(f[q]));
			for(int s=0;s<(1<<(h+1));s++) if(s&1) f[q][(s>>1)|(1<<h)]=f[p][s];
			swap(p,q);
		}
	}
	cout<<f[p][(1<<8)-1];
	return 0;
}