// LUOGU_RID: 100299504
#include<bits/stdc++.h>
#define IL inline
#define reg register
#define N 5005000
char s[N+N],t[N],h[N];
int n,k;

IL void print(reg char *s,reg int n)
{
for(reg int i=1;i<=n;++i)putchar(s[i]);
exit(0);
}

int l[N+N],r[N+N],m;
bool eq[N+N];

IL void Lyndon(reg char *s,reg int n)
{
m=0;
for(reg int i=1,j,k;i<=n;)
{
j=i,k=i+1;
for(;k<=n&&s[k]>=s[j];++k)if(s[k]==s[j])++j; else j=i;
while(i<=j)l[++m]=i,i+=k-j,r[m]=i-1;
}
for(reg int i=1,j;i<m;++i)if(r[i]-l[i]==r[i+1]-l[i+1])
{
eq[i]=1;
for(j=0;j<=r[i]-l[i];++j)eq[i]&=s[j+l[i]]==s[j+l[i+1]];
eq[i]|=l[i]==r[i];
}
}

IL void upd()
{
for(reg int i=1;i<=n;++i)if(t[i]!=h[i])
{
if(h[i]<t[i])for(i=1;i<=n;++i)t[i]=h[i];
break;
}
}

int z[N];

IL int min(reg int x,reg int y){return x<y?x:y;}

main()
{
scanf("%s%d",t+1,&k),n=strlen(t+1);
for(reg int i=1;i<=n;++i)s[i]=t[n-i+1];
if(k==1)
{
for(reg int i=1;i<=n;++i)if(s[i]!=t[i])print(s[i]<t[i]?s:t,n);
print(s,n);
}
Lyndon(s,n); reg int p=m;
for(reg int i;p;--p)
{
k-=!eq[p];
if(k==1)break;
for(i=l[p];i<=r[p];++i)putchar(s[i]);
}
if(!p)return 0;
n=r[p];
for(reg int i=1;i<=n;++i)t[i]=s[n-i+1],s[i+n]=s[i];
Lyndon(s,n+n);
for(reg int i=1;i<=m;++i)if(r[i]>=n){p=l[i]; break;}
for(reg int i=p;i<=n;++i)h[i-p+1]=s[i];
for(reg int i=1;i<p;++i)h[i+n-p+1]=s[i];
upd();
for(reg int i=p;i<=n;++i)h[i-p+1]=s[i];
for(reg int i=1;i<p;++i)h[i+n-p+1]=s[p-i];
upd(),std::reverse(s+1,s+1+n),p=0,z[n]=n;
for(reg int i=n-1,l=n,r;i;--i)
{
if(i>=l)z[i]=min(z[n-(r-i)],i-l+1);
while(s[n-z[i]]==s[i-z[i]])++z[i];
if(i-z[i]<l)r=i,l=i-z[i]+1;
}
for(reg int i=1,x,f0=0,f1=0;i<=n;++i)
{
if(!f0&&s[i]!=s[n-i+p+1])f0=1,f1=s[i]<s[n-i+p+1];
x=n-i+p;
if(f1||!f0&&s[n-z[x]]<s[x-z[x]])p=i,f0=f1=0;
}
for(reg int i=1;i<=p;++i)h[i]=s[i];
for(reg int i=p+1;i<=n;++i)h[i]=s[n-i+p+1];
upd(),print(t,n);
}