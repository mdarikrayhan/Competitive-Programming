// LUOGU_RID: 159242778
#include<bits/stdc++.h>
using namespace std;
#define Getchar() p1==p2 and (p2=(p1=Inf)+fread(Inf,1,1<<21,stdin),p1==p2)?EOF:*p1++
#define Putchar(c) p3==p4 and (fwrite(Ouf,1,1<<21,stdout),p3=Ouf),*p3++=c
char Inf[1<<21],Ouf[1<<21],*p1,*p2,*p3=Ouf,*p4=Ouf+(1<<21);
inline void read(int &x,char c=Getchar())
{
	bool f=c!='-';
	x=0;
	while(c<48 or c>57) c=Getchar(),f&=c!='-';
	while(c>=48 and c<=57) x=(x<<3)+(x<<1)+(c^48),c=Getchar();
	x=f?x:-x;
}
inline void write(int x)
{
	if(x<0) Putchar('-'),x=-x;
	if(x>=10) write(x/10),x%=10;
	Putchar(x^48);
}
inline void IndSet()
{
	Putchar('I'),Putchar('n'),Putchar('d'),Putchar('S'),Putchar('e'),Putchar('t'),Putchar('\n');
}
inline void Matching()
{
	Putchar('M'),Putchar('a'),Putchar('t'),Putchar('c'),Putchar('h'),Putchar('i'),Putchar('n'),Putchar('g'),Putchar('\n');
}
int t,n,m,cnt,num,ans[500010];
bool vis[500010];
inline void init()
{
	cnt=num=0;
	for(int i=1;i<=n*3;i++) vis[i]=0;//警钟敲烂！！！不要memset！！！否则超时！！！
}
int main()
{
	read(t);
	while(t--)
	{
		read(n),read(m),init();
		for(int i=1,x,y;i<=m;i++)
		{
			read(x),read(y);
			if(!vis[x] && !vis[y]) vis[x]=vis[y]=1,ans[++cnt]=i;
		}
		if(cnt<=n)
		{
			IndSet();
			for(int i=1;i<=n*3 && num<n;i++) if(!vis[i]) write(i),Putchar(' '),num++;
			Putchar('\n');
		}else
		{
			Matching();
			for(int i=1;i<=n;i++) write(ans[i]),Putchar(' ');
			Putchar('\n');
		}
	}
	fwrite(Ouf,1,p3-Ouf,stdout),fflush(stdout);
	return 0;
}