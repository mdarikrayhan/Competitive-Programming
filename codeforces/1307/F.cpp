// LUOGU_RID: 158462433
#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;int f=1;char c=getchar();
        while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
        while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
        x*=f;
    }
    const int BUF=1<<21;
    char buf[BUF],ctop,cstk[32];int plen;
    #define flush() fwrite(buf,1,plen,stdout),plen=0
    inline void pc(char c){
        buf[plen++]=c;
        if(plen==BUF) flush();
    }
    template<typename T>inline void print(T x){
        if(!x){pc(48);return;}
        if(x<0) x=~x+1,pc('-');
        while(x) cstk[++ctop]=48+x%10,x/=10;
        while(ctop) pc(cstk[ctop--]);
    }
}
using namespace IO;
const int N=4e5+5;
int head[N],to[N<<1],nxt[N<<1],tot;
inline void add(int x,int y){
    to[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
int n,m,q,u[N],v[N],d[N],s[N],t[N],k[N],dis[N];
namespace BL{
    inline bool query(int x,int y,int k){
        priority_queue<pair<int,int>> hp;
        for(int i=1;i<=n;++i) dis[i]=-N;
        dis[x]=max(k,d[x]);hp.push({dis[x],x});
        while(!hp.empty()){
            int u=hp.top().second;hp.pop();
            if(u==y) return 1;
            if(!dis[u]) continue;
            for(int o=head[u];o;o=nxt[o])
                if(dis[to[o]]<max(d[to[o]],dis[u]-1)) hp.push({dis[to[o]]=max(d[to[o]],dis[u]-1),to[o]});
        }
        return 0;
    }
    inline void sol(){
        for(int i=1;i<n;++i) add(u[i],v[i]),add(v[i],u[i]);
        for(int i=1;i<=q;++i){
            if(query(s[i],t[i],k[i])) pc('Y'),pc('E'),pc('S'),pc('\n');
            else pc('N'),pc('O'),pc('\n');
        }
        flush();
    }
}
namespace SUBD{
    int f[N][21],lg[N],dep[N],fa[N],nn;
    void dfs(int p){
        dep[p]=dep[f[p][0]]+1;
        for(int i=1;i<=lg[dep[p]];++i) f[p][i]=f[f[p][i-1]][i-1];
        for(int o=head[p],v;o;o=nxt[o]){
            v=to[o];
            if(v!=f[p][0]){
                f[v][0]=p;
                dfs(v);
            }
        }
    }
    inline int Lca(int x,int y){
        if(dep[x]<dep[y]) swap(x,y);
        for(int c=dep[x]-dep[y],i=0;c;++i,c>>=1)
            if(c&1) x=f[x][i];
        if(x==y) return x;
        for(int i=lg[dep[x]];~i;--i)
            if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
        return f[x][0];
    }
    inline int jump(int x,int k){
        for(;k;k^=k&-k){
            int b=k&-k;
            x=f[x][lg[b]];
        }
        return x;
    }
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    inline void sol(int K){
        K<<=1;
        queue<int> Q;
        nn=n;
        for(int i=1;i<n;++i){
            ++nn;
            add(u[i],nn);add(nn,u[i]);
            add(v[i],nn);add(nn,v[i]);
        }
        for(int i=1;i<=nn;++i)if(d[i]>0) Q.push(i),fa[i]=i;
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            if(dis[u]==K/2) continue;
            for(int o=head[u],v;o;o=nxt[o]){
                v=to[o];
                if(fa[v]){
                    if(find(v)^find(u)) fa[fa[v]]=fa[u];
                }else{
                    fa[v]=u;
                    Q.push(v);
                    dis[v]=dis[u]+1;
                }
            }
        }
        for(int i=1;i<=nn;++i)if(!fa[i]) fa[i]=i;
        for(int i=2;i<=nn;++i) lg[i]=lg[i>>1]+1;
        dfs(1);
        for(int i=1;i<=q;++i){
            read(s[i]),read(t[i]);
            int lc=Lca(s[i],t[i]),dis=dep[s[i]]+dep[t[i]]-dep[lc]*2;
            bool ans;
            if(dis<=K) ans=1;
            else{
                int u=(dep[s[i]]-dep[lc]>=K/2?jump(s[i],K/2):jump(t[i],dis-K/2));
                int v=(dep[t[i]]-dep[lc]>=K/2?jump(t[i],K/2):jump(s[i],dis-K/2));
                ans=(find(u)==find(v));
            }
            if(ans) pc('Y'),pc('E'),pc('S'),pc('\n');
            else pc('N'),pc('O'),pc('\n');
        }
        flush();
    }
}
int main(){
    int K;
    read(n),read(K),read(m);
    for(int i=1;i<n;++i){
        read(u[i]),read(v[i]);
    }
    memset(d,-1,sizeof(d));
    while(m--){int a;
        read(a);
        d[a]=1;
    }
    read(q);
    SUBD::sol(K);
    return 0;
}