// LUOGU_RID: 160225805
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

inline int read(){
    int ret=0;
    char c=getchar();
    while(!('0'<=c&&c<='9')) c=getchar();
    while('0'<=c&&c<='9') ret=(ret*10)+(c^48),c=getchar();
    return ret;
}

// #define DEBUG

int Q,n,m;
int S,T;
const int N=3e5+20,M=5e6+10;
//  theoretically, there's 5328 edges in previous graph.
/*
    x_in <- x<<2;
    x'_in <- x<<2|2
    x_out <- x<<2|1
    x'_out <- x<<2|3
*/

#ifdef DEBUG
inline void show(int x){
    if(x==S){
        printf("S");
        return ;
    }
    if(x==T){
        printf("T");
        return ;
    }
    printf("%d",x>>2);
    if(x&2) printf("'");
    if(x&1) printf("_out");
    else printf("_in");
}
#endif

int to[M],nt[M],c[M],idx,h[N];
inline void add(int x,int y){
    #ifdef DEBUG
    printf("add("),show(x),printf(","),show(y),printf(")\n");
    // printf("%d %d\n",x,y);
    #endif
    to[idx]=y,nt[idx]=h[x],c[idx]=1,h[x]=idx++;
    to[idx]=x,nt[idx]=h[y],c[idx]=0,h[y]=idx++;
}
inline void add_edge(int x,int y){
    add(x<<2,y<<2|1);
    add(x<<2,y<<2|3);
    add(x<<2|2,y<<2|3);
}

int cur[N],lv[N];
int q[N],tt=-1,hh=0;
bool bfs(){
    #ifdef DEBUG
    printf("bfs()");
    #endif
    tt=-1,hh=0;
    for(int i=S;i<=T;i++) lv[i]=-1;
    cur[S]=h[S];
    lv[S]=0;
    q[++tt]=S;
    while(hh<=tt){
        int u=q[hh++];
        for(int i=h[u];i!=-1;i=nt[i]){
            int j=to[i];
            if(lv[j]!=-1||c[i]==0) continue;
            cur[j]=h[j];
            lv[j]=lv[u]+1;
            q[++tt]=j;
            if(j==T) return true;
        }
    }
    #ifdef DEBUG
    printf("==false\n");
    #endif
    return false;
}

int find(int u,int limit){
    if(u==T) return limit;
    int flow=0;
    for(int i=cur[u];i!=-1&&flow<limit;i=nt[i]){
        cur[u]=i;
        int j=to[i];
        if(lv[j]!=lv[u]+1||c[i]==0) continue;
        int k=find(j,min(c[i],limit-flow));
        if(k==0) lv[j]=-1;
        #ifdef DEBUG
        printf("c("),show(u),printf(","),show(j),printf(")=%d\n",k);
        #endif
        flow+=k;
        c[i]-=k;
        c[i^1]+=k;
    }
    return flow;
}

int dinic(){
    int ans=0,flow=0;
    while(bfs()){
        while(flow=find(S,0x3f3f3f3f)) ans+=flow;
    }
    return ans;
}

int a[N],pos[N];
int main(){
    Q=read();
    while(Q--){
        n=read();
        S=0,T=(n<<2|3)+1;
        for(int i=S;i<=T;i++) h[i]=-1;
        idx=0;
        for(int i=1;i<=n;i++){
            a[i]=read();
            pos[a[i]]=i;
            add(i<<2,i<<2|3);
            // add(i<<2,i<<2|1);
            // add(i<<2|2,i<<2|3);
        }
        for(int i=1;i<=50000;i++){
            if(!pos[i]) continue;
            for(int j=i+i;j<=50000;j+=i){
                if(!pos[j]) continue;
                add_edge(pos[j],pos[i]);
            }
        }
        for(int i=4;i<T;i++){
            if(i&1) add(i,T);
            else add(S,i);
        }
        int ans=n-(2*n-dinic());
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) pos[a[i]]=0;
    }
    return 0;
}