// LUOGU_RID: 158372248
#include<bits/stdc++.h>
using namespace std;
#define N 2050500
const int up=2e6+5;
#define db double
#define int __int128
int n,m,cnts,res;
int low[N],hig[N],x[N],y[N];
int read(){
    int x=0,w=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();return x*w;
}
db eps=1e-8;
void add(int x1,int y1,int x2,int y2){
    if(x1>x2)swap(x1,x2),swap(y1,y2);
    if(x1==x2){
        if(y1>y2)swap(y1,y2);
        low[x1]=min(low[x1],y1);
        hig[x1]=max(hig[x1],y2);return ;
    }
    db k=1.0*(y2-y1)/(x2-x1),b=y1-x1*k;
    for(int i=x1;i<=x2;i++){
        low[i]=min(low[i],(int)ceil(k*i+b-eps));
        hig[i]=max(hig[i],(int)floor(k*i+b+eps));
    }
}
void sol(){
    for(int i=0;i<=up;i++)low[i]=up,hig[i]=0;
    for(int i=1;i<=n;i++)add(x[i],y[i],x[i+1],y[i+1]);
    int all=0;cnts=0;
    for(int i=0;i<=up;i++)if(low[i]<up){
        int cnt=hig[i]-low[i]+1;
        cnts+=cnt;all+=i*cnt;
    }
    for(int i=0;i<=up;i++)if(low[i]<up){
        int cnt=hig[i]-low[i]+1;
        res+=cnt*i*i*cnts;res-=cnt*i*all;
    }
}
signed main(){
    n=read();
    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read(),x[i]+=1e6,y[i]+=1e6;x[n+1]=x[1],y[n+1]=y[1];
    sol();
    for(int i=1;i<=n+1;i++)swap(x[i],y[i]);
    // cout<<"chg\n";
    sol();
    cout<<fixed<<setprecision(15)<<1.0*res/cnts/(cnts-1)<<"\n";
}//codeforces