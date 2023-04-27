#include<bits/stdc++.h>
using namespace std;
char s[300008];
int t,n,i,a,b;
int main() {
    for(scanf("%d",&t); t--; printf("%d\n",n),i=a=b=0) {
        for(scanf("%d%s",&n,s); s[i]; a+=s[i]=='<',b+=s[i++]=='>');
        if(a&&b)
            for(s[i=n]=s[0]; i--; s[i]=='-'||s[i+1]=='-'?0:--n);
    }
    exit(0);
}