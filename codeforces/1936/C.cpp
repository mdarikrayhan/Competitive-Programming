#include <bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
#define DF(i,x,y) for(int i=(x);i>=(y);i--)
#define ms(x,y) memset(x,y,sizeof(x))
#define SZ(x) (int)x.size()-1
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T> void chkmax(T &x,T y){ x=max(x,y);}
template<typename T> void chkmin(T &x,T y){ x=min(x,y);}
template<typename T> void read(T &FF){
    FF=0;int RR=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') RR=-1;
    for(;isdigit(ch);ch=getchar()) FF=(FF<<1)+(FF<<3)+ch-48;
    FF*=RR;
}
const int N=400010,inf=2e9+5;
int n,m,a[N],c[N],f[N<<1],id[N];
bool vis[N<<1];
vector<pii> G[N<<1];
priority_queue<pii,vector<pii>,greater<pii> > pq;
int ind(int x,int y){ return (x-1)*m+y;}
void work(){
    read(n),read(m);
    F(i,1,n) read(c[i]);
    F(i,1,n) F(j,1,m) read(a[ind(i,j)]);
    F(i,1,n*m+n) G[i].clear();
    F(j,1,m){
        F(i,1,n) id[i]=i;
        sort(id+1,id+n+1,[&](int x,int y){ return a[ind(x,j)]<a[ind(y,j)];});
        F(i,1,n-1){
            int x=id[i],y=id[i+1];
            G[ind(x,j)].pb({ind(y,j),0});
            G[ind(y,j)].pb({ind(x,j),a[ind(y,j)]-a[ind(x,j)]});
        }
    }
    F(i,1,n) F(j,1,m) G[ind(i,j)].pb({n*m+i,c[i]}),G[n*m+i].pb({ind(i,j),0});
    F(i,1,n*m+n) f[i]=inf,vis[i]=0;
    f[n*m+1]=0,pq.push({0,n*m+1});
    while(!pq.empty()){
        auto [dis,u]=pq.top();pq.pop();
        if(vis[u]) continue;vis[u]=1;
        for(auto [v,w]:G[u]) if(f[u]+w<f[v]) f[v]=f[u]+w,pq.push({f[v],v});
    }
    printf("%d\n",f[n*m+n]);
}
int main(){
    int T;read(T);
    while(T--) work();
    return 0;
}
