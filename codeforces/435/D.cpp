#include<bits/stdc++.h>
using namespace std;
const int MAXN=450;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
int dp[8][MAXN][MAXN],tb[MAXN][MAXN];
int N,M,Ans;
void rotate(int &p) {
    p++;
    p%=8;
} 
void Sol(int x,int y) {
    int mxd=min(min(x-1,N-x),min(y-1,M-y));
    // for(int op=0;op<8;++op) {
    //     printf("%d ",dp[op][x][y]);
    // }printf("\n");
    // printf("(%d,%d)\n",x,y);
    for(int p1=0,p2=2,p3=3,p4=7,cnt=0;cnt<8;cnt++,rotate(p1),rotate(p2),rotate(p3),rotate(p4)) {
        int px=x,py=y,qx=x,qy=y;
        for(int d=1,ok=1;1;++d) {
            px+=dx[p1],py+=dy[p1],ok&=tb[px][py];
            qx+=dx[p2],qy+=dy[p2],ok&=tb[qx][qy];
            
            if(!ok) break;
            // if(x==1&&y==2&&p1==4) {
            //     printf("{%d,%d}{%d,%d}{%d,%d}\n",x,y,px,py,qx,qy);
            // }
            // printf("{%d,%d,%d}%d\n",p1,x,y,d);
            if(dp[p3][px][py]>d&&dp[p4][qx][qy]>d){
                 Ans++;
                //  printf("%d:(%d,%d,%d,%d){%d,%d}{%d,%d}{%d,%d}\n",d,p1,p2,p3,p4,x,y,px,py,qx,qy);
            }
        }
    }
    return ;
}

char str[MAXN];
void DP(int op) {
    int tx=(dx[op]>=0),ty=(dy[op]>=0);
    for(int x=(tx?N:1);(tx?(x>=1):(x<=N));(tx?(x--):(x++)))
        for(int y=(ty?M:1);(ty?(y>=1):(y<=M));(ty?(y--):(y++))) if(tb[x][y])
            dp[op][x][y]=dp[op][x+dx[op]][y+dy[op]]+1;
}
void Solve() {
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i) {
        scanf("%s",str);
        for(int j=1;j<=M;++j) tb[i][j]=(str[j-1]-'0')^1;
    }
    for(int op=0;op<8;++op) DP(op);
    // for(int op=0;op<4;++op)//wrong!!
    //     for(int i=1;i<=N;++i)
    //         for(int j=M;j;--j) if(tb[i][j]) 
    //             dp[op][i][j]=dp[op][i+dx[op]][j+dy[op]]+1;
    // for(int op=4;op<8;++op)
    //     for(int i=N;i;--i)
    //         for(int j=1;j<=M;++j) if(tb[i][j])
    //             dp[op][i][j]=dp[op][i+dx[op]][j+dy[op]]+1;
    
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j) if(tb[i][j])
            Sol(i,j);
    printf("%d",Ans);
    return ;
}

int main() {
    // freopen("435d.in","r",stdin);
    // freopen("435d.out","w",stdout);
    Solve();
    return 0;
}