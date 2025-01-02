// LUOGU_RID: 160155500
#include<iostream>
#include<cstring>
using namespace std;
const int N=150010,M=310;
long long f[2][N];
long long a[M],b[M],t[M];
int n,m,d;
long long q[N];
int main(){
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1; i<=m; i++){
        scanf("%d%d%d",&a[i],&b[i],&t[i]);
    }
    int hh=0,tt=-1;
    memset(f,-0x3f,sizeof f);
    for(int i=1; i<=n; i++)f[0][i]=0;
    for(int i=1; i<=m; i++){
        int now=i&1,last=(i-1)&1;
         hh=0,tt=-1;
        for(int j=1; j<=n; j++){
           while(hh<=tt && f[last][q[tt]]<=f[last][j])tt--;
           q[++tt]=j;
           if(hh<=tt && q[hh]<j-((t[i]-t[i-1])*d))hh++;
           f[now][j]=f[last][q[hh]]+b[i]-abs(a[i]-j);
        }
        hh=0,tt=-1;
         for(int j=n; j>=1; j--){
           while(hh<=tt && f[last][q[tt]]<=f[last][j])tt--;
           q[++tt]=j;
           if(hh<=tt && q[hh]>j+((t[i]-t[i-1])*d))hh++;
           f[now][j]=max(f[last][q[hh]]+b[i]-abs(a[i]-j),f[now][j]);
        }
    }
    long long ans=-1e18;
    for(int i=1; i<=n; i++)ans=max(ans,f[m&1][i]);
    printf("%lld",ans);
}