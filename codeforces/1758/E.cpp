// LUOGU_RID: 160092164
#include <bits/stdc++.h>
using namespace std;
namespace Le0{
const int N=2e5+5,M=2e5+5,mod=1e9+7;
int T,n,m,h;
int fa[N],dis[N],siz[N];
int find(int x){
    if(x==fa[x]) return x;
    int f=fa[x];
    fa[x]=find(fa[x]);
    dis[x]=(dis[f]+dis[x])%h;
    return fa[x];
}
int qp(int a,int b){
    int as=1;
    while(b){
        if(b&1) as=1ll*as*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }return as;
}
int cal(int x){
    return (x+h)%h;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>h;
        vector<vector<int>> w(n+1,vector<int> (m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>w[i][j];
            }
        }
        for(int i=1;i<=m;i++) fa[i]=i,dis[i]=0;
        int tot=m,ans=1;bool fk=1;
        for(int i=1;i<=n;i++){
            bool ok=1;
            int k=0;
            for(int j=1;j<=m;j++){
                if(w[i][j]==-1) continue;
                ok=0;
                if(k){
                    int fx=find(k),fy=find(j);
                    if(fx==fy){
                        if(cal(dis[k]-dis[j])!=cal(w[i][j]-w[i][k])){
                            fk=0;
                            break;
                        }
                    }
                    else{
                        fa[fy]=fx;
                        int di=cal(w[i][k]-w[i][j]);
                        dis[fy]=cal(((dis[k]+di)%h-dis[j]));
                        tot--;
                    }
                }
                k=j;
            }
            if(!fk){break;}
            if(ok) ans=1ll*ans*h%mod;
        }
        if(!fk){cout<<"0\n";continue;}
        cout<<1ll*ans*qp(h,tot-1)%mod<<"\n";
    }
    return 0;
}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    return Le0::main();
}