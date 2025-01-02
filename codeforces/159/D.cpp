#include<cstring>
#include<cstdio>
char s[2048];int p[2048],q[2048],l,a,b,i;long long r;main(){l=strlen(gets(s+1));for(i=1;i<=l;++i){for(a=i,b=i+1;a&&b<=l&&s[a]==s[b];--a,++b)++p[b],++q[a];for(a=b=i;a&&b<=l&&s[a]==s[b];--a,++b)++p[b],++q[a];}for(i=l;i;--i)q[i]+=q[i+1];for(i=1;i<l;++i)r+=(long long)p[i]*q[i+1];printf("%I64d",r);}