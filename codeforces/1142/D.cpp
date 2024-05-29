// LUOGU_RID: 159971020
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 100005
#define int ll
using namespace std;
int re()
{
    int x=0;
    #ifndef ONLINE_JUDGE
    scanf("%lld",&x);
    return x;
    #endif
    bool t=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
        t=ch=='-'?0:t,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?x:-x;
}
int n,ans;
char a[maxn];
int f[maxn][11];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    scanf("%s",a+1);
    n=strlen(a+1);
    for(int i=1;i<=n;i++)
    {
        int x=a[i]-'0';
        if(x)
            f[i][x]=1;
        for(int j=x+1;j<=10;j++)
            f[i][(x+10+j*(j-1)/2)%11]+=f[i-1][j];
        for(int j=0;j<=10;j++)
            ans+=f[i][j];
    }
    printf("%lld",ans);
    return 0;
}