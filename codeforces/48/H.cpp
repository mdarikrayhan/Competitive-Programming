#include<cstdio>
#include<algorithm>
using namespace std;
const char w[6][5]={"####","....","\\#.\\",".//#","\\.#\\","#//."};
int a,b,c,n,m,x,y,p[110][110];
void ne(){y++;if(y==m)x++,y=0;}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    for(int i=0;i<a;i++,ne())p[x][y]=0;
    for(int i=0,y0=y;i<m;i++,ne())p[x][y]=((y>=y0)^abs(y0-y)&1)?5:2;
    for(int i=0;i<b;i++,ne())p[x][y]=1;
    for(int x0=x,y0=y,i=0;i<c-m;i++,ne())p[x][y]=(((x-x0)&1)?(abs(y-y0)&1)?3:4:(abs(y-y0)&1)?5:2)^(y>=y0);
    for(int i=0;i<n*2;i++)
    {
        for(int j=0;j<m*2;j++)
            putchar(w[p[i/2][j/2]][(i&1)*2+(j&1)]);
        puts("");
    }
}