// LUOGU_RID: 159725362
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define pb push_back
#define ull unsigned long long
void in(int &x){
    int f=1;x=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-')c=getchar();
    if(c=='-')f=-1,c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    x*=f;
}
mt19937_64 Rnd(time(0));
int t,n,m,k,x,y;
double p[100005];
char s[100005],ss[5];
signed main(){
    in(n);in(m);
    for(int i=1;i<=n;i++)p[i]=1;
    for(int i=1;i<=m;i++){
        scanf("%s",s+1);
        double s0=0,s1=0;
        for(int j=1;j<=n;j++)if(s[j]=='1')s1+=p[j];else s0+=p[j];
        uniform_real_distribution<double>rnd(-s0,s1);
        if(rnd(Rnd)>=0)puts("1");
        else puts("0");
        fflush(stdout);
        scanf("%s",ss+1);
        for(int j=1;j<=n;j++)if(ss[1]!=s[j])p[j]*=0.8;
    }
}