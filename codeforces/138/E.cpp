// LUOGU_RID: 159938303
#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void print(T x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+48);
}
template <typename T> void print(T x,char c){print(x); putchar(c);}
template<typename T>inline void output(T x){print(x,' ');}
template<typename T,typename ...Arg>inline void output(T x,Arg ...arg){output(x);output(arg...);}
const int N=100007,M=507;
int n,m,L,R,s[N][26],f[N],res;
ll ans; char str[N],ch[3];
struct node{int c,cl,cr,l,r;}a[M];
void add(int p,int v)
{
	res-=(L<=f[p]&&f[p]<=R);
	f[p]+=v;
	res+=(L<=f[p]&&f[p]<=R);
}
int main()
{
	scanf("%s",str+1); read(m,L,R);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
		for(int c=0;c<26;c++)
			s[i][c]=s[i-1][c]+(str[i]=='a'+c);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",ch);
		read(a[i].cl,a[i].cr);
		a[i].c=ch[0]-'a';
	}
	for(int r=1;r<=n;r++)
	{
		res+=(L<=f[r]&&f[r]<=R);
		for(int i=1;i<=m;i++)
		{
			int ch=a[i].c;
			while(a[i].r<r&&s[r][ch]-s[a[i].r][ch]>=a[i].cl) add(++a[i].r,1);
			while(s[r][ch]-s[a[i].l][ch]>a[i].cr) add(++a[i].l,-1);
		}
		ans+=res;
	}
	print(ans,'\n');
	return 0;
}