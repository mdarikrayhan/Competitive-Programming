// LUOGU_RID: 159992244
#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pi pair<int,int>
using namespace std;
const int N=55,M=1e5+10;
int n,m,st1,st2;
char a[N][N],b[N][N];
pi ans1[M],ans2[M];
void cha(char A[N][N],int x,int y)
{
    if(A[x][y]=='L') A[x][y]=A[x][y+1]='U',A[x+1][y]=A[x+1][y+1]='D';
    else A[x][y]=A[x+1][y]='L',A[x][y+1]=A[x+1][y+1]='R';
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++) scanf("%s",b[i]+1);
    int sum=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum+=(b[i][j]=='L'&&b[i][j+1]=='R'),
            sum+=(b[i][j]=='U'&&b[i+1][j]=='D');
    if(sum*2!=n*m) return puts("-1"),0;
    for(int k=1;k<=n*m;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]=='L'&&a[i][j+1]=='R')
                    if(a[i+1][j]=='U'&&a[i+1][j+1]=='U')
                        ans1[++st1]=mk(i+1,j),cha(a,i+1,j),ans1[++st1]=mk(i,j),cha(a,i,j);
                    else if(a[i+1][j]=='L'&&a[i][j+2]=='U')
                        ans1[++st1]=mk(i,j),cha(a,i,j),ans1[++st1]=mk(i,j+1),cha(a,i,j+1);
    for(int k=1;k<=n*m;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(b[i][j]=='L'&&b[i][j+1]=='R')
                    if(b[i+1][j]=='U'&&b[i+1][j+1]=='U')
                        ans2[++st2]=mk(i+1,j),cha(b,i+1,j),ans2[++st2]=mk(i,j),cha(b,i,j);
                    else if(b[i+1][j]=='L'&&b[i][j+2]=='U')
                        ans2[++st2]=mk(i,j),cha(b,i,j),ans2[++st2]=mk(i,j+1),cha(b,i,j+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='L'&&b[i][j]=='U')
                ans1[++st1]=mk(i,j),cha(a,i,j);
            if(a[i][j]=='U'&&b[i][j]=='L')
                ans1[++st1]=mk(i,j),cha(a,i,j);
        }
    for(int i=st2;i;i--) ans1[++st1]=ans2[i];
    printf("%d\n",st1);
    for(int i=1;i<=st1;i++)
        printf("%d %d\n",ans1[i].fi,ans1[i].se);
    return 0;
}