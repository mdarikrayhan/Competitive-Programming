#include<bits/stdc++.h>
using namespace std;
char s[512],t[32];
int q,a,b,c,f;
int main() {
for(scanf("%d",&q); q--; printf("%s\n",f?"-1":s),f=0)
for(scanf("%s%s",s,t),a=strlen(s),b=strlen(t),s[c=a*b/__gcd(a,b)]=0;
c--;
f|=(s[c]=s[c%a])!=t[c%b]);
return 0;
}