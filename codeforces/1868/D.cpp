// LUOGU_RID: 158873866
// created:  May/13/2024 11:03:52
#include<cstdio>
#include<cctype>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
#define I128 //||is_same<T,__int128_t>::value||is_same<T,__uint128_t>::value
using namespace std;
template<typename T>enable_if_t<is_integral<T>::value I128,void> readmain(T &x)
{
	bool neg=false;int c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=true;
	for(x=0;isdigit(c);c=getchar())x=(T)(10*x+(c-'0'));
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
typedef long long ll;
constexpr int N=1e6+5;
int tt,n,d[N],id[N];
void solve()
{
	ll sd=0;
	F(i,0,n)sd+=d[i],id[i]=i;
	sort(id,id+n,[](const int &u,const int &v){return d[u]>d[v];});
	if(sd!=2*n)return puts("No"),void();
	if(d[id[0]]==2)
	{
		puts("Yes");
		F(i,0,n)printf("%d %d\n",i+1,i+2-n*(i==n-1));
		return;
	}
	if(d[id[1]]<=2)return puts("No"),void();
	if(d[id[2]]==2&&d[id[0]]==3)
	{
		if(n&1)return puts("No"),void();
		puts("Yes");
		printf("%d %d\n",id[0]+1,id[1]+1);
		printf("%d %d\n",id[0]+1,id[1]+1);
		d[id[0]]-=2;
		d[id[1]]-=2;
		int c=0;
		F(i,2,n)
		{
			int u=id[i];
			printf("%d %d\n",id[c]+1,u+1),id[c]=u,c^=1;
		}
		return;
	}
	int r=2;
	while(r<n&&d[id[r]]>1)++r;
	if(r==3||(r==5&&d[id[0]]<=3))
	{
		if(d[id[r-1]]==2)return puts("No"),void();
		puts("Yes");
		F(i,0,r)printf("%d %d\n",id[i]+1,id[i+1-r*(i==r-1)]+1),d[id[i]]-=2;
		int j=0;
		F(i,r,n)
		{
			int u=id[i],fa;
			--d[u];
			if(!d[u])
			{
				while(!d[id[j]])++j;
				fa=id[j];
			}
			--d[fa];
			printf("%d %d\n",fa+1,u+1);
		}
		return;
	}
	puts("Yes");
	printf("%d %d\n",id[0]+1,id[1]+1);
	printf("%d %d\n",id[0]+1,id[1]+1);
	d[id[0]]-=2;
	d[id[1]]-=2;
	int e[2]={id[0],id[1]},c=0,j=0;
	F(i,2,n)
	{
		int u=id[i],fa;
		--d[u];
		if(!d[u])
		{
			while(!d[id[j]])++j;
			fa=id[j];
		}
		else fa=i==(r^1)?id[0+2*!d[id[0]]]:e[c&1],e[c&1]=u,++c;
		--d[fa];
		printf("%d %d\n",fa+1,u+1);
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(d[i]);
		solve();
	}
	return 0;
}
