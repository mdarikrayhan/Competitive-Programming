#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=410,mod=998244353;
inline int Add(const int &a,const int &b){
	return a+b>=mod?a+b-mod:a+b;
}
inline int Del(const int &a,const int &b){
	return a-b<0?a-b+mod:a-b;
}
inline int Mul(const int &a,const int &b){
	return 1ll*a*b%mod;
}
int qmi(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=Mul(ans,a);
		a=Mul(a,a);
		b/=2;
	}
	return ans;
}
int n,ans;
int cnt[27];
int f[2][N][N][3][3];
int g[2][N][2][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=26;i++)
        scanf("%d",&cnt[i]);
    ans=Mul(26,Mul(26,qmi(25,n-2)));
    int op=1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(i<2&&j<2)g[op][(i==1)+(j==1)][i][j]=Mul((i==0?25:1),(j==0?25:1));
            f[op][(i==1)+(j==1)][(i==2)+(j==2)][i][j]=Mul((i==0?24:1),(j==0?24:1));
        }
    for(int i=3;i<=n;i++){
        op^=1;
        memset(f[op],0,sizeof f[op]);
        memset(g[op],0,sizeof g[op]);
        for(int j=0;j<=n;j++){
            for(int a=0;a<2;a++)
                for(int b=0;b<2;b++)
                {
                    if(a==0){
                        g[op][j+1][b][1]=Add(g[op][j+1][b][1],g[op^1][j][a][b]);
                        g[op][j][b][0]=Add(g[op][j][b][0],Mul(g[op^1][j][a][b],24));
                    }
                    else g[op][j][b][0]=Add(g[op][j][b][0],Mul(g[op^1][j][a][b],25));
                }
        }
        for(int j=0;j<=n;j++){
            for(int k=0;j+k<=n;k++)
                for(int a=0;a<3;a++)
                    for(int b=0;b<3;b++)
                    {
                        if(a==0){
                            f[op][j][k][b][0]=Add(f[op][j][k][b][0],Mul(f[op^1][j][k][a][b],23));
                            f[op][j+1][k][b][1]=Add(f[op][j+1][k][b][1],f[op^1][j][k][a][b]);
                            f[op][j][k+1][b][2]=Add(f[op][j][k+1][b][2],f[op^1][j][k][a][b]);
                        }
                        else if(a==1)
                        {
                            f[op][j][k][b][0]=Add(f[op][j][k][b][0],Mul(f[op^1][j][k][a][b],24));
                            f[op][j][k+1][b][2]=Add(f[op][j][k+1][b][2],f[op^1][j][k][a][b]);
                        }
                        else
                        {
                            f[op][j][k][b][0]=Add(f[op][j][k][b][0],Mul(f[op^1][j][k][a][b],24));
                            f[op][j+1][k][b][1]=Add(f[op][j+1][k][b][1],f[op^1][j][k][a][b]);
                        }
                    }
        }
    }
    for(int i=1;i<=26;i++)
    {
        for(int k=cnt[i]+1;k<=n;k++)
            for(int a=0;a<2;a++)
            for(int b=0;b<2;b++)
            ans=Del(ans,g[op][k][a][b]);
        for(int j=i+1;j<=26;j++)
        {
            for(int k=cnt[i]+1;k<=n;k++)
            for(int k2=cnt[j]+1;k2+k<=n;k2++)
                for(int a=0;a<3;a++)
                for(int b=0;b<3;b++)
                ans=Add(ans,f[op][k][k2][a][b]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
							    					   		 		   	  	