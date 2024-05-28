#include <bits/stdc++.h>
 
using namespace std;
inline void read(int &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}
 
inline void read(long long &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}
 
 
inline void write(int x){
    static const int maxlen=100;
    static char s[maxlen];
        if (x<0) {   putchar('-'); x=-x;}
    if(!x){ putchar('0'); return; }
    int len=0; for(;x;x/=10) s[len++]=x % 10+'0';
    for(int i=len-1;i>=0;--i) putchar(s[i]);
}
 
const int MAXN = 410000;
int a[ MAXN ];
int n;
 
int main(){
    read(n);
    int sum=0;
    int ans=0;
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        read(a[i]);
        sum+=a[i]/1000;
        if ( a[i]==1000)
            tot++;
    }
    int tmp = 10*sum/11;
    if ( sum <= 11 )
        tmp = sum - a[n] /1000;
    if ( ( !tot ) && ( tmp % 2 ==1 ) )
        tmp--;
    printf("%d\n",sum*1000-tmp*100);
    return 0;
}