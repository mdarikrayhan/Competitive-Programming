#include<bits/stdc++.h>
using namespace std;
int T,l,n;
char s[11];
int main()
{
cin>>T;
while(T--)
{
while(getchar()!='\'');
cin>>s,l=strlen(s);
int _=0,_1=1,n=atoi(s);
for(int i=1;i<l;i++)_+=(_1*=10);
_1*=10;
while(n<1989+_)n+=_1;
printf("%d\n",n);
}
return 0;
}