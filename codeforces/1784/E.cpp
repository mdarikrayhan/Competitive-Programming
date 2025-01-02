#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 205
#define mod 998244353
#define B 300
using namespace std;
int re()
{
    int x=0;
    bool t=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
        t=ch=='-'?0:t,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?x:-x;
}
int n,ans1,ans2,ans3;
char s[maxn];
int a[maxn],f[maxn][maxn*3][2][3][3][3],nex[3],b[10];
void upd(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    if(x<0)x+=mod;
}
int get(int fr1,int t,int &to,bool ch)
{
    if(fr1>>t&1)
    {
        if(ch)
            to+=!t?1:-1;
        return 0;
    }
    return fr1+4|1<<t;
}
void solve()
{
    a[0]=a[n];
    for(int ch=1;ch<8;ch++)
    {
        mclear(f);
        f[0][B][a[n]][a[n-1]==a[n]?0:2][1][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int t=0;t<=1;t++)
            {
                if(!t==a[i])continue;
                for(int la=0;la<=1;la++)
                {
                    if(!la==a[i-1])continue;
                    for(int j=1;j<B<<1;j++)
                    {
                        for(int fr1=0;fr1<3;fr1++)
                        {
                            for(int fr2=0;fr2<3;fr2++)
                            {
                                for(int fr3=0;fr3<3;fr3++)
                                {
                                    if(!f[i-1][j][la][fr1][fr2][fr3])continue;
                                    int to1=fr1+1,to2=fr2+1,to3=fr3+1,to=j;
                                    if(to1==3||to1==2&&t==la)
                                        to1=0,to+=(ch&1)?!t?1:-1:0;
                                    if(to2==3||to2==2&&t==la)
                                        to2=0,to+=(ch&2)?!t?1:-1:0;
                                    if(to3==3||to3==2&&t==la)
                                        to3=0,to+=(ch&4)?!t?1:-1:0;
                                    upd(f[i][to][t][to1][to2][to3],f[i-1][j][la][fr1][fr2][fr3]);
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i0=0;i0<3;i0++)
        {
            for(int i1=0;i1<3;i1++)
            {
                for(int i2=0;i2<3;i2++)
                {
                    nex[0]=2-i0,nex[1]=2-i1,nex[2]=2-i2;
                    int vis=0,now=2,cnt=0;
                    while(1)
                    {
                        b[++cnt]=now;
                        if(vis>>now&1)break;
                        vis|=1<<now;
                        now=nex[now];
                    }
                    vis=1<<now;
                    for(int i=cnt-1;b[i]!=b[cnt];i--)
                        vis|=1<<b[i];
                    if(vis==ch)
                    {
                        for(int i=1;i<B;i++)
                            upd(ans3,f[n][i][a[n]][i0][i1][i2]);
                        upd(ans2,f[n][B][a[n]][i0][i1][i2]);
                        for(int i=B+1;i<B<<1;i++)
                            upd(ans1,f[n][i][a[n]][i0][i1][i2]);
                    }
                }
            }
        }
    }
}
signed main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    if(n==1)
    {
        if(s[1]=='a')
            puts("1\n0\n0");
        if(s[1]=='b')
            puts("0\n0\n1");
        if(s[1]=='?')
            puts("1\n0\n1");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?')
            a[i]=2;
        else
            a[i]=s[i]-'a';
    }
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=1;j++)
        {
            if((s[n-1]=='?'||s[n-1]==i+'a')&&(s[n]=='?'||s[n]==j+'a'))
            {
                a[n-1]=i,a[n]=j;
                solve();
            }
        }
    }
    printf("%d\n%d\n%d",ans1,ans2,ans3);
    return 0;
}
		  				  			 			    			   	 	