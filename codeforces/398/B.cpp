// LUOGU_RID: 160509995
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=2e3+10;
bool visx[maxn],visy[maxn];
double dp[maxn][maxn];
int main(){
    scanf("%d%d",&n,&m);
    int row=n,col=n;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(!visx[x]){
            visx[x]=1;
            row--;
        }
        if(!visy[y]){
            visy[y]=1;
            col--;
        }
    }
    for(int i=1;i<=row;i++){
        dp[i][0]=dp[i-1][0]+(double)n/i;
    }
    for(int i=1;i<=col;i++){
        dp[0][i]=dp[0][i-1]+(double)n/i;
    }
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            dp[i][j]=(dp[i-1][j-1]*i*j+dp[i-1][j]*i*(n-j)+dp[i][j-1]*j*(n-i)+n*n)/(n*n-(n-i)*(n-j));
        }
    }
    printf("%.4lf",dp[row][col]);
    return 0;
}