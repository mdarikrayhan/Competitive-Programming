#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,u,v;
int c[200005];
vector<int>p[200005];
int d[105][105][2];
int main(){
    memset(d,0x3f,sizeof d);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){cin>>c[i];d[i][i][0]=0;}
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        if(c[u]==c[v])d[u][v][0]=d[v][u][0]=1;
        else d[u][v][1]=d[v][u][1]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int t=0;t<=1;t++)
                    for(int o=0;o<=1;o++)
                        d[i][j][t]=min(d[i][j][t],d[i][k][o]+d[k][j][t^o]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans=max(ans,min({(d[i][j][0]+d[i][j][1]+k)/2,d[i][j][0]+k,d[i][j][1]+k}));
    cout<<ans<<endl;
}