// LUOGU_RID: 160501166
#include<stdio.h>
#define N 2000009
#define max(x,y) ((x)>(y)?(x):(y))
inline char nc()
{
	static char buf[99999],*l,*r;
	return l==r&&(r=(l=buf)+fread(buf,1,99999,stdin),l==r)?EOF:*l++;
}
inline void read(int&x)
{
	char c=nc();for(;c<'0'||'9'<c;c=nc());
	for(x=0;'0'<=c&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=nc());
}
int t,n,l[N],r[N],s1[N],s2[N],s3[N],nxt[N],lst[N],f[N<<1],cnt;bool ff[N<<1];
struct __readt__{inline __readt__(){read(t);}}_readt___;
inline int find(int x){if(x^f[x])return f[x]=find(f[x]);return x;}
main()
{
	read(n);
	for(int i=1;i<=n;s1[i]=s2[i]=s3[i]=0,read(l[i]),read(r[i++]));
	for(int i=1;i<=n;++i)
	{
		if(i+l[i]<=n)++s1[i+l[i]];
		if(i+r[i]+1<=n)--s1[i+r[i]+1];
		++s2[max(1,i-r[i])];
		--s2[max(1,i-l[i]+1)];
	}
	for(int i=1;i<=n;s1[i]+=s1[i-1],s2[i]+=s2[i-1],++i);
	for(int i=n,x=n+1;i;--i)
	{
		nxt[i]=x;
		if(s1[i]&&s2[i])x=i;
	}
	for(int i=1,x=0;i<=n;++i)
	{
		lst[i]=x;
		if(s1[i]&&s2[i])x=i;
	}
	for(int i=1;i<=n<<1;f[i]=i,ff[i++]=0);
	for(int i=1,j;i<=n;++i)
	{
		j=i+l[i];
		if(j<=n)
		{
			if(!s1[j]||!s2[j])j=nxt[j];
			if(j<=n)if(j<=i+r[i])f[find(j+n)]=find(i);
		}
		j=max(1,i-r[i]);
		if(!s1[j]||!s2[j])j=nxt[j];
		if(j<=n)if(j<=i-l[i])f[find(j+n)]=find(i);
	}
	for(int i=1,j;i<=n;++i)
	{
		j=i+l[i];
		if(j<=n)
		{
			if(!s1[j]||!s2[j])j=nxt[j];
			if(j<=n)if(j<=i+r[i])++s3[j];
		}
		j=i+r[i];
		if(j<=n)
		{
			if(!s1[j]||!s2[j])j=lst[j];
			if(j>=i+l[i])--s3[j];
		}
		j=max(1,i-r[i]);
		if(!s1[j]||!s2[j])j=nxt[j];
		if(j<=n)if(j<=i-l[i])++s3[j];
		j=max(1,i-l[i]);
		if(!s1[j]||!s2[j])j=lst[j];
		if(j>0)if(j>=i-r[i])--s3[j];
	}
	for(int i=s1[1]&&s2[1]?1:nxt[1];i<=n&&nxt[i]<=n;i=nxt[i])
	{
		s3[nxt[i]]+=s3[i];
		if(s3[i])f[find(i+n)]=find(nxt[i]+n);
	}
	for(int i=1;i<=n;ff[find(i++)]=1);
	cnt=0;for(int i=1;i<=n<<1;++i)if(i==f[i])cnt+=ff[i];
	printf("%d\n",cnt);
	if(--t)main();
}